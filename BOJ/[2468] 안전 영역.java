package BOJ_2468;

import java.util.Scanner;

public class Main {
    final static int[] dy = {-1, 0, 1, 0};
    final static int[] dx = {0, 1, 0, -1};
    static int N;
    static int[][] MAP;
    static boolean[][] visited;
    static int maxSafeAreaCnt = 0;
    static int maxDepth = 0;

    static void dfs(int curDepth, int y, int x) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (curDepth < MAP[ny][nx]) {
                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        dfs(curDepth, ny, nx);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        MAP = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                MAP[i][j] = sc.nextInt();
                maxDepth = Math.max(maxDepth, MAP[i][j]);
            }
        }
        sc.close();

        for (int curDepth = 0; curDepth < maxDepth; curDepth++) {
            int cnt = 0;
            visited = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (curDepth < MAP[i][j]) {
                        if (!visited[i][j]) {
                            cnt++;
                            visited[i][j] = true;
                            dfs(curDepth, i, j);
                        }
                    }
                }
            }
            maxSafeAreaCnt = Math.max(maxSafeAreaCnt, cnt);
        }
        System.out.println(maxSafeAreaCnt);
    }
}
