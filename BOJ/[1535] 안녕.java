package boj1535;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] dp = new int[101];
        int[] cost = new int[N + 1];
        int[] earn = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            cost[i] = sc.nextInt();
        }
        for (int i = 1; i <= N; i++) {
            earn[i] = sc.nextInt();
        }
        sc.close();


        for (int i = 1; i <= N; i++) {
            for (int j = 99; j >= 0; j--) {
                int curCost = cost[i] + j;
                if (curCost < 100) {
                    dp[curCost] = Math.max(dp[curCost], dp[j] + earn[i]);
                }
            }
        }

        System.out.println(dp[99]);
    }
}
