package boj1717;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] parent;

    static int[] makeParentSet(int size) {
        int[] parent = new int[size + 1];
        for (int i = 0; i <= size; i++) {
            parent[i] = i;
        }
        return parent;
    }

    static int findParent(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }

    static boolean isSameParent(int a, int b) {
        return findParent(a) == findParent(b);
    }

    static void unionParent(int a, int b) {
        int aP = findParent(a);
        int bP = findParent(b);
        if (aP > bP) {
            parent[aP] = bP;
        } else {
            parent[bP] = aP;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        parent = makeParentSet(N);

        int order, a, b;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            order = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if (order == 0) {
                unionParent(a, b);
            } else {
                System.out.println(isSameParent(a, b) ? "YES" : "NO");
            }
        }
        br.close();
    }
}

