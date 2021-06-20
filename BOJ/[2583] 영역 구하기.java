package boj_2583;

import java.util.*;

public class Main {
    static int N, M, K;
    static boolean[][] area;
    static boolean[][] visited;
    static List<Integer> answer;
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};

    static void dfs(int y, int x) {
        int lastIdx = answer.size() - 1;
        answer.set(lastIdx, answer.get(lastIdx) + 1);
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < M && 0 <= nx && nx < N) {
                if (!area[ny][nx]) {
                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        dfs(ny, nx);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        K = sc.nextInt();
        area = new boolean[M][N];
        visited = new boolean[M][N];

        for (int i = 0; i < K; i++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            for (int y = y1; y < y2; y++) {
                for (int x = x1; x < x2; x++) {
                    area[y][x] = true;
                }
            }
        }
        sc.close();

        answer = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!area[i][j]) {
                    if (!visited[i][j]) {
                        answer.add(0);
                        visited[i][j] = true;
                        dfs(i, j);
                    }
                }
            }
        }
        Collections.sort(answer);
        
        System.out.println(answer.size());
        for (Integer i : answer) {
            System.out.print(i + " ");
        }
    }
}
