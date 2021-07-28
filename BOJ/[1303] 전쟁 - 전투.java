package boj1303;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};
    static int N, M;
    static char[][] map;
    static boolean[][] visited;
    static int whitePower, bluePower;
    static int count;

    static void dfs(int y, int x) {
        char color = map[y][x];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < M && 0 <= nx && nx < N) {
                if (map[ny][nx] == color) {
                    if (!visited[ny][nx]) {
                        count++;
                        visited[ny][nx] = true;
                        dfs(ny, nx);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[M][N];
        visited = new boolean[M][N];

        for (int i = 0; i < M; i++) {
            String row = br.readLine().strip();
            for (int j = 0; j < N; j++) {
                map[i][j] = row.charAt(j);
            }
        }
        br.close();

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    count = 1;

                    visited[i][j] = true;
                    dfs(i, j);

                    if (map[i][j] == 'B') {
                        bluePower += count * count;
                    } else {
                        whitePower += count * count;
                    }
                }
            }
        }

        System.out.println(whitePower + " " + bluePower);
    }
}
