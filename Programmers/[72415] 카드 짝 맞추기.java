import java.util.*;
import java.util.stream.Collectors;

class Solution {
    static final int INF = 987654321;
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};
    static List<Integer> answer;

    static int calculatePath(int fromY, int fromX, int toY, int toX, List<Card> cards) {
        // 8가지 방향
        int[][] visited = new int[4][4];
        for (int[] v : visited) {
            Arrays.fill(v, INF);
        }
        Queue<Position> queue = new LinkedList<>();

        queue.offer(new Position(fromY, fromX));
        visited[fromY][fromX] = 0;

        while (!queue.isEmpty()) {
            Position cur = queue.poll();
            if (cur.y == toY && cur.x == toX) {
                return visited[toY][toX];
            }

            // just one
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
                    if (visited[ny][nx] == INF) {
                        visited[ny][nx] = visited[cur.y][cur.x] + 1;
                        queue.offer(new Position(ny, nx));
                    }
                }
            }

            // + ctrl
            for (int i = 0; i < 4; i++) {
                int length = 0;
                boolean isPossible = true;
                while (isPossible) {
                    int ny = cur.y + (length + 1) * dy[i];
                    int nx = cur.x + (length + 1) * dx[i];

                    if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
                        break;
                    }
                    for (Card card : cards) {
                        if (card.y == ny && card.x == nx) {
                            isPossible = false;
                            break;
                        }
                    }

                    length++;
                }

                int ny = cur.y + length * dy[i];
                int nx = cur.x + length * dx[i];
                if (visited[ny][nx] == INF) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    queue.offer(new Position(ny, nx));
                }
            }
        }

        return visited[toY][toX];
    }

    static void dfs(int y, int x, int cnt, List<Card> cards) {
        if (cards.isEmpty()) {
            answer.add(cnt);
            return;
        }

        for (Card card : cards) {
            Card oppositeCard = card.pair;
            int path1 = calculatePath(y, x, card.y, card.x, cards) + 1;
            int path2 = calculatePath(card.y, card.x, oppositeCard.y, oppositeCard.x, cards) + 1;

            List<Card> removedCards = cards.stream()
                    .filter(c -> !c.equals(card) && !c.equals(oppositeCard))
                    .collect(Collectors.toCollection(ArrayList::new));

            dfs(oppositeCard.y, oppositeCard.x, cnt + path1 + path2, removedCards);
        }
    }

    public int solution(int[][] board, int r, int c) {
        answer = new ArrayList<>();

        List<Card> cards = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int num = board[i][j];
                if (num != 0) {
                    Card newCard = new Card(num, i, j);
                    for (Card card : cards) {
                        if (card.num == num) {
                            card.setPair(newCard);
                            newCard.setPair(card);
                        }
                    }
                    cards.add(newCard);
                }
            }
        }

        dfs(r, c, 0, cards);

        return Collections.min(answer);
    }

    static class Position {
        int y;
        int x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Card {
        int num;
        int y;
        int x;
        Card pair;

        public Card(int num, int y, int x) {
            this.num = num;
            this.y = y;
            this.x = x;
        }

        void setPair(Card pair) {
            this.pair = pair;
        }
    }
}
