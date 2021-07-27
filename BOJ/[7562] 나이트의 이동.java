package boj7562;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int[] dy = {2, 1, -1, -2, -2, -1, 1, 2};
    static final int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
    static int[][] visited;
    static int l;

    static int bfs(int fromY, int fromX, int toY, int toX) {
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(fromY, fromX));
        visited[fromY][fromX] = 0;

        while (!queue.isEmpty()) {
            Position popped = queue.poll();
            int y = popped.y;
            int x = popped.x;

            if (y == toY && x == toX) {
                break;
            }

            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 <= ny && ny < l && 0 <= nx && nx < l) {
                    if (visited[ny][nx] == 0) {
                        queue.offer(new Position(ny, nx));
                        visited[ny][nx] = visited[y][x] + 1;
                    }
                }
            }
        }

        return visited[toY][toX];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        List<Integer> answer = new ArrayList<>();

        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            l = Integer.parseInt(br.readLine());
            visited = new int[l][l];

            st = new StringTokenizer(br.readLine());
            int fromY = Integer.parseInt(st.nextToken());
            int fromX = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            int toY = Integer.parseInt(st.nextToken());
            int toX = Integer.parseInt(st.nextToken());

            answer.add(bfs(fromY, fromX, toY, toX));
        }
        br.close();

        answer.forEach(System.out::println);
    }

    static class Position {
        int y, x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
