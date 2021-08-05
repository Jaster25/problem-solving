package boj1756;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int D, N;
        int[] pizzas, diameters, visited;

        st = new StringTokenizer(br.readLine());
        D = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        diameters = new int[N];
        visited = new int[N];
        pizzas = new int[D];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < D; i++) {
            pizzas[i] = Integer.parseInt(st.nextToken());
            if (i > 0) {
                pizzas[i] = Math.min(pizzas[i], pizzas[i - 1]);
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            diameters[i] = Integer.parseInt(st.nextToken());
        }
        br.close();

        int index = 0;
        for (int i = D - 1; i >= 0; i--) {
            if (diameters[index] <= pizzas[i]) {
                visited[index++] = i + 1;
            }
            if (index == N) {
                break;
            }
        }

        System.out.println(index == N ? visited[N - 1] : 0);
    }
}
