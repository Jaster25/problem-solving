package boj13302;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int MAX_NUMBER = 111;
    static final int INF = 987654321;
    static final int ONE_DAY_COST = 10_000;
    static final int THREE_DAY_COST = 25_000;
    static final int FIVE_DAY_COST = 37_000;

    static int N, M;
    static int[][] cost = new int[MAX_NUMBER][MAX_NUMBER];
    static boolean[] impossibleDate = new boolean[MAX_NUMBER];

    static int dp(int date, int couponCount) {
        if (date > N) return 0;
        if (cost[date][couponCount] != INF) {
            return cost[date][couponCount];
        }
        if (impossibleDate[date]) {
            return cost[date][couponCount] =  Math.min(cost[date][couponCount], dp(date + 1, couponCount));
        }

        cost[date][couponCount] = Math.min(cost[date][couponCount], dp(date + 1, couponCount) + ONE_DAY_COST);
        cost[date][couponCount] = Math.min(cost[date][couponCount], dp(date + 3, couponCount + 1) + THREE_DAY_COST);
        cost[date][couponCount] = Math.min(cost[date][couponCount], dp(date + 5, couponCount + 2) + FIVE_DAY_COST);
        if (couponCount >= 3) {
            cost[date][couponCount] = Math.min(cost[date][couponCount], dp(date + 1, couponCount - 3));
        }

        return cost[date][couponCount];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        if(M > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                impossibleDate[Integer.parseInt(st.nextToken())] = true;
            }
        }

        for (int i = 0; i < MAX_NUMBER; i++) {
            Arrays.fill(cost[i], INF);
        }

        int answer = dp(1, 0);
        System.out.println(answer);
    }
}
