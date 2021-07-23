package boj13913;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int MAX_LENGTH = 100_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        br.close();

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] parent = new int[MAX_LENGTH + 1];
        int[] visited = new int[MAX_LENGTH + 1];
        Arrays.fill(visited, -1);

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(N);
        visited[N] = 0;

        while (!queue.isEmpty()) {
            int popped = queue.poll();
            if (popped == K) {
                break;
            }

            for (int nextIndex : new int[]{popped - 1, popped + 1, popped * 2}) {
                if (0 <= nextIndex && nextIndex <= MAX_LENGTH) {
                    if (visited[nextIndex] == -1) {
                        visited[nextIndex] = visited[popped] + 1;
                        parent[nextIndex] = popped;
                        queue.offer(nextIndex);
                    }
                }
            }
        }

        Stack<Integer> stack = new Stack<>();
        stack.push(K);

        int trace = K;
        while (trace != N) {
            trace = parent[trace];
            stack.push(trace);
        }

        System.out.println(visited[K]);
        while (!stack.isEmpty()) {
            System.out.print( stack.pop() + " ");
        }
    }
}
