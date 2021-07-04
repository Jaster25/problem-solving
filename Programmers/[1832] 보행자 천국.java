package pg1832;

class Solution {
    static final int MOD = 20170805;
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};

    public int solution(int m, int n, int[][] cityMap) {
        int[][] dp = new int[m][n];
        dp[0][0] = 1;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (cityMap[y][x] == 1 || cityMap[y][x] == 2) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (0 <= ny && ny < m && 0 <= nx && nx < n) {
                        if (cityMap[ny][nx] == 1) {
                            continue;
                        }

                        boolean isPossible = true;
                        while (cityMap[ny][nx] == 2) {
                            ny += dy[i];
                            nx += dx[i];
                            if (!(0 <= ny && ny < m && 0 <= nx && nx < n) || cityMap[ny][nx] == 1) {
                                isPossible = false;
                                break;
                            }
                        }
                        if (isPossible) {
                            dp[y][x] = (dp[y][x] + dp[ny][nx]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
}