package wk9;

import java.util.*;

class Solution {

    static Map<Integer, Set<Integer>> tree = new HashMap<>();
    static int minDifference = 987654321;

    int countNode(int v) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] isVisited = new boolean[101];
        int count = 0;

        isVisited[v] = true;
        queue.offer(v);
        count++;

        while (!queue.isEmpty()) {
            int popped = queue.poll();
            for (int newNode : tree.get(popped)) {
                if (!isVisited[newNode]) {
                    isVisited[newNode] = true;
                    queue.offer(newNode);
                    count++;
                }
            }
        }
        return count;
    }

    int calculateDifference(int v1, int v2) {
        int v1Count = countNode(v1);
        int v2Count = countNode(v2);
        return Math.abs(v1Count - v2Count);
    }

    public int solution(int n, int[][] wires) {
        for (int i = 0; i < 101; i++) {
            tree.put(i, new HashSet<>());
        }

        for (int[] wire : wires) {
            int v1 = wire[0];
            int v2 = wire[1];
            tree.get(v1).add(v2);
            tree.get(v2).add(v1);
        }

        for (int[] wire : wires) {
            int v1 = wire[0];
            int v2 = wire[1];
            tree.get(v1).remove(v2);
            tree.get(v2).remove(v1);

            int difference = calculateDifference(v1, v2);
            minDifference = Math.min(minDifference, difference);

            tree.get(v1).add(v2);
            tree.get(v2).add(v1);
        }

        return minDifference;
    }
}