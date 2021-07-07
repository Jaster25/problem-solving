import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {
    static int answer;
    static int N;
    static int[][] MAP;
    static int[] selfCost;
    static int[] parent;
    static PriorityQueue<Edge> pq;

    static int[] makeParentSet(int size) {
        int[] p = new int[size + 1];
        for (int i = 0; i < size + 1; i++) {
            p[i] = i;
        }
        return p;
    }

    static int findParent(int a) {
        int pa = parent[a];
        if (pa == a) {
            return pa;
        } else {
            return parent[a] = findParent(pa);
        }
    }

    static void unionParent(int a, int b) {
        int pa = parent[a];
        int pb = parent[b];
        if (pa < pb) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        pq = new PriorityQueue<>();
        N = sc.nextInt();
        MAP = new int[N + 1][N + 1];
        selfCost = new int[N + 1];
        parent = makeParentSet(N);

        for (int i = 1; i < N + 1; i++) {
            selfCost[i] = sc.nextInt();
        }
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                MAP[i][j] = sc.nextInt();
            }
        }
        sc.close();

        for (int i = 1; i < N + 1; i++) {
            for (int j = i; j < N + 1; j++) {
                if (i == j) {
                    pq.add(new Edge(0, i, selfCost[i]));
                } else {
                    pq.add(new Edge(i, j, MAP[i][j]));
                }
            }
        }

        while (!pq.isEmpty()) {
            Edge popped = pq.poll();
            if (findParent(popped.a) != findParent(popped.b)) {
                unionParent(popped.a, popped.b);
                answer += popped.cost;
            }
        }

        System.out.println(answer);
    }

    static class Edge implements Comparable<Edge> {
        int a, b, cost;

        public Edge(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }
}
