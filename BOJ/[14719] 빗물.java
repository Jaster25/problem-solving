package boj14719;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        boolean[][] isBlock = new boolean[H][W];

        for (int i = 0; i < W; i++) {
            int blockHeight = Integer.parseInt(st.nextToken());
            for (int j = 0; j < blockHeight; j++) {
                isBlock[j][i] = true;
            }
        }
        br.close();

        int answer = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (isBlock[i][j]) {
                    int start = j;
                    while (j + 1 < W && !isBlock[i][j + 1]) {
                        j++;
                    }
                    if (j + 1 < W && isBlock[i][j + 1]) {
                        if (start < j + 1) {
                            answer += j - start;
                        }
                    }
                }
            }
        }

        System.out.println(answer);
    }
}