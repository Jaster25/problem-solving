package boj22255;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int INF = 987654321;
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};

    static int N, M;
    static int toY, toX;
    static int[][] impulse;
    static int[][][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int fromY = Integer.parseInt(st.nextToken()) - 1;
        int fromX = Integer.parseInt(st.nextToken()) - 1;
        toY = Integer.parseInt(st.nextToken()) - 1;
        toX = Integer.parseInt(st.nextToken()) - 1;

        impulse = new int[N][M];
        visited = new int[N][M][3];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                impulse[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        br.close();

        int result = dijkstra(fromY, fromX);

        System.out.println(result != INF ? result : -1);
    }

    private static int dijkstra(int fromY, int fromX) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Arrays.fill(visited[i][j], INF);
            }
        }

        visited[fromY][fromX][0] = 0;
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(fromY, fromX, 0));

        while (!queue.isEmpty()) {
            Position popped = queue.poll();
            int y = popped.y;
            int x = popped.x;
            int count = popped.count;

            if (y == toY && x == toX) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                if ((count + 1) % 3 == 1 && i % 2 == 1) {
                    continue;
                } else if ((count + 1) % 3 == 2 && i % 2 == 0) {
                    continue;
                }

                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (impulse[ny][nx] != -1) {
                        if (visited[ny][nx][(count + 1) % 3] > visited[y][x][count % 3] + impulse[ny][nx]) {
                            visited[ny][nx][(count + 1) % 3] = visited[y][x][count % 3] + impulse[ny][nx];
                            queue.offer(new Position(ny, nx, count + 1));
                        }
                    }
                }
            }
        }
        return Arrays.stream(visited[toY][toX]).min().orElse(INF);
    }

    static class Position {
        int y, x, count;

        public Position(int y, int x, int count) {
            this.y = y;
            this.x = x;
            this.count = count;
        }
    }
}