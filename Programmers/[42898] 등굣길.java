package pg42898;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class Solution {
    final static int MOD = 1_000_000_007;

    public int solution(int m, int n, int[][] puddles) {
        int[][] dp = new int[n][m];
        for (int[] puddle : puddles) {
            dp[puddle[1] - 1][puddle[0] - 1] = -1;
        }

        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    continue;
                }

                if (i > 0 && dp[i - 1][j] != -1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
                if (j > 0 && dp[i][j - 1] != -1) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
        return dp[n - 1][m - 1];
    }

    @Test
    public void test() {
        Assertions.assertEquals(4, solution(4, 3, new int[][]{{2, 2}}));
    }
}