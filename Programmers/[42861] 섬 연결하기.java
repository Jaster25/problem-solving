import java.util.PriorityQueue;

class Solution {
    static int[] parent;

    static int[] makeParentSet(int n) {
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        return parent;
    }

    static int findParent(int a) {
        if (parent[a] == a) {
            return a;
        } else {
            return parent[a] = findParent(parent[a]);
        }
    }

    static void unionParent(int a, int b) {
        int aParent = parent[a];
        int bParent = parent[b];
        if (aParent < bParent) {
            parent[bParent] = aParent;
        } else {
            parent[aParent] = bParent;
        }
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;
        parent = makeParentSet(n);
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (int[] cost : costs) {
            pq.add(new Edge(cost[0], cost[1], cost[2]));
        }

        while (!pq.isEmpty()) {
            Edge popped = pq.poll();
            int a = popped.a;
            int b = popped.b;
            int cost = popped.cost;
            if (findParent(a) != findParent(b)) {
                unionParent(a, b);
                answer += cost;
            }
        }

        return answer;
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