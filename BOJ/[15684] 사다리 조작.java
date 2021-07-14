package boj9935;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<Integer> result;
    static int N, M, H;
    static int[][] graph; // [H][N]

    static int down(int h, int idx) {
        if (h == H) {
            return idx;
        }

        if (graph[h + 1][idx] != 0) {
            return down(h + 1, graph[h + 1][idx]);
        }
        return down(h + 1, idx);
    }

    static boolean check() {
        for (int i = 1; i <= N; i++) {
            if (down(0, i) != i) {
                return false;
            }
        }
        return true;
    }

    static void dfs(int h, int n, int cnt) {
        if (check()) {
            result.add(cnt);
        }
        if (cnt == 3) {
            return;
        }

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j < N; j++) {
                if (i == h && j <= n) {
                    continue;
                }
                if (graph[i][j] == 0 && graph[i][j + 1] == 0) {
                    graph[i][j] = j + 1;
                    graph[i][j + 1] = j;
                    dfs(i, j, cnt + 1);
                    graph[i][j] = 0;
                    graph[i][j + 1] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        result = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        graph = new int[H + 1][N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a][b] = b + 1;
            graph[a][b + 1] = b;
        }

        if (check()) {
            System.out.println(0);
            return;
        }

        for (int i = 1; i <=H ; i++) {
            for (int j = 1; j < N; j++) {
                if (graph[i][j] == 0 && graph[i][j + 1] == 0) {
                    graph[i][j] = j + 1;
                    graph[i][j + 1] = j;
                    dfs(i, j, 1);
                    graph[i][j] = 0;
                    graph[i][j + 1] = 0;
                }
            }
        }

        if (result.isEmpty()) {
            System.out.println(-1);
        } else {
            System.out.println(Collections.min(result));
        }
    }
}
