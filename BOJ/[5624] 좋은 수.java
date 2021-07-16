package boj5624;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int MAX_NUMBER = 200_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] array = new int[N];
        boolean[] visited = new boolean[MAX_NUMBER * 2 + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }
        br.close();

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (visited[array[i] - array[j] + MAX_NUMBER]) {
                    answer++;
                    break;
                }
            }

            for (int j = 0; j <= i; j++) {
                visited[array[i] + array[j] + MAX_NUMBER] = true;
            }
        }

        System.out.println(answer);
    }
}

