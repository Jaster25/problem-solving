import java.util.*;

class Solution {
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};

    boolean isCompliedPerson(String[] place, Position applicant) {
        Queue<Position> queue = new LinkedList<>();
        int[][] visited = new int[5][5];
        for (int i = 0; i < 5; i++) {
            Arrays.fill(visited[i], -1);
        }

        visited[applicant.y][applicant.x] = 0;
        queue.offer(applicant);

        while (!queue.isEmpty()) {
            Position popped = queue.poll();
            int y = popped.y;
            int x = popped.x;

            if (visited[y][x] > 2) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
                    if (visited[ny][nx] == -1) {
                        char nextPosition = place[ny].charAt(nx);
                         visited[ny][nx] = visited[y][x] + 1;
                        if (nextPosition == 'P') {
                            if (visited[ny][nx] <= 2) {
                                return false;
                            }
                        }
                        if (nextPosition != 'X') {
                            queue.offer(new Position(ny, nx));
                        }
                    }
                }
            }
        }
        return true;
    }

    boolean isCompliedPlace(String[] place) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i].charAt(j) == 'P') {
                    if (!isCompliedPerson(place, new Position(i, j))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public int[] solution(String[][] places) {
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            answer.add(isCompliedPlace(places[i]) ? 1 : 0);
        }

        return answer.stream()
                .mapToInt(x -> x)
                .toArray();
    }

    static class Position {
        int y, x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}