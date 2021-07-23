package boj2806;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[] alphabets = br.readLine().toCharArray();
        br.close();

        int dp[][] = new int[N][2];
        // dp[][0] => A
        // dp[][1] => B
        if (alphabets[0] == 'A') {
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
        }

        for (int i = 1; i < N; i++) {
            if (alphabets[i] == 'A') {
                dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            } else {
                dp[i][0] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
                dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1]);
            }
        }

        System.out.println(dp[N-1][0]);
    }
}
