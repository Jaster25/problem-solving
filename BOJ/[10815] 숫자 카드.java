package boj10815;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] cards;

    static int binarySearch(int number) {
        int left = 0;
        int right = cards.length - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (cards[mid] == number) {
                return 1;
            } else if (cards[mid] < number) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        cards = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            cards[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(cards);

        StringBuilder answer = new StringBuilder();
        M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < M; i++) {
            int number = Integer.parseInt(st.nextToken());
            answer.append(binarySearch(number)).append(" ");
        }
        br.close();

        System.out.println(answer);
    }
}
