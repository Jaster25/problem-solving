package boj1922;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] parents;

    static int[] makeParentArray() {
        int[] array = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            array[i] = i;
        }
        return array;
    }

    static int findParent(int a) {
        int pa = parents[a];
        if (pa == a) {
            return a;
        }
        return parents[pa] = findParent(pa);
    }

    static boolean isSameParent(int a, int b) {
        return findParent(a) == findParent(b);
    }

    static void unionParent(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa < pb) {
            parents[pa] = b;
        } else {
            parents[pb] = a;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(o -> o.cost));
        for (int i = 0; i < M; i++) {
            int a, b, c;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            priorityQueue.offer(new Node(a, b, c));
        }
        br.close();

        int total = 0;
        parents = makeParentArray();

        while (!priorityQueue.isEmpty()) {
            Node popped = priorityQueue.poll();
            int a = popped.a;
            int b = popped.b;
            int cost = popped.cost;
            if (!isSameParent(a, b)) {
                total += cost;
                unionParent(a, b);
            }
        }

        System.out.println(total);
    }

    static class Node {
        int a, b, cost;

        public Node(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
    }
}
