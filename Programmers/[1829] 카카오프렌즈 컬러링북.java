package com.ps.java.pg1829;

class Solution {
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};
    static boolean[][] visited;
    static int[][] MAP;
    static int curAreaCnt;
    static int M;
    static int N;

    void dfs(int y, int x) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < M && 0 <= nx && nx < N) {
                if (MAP[y][x] == MAP[ny][nx]) {
                    if (!visited[ny][nx]) {
                        curAreaCnt++;
                        visited[ny][nx] = true;
                        dfs(ny, nx);
                    }
                }
            }
        }
    }

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        N = n;
        M = m;
        MAP = picture;
        visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] != 0) {
                    if (!visited[i][j]) {
                        curAreaCnt = 1;
                        visited[i][j] = true;
                        dfs(i, j);

                        numberOfArea++;
                        maxSizeOfOneArea = Math.max(curAreaCnt, maxSizeOfOneArea);
                    }
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}
