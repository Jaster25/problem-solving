package workspace;

import java.util.*;

class Solution {
    static final int INF = 987654321;

    public int solution(int N, int[][] road, int K) {
        int[] visited = new int[N + 1];
        Arrays.fill(visited, INF);
        List<List<Edge>> graph = new ArrayList<List<Edge>>();
        for (int i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] roadInfo : road) {
            int a = roadInfo[0];
            int b = roadInfo[1];
            int cost = roadInfo[2];
            graph.get(a).add(new Edge(b, cost));
            graph.get(b).add(new Edge(a, cost));
        }

        Queue<Integer> queue = new LinkedList<>();
        visited[1] = 0;
        queue.offer(1);
        while (!queue.isEmpty()) {
            int popped = queue.poll();
            for (Edge edge : graph.get(popped)) {
                int to = edge.to;
                int cost = edge.cost;
                if (visited[to] > visited[popped] + cost) {
                    visited[to] = visited[popped] + cost;
                    queue.add(to);
                }
            }
        }

        int answer = 0;
        for (int v : visited) {
            if (v <= K) {
                answer++;
            }
        }
        return answer;
    }

    static class Edge {
        int to, cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
}
