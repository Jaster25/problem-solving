package boj10844;

import java.util.Scanner;

public class Main {
    static final int MOD = 1_000_000_000;
    static int[][] dp;
    static int N;

    static int solution(int index, int curNumber) {
        if (index == 0 || dp[index][curNumber] != 0) {
            return dp[index][curNumber];
        }

        if (curNumber == 0) {
            return dp[index][curNumber] = solution(index - 1, 1);
        } else if (curNumber == 9) {
            return dp[index][curNumber] = solution(index - 1, 8);
        } else {
            return dp[index][curNumber] = (solution(index - 1, curNumber - 1)
                    + solution(index - 1, curNumber + 1))
                    % MOD;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        dp = new int[N][10];
        sc.close();

        for (int i = 1; i <= 9; i++) {
            dp[0][i] = 1;
        }

        int answer = 0;
        for (int i = 0; i <= 9; i++) {
            answer = (answer + solution(N - 1, i)) % MOD;
        }

        System.out.println(answer);
    }
}