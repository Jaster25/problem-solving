package boj1405;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class Main {

    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};

    static int N;
    static double[] possibility = new double[4];

    static double answer = 0.0;
    static boolean[][] visited = new boolean[50][50];

    static void dfs(int y, int x, int count, double cur) {
        if (count == N) {
            answer += cur;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!visited[ny][nx] && possibility[i] != 0) {
                visited[ny][nx] = true;
                dfs(ny, nx, count + 1, cur * possibility[i]);
                visited[ny][nx] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < 4; i++) {
            possibility[i] = Integer.parseInt(st.nextToken()) / 100.0;
        }
        br.close();

        visited[25][25] = true;
        dfs(25, 25, 0, 1.0);

        DecimalFormat decimalFormat = new DecimalFormat("#.#########");
        System.out.println(decimalFormat.format(answer));
    }
}
