package boj1963;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int T, from, to;
    static boolean[] isPrime;
    static int[] visited;

    static void primeNumberSieve() {
        for (int i = 2; i < 10000; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i + i; j < 10000; j += i) {
                if (!isPrime[j]) {
                    continue;
                }
                isPrime[j] = false;
            }
        }
    }

    static boolean checkConditions(int number) {
        if (String.valueOf(number).length() < 4) {
            return false;
        }
        return isPrime[number];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        isPrime = new boolean[10000];
        visited = new int[10000];
        Arrays.fill(isPrime, true);
        primeNumberSieve();

        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            Arrays.fill(visited, -1);

            // BFS
            Queue<Node> queue = new LinkedList<>();
            queue.add(new Node(from, 0));
            visited[from] = 0;

            boolean isPossible = false;
            while (!queue.isEmpty()) {
                Node popped = queue.poll();
                int number = popped.number;
                String numberStr = String.valueOf(number);
                int count = popped.count;

                if (number == to) {
                    isPossible = true;
                    queue.clear();
                    break;
                }

                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k <= 9; k++) {
                        int newNumber = Integer.parseInt(numberStr.substring(0, j) + k + numberStr.substring(j + 1, 4));
                        if (checkConditions(newNumber)) {
                            if (visited[newNumber] == -1) {
                                visited[newNumber] = count + 1;
                                queue.offer(new Node(newNumber, count + 1));
                            }
                        }
                    }
                }
            }

            if (isPossible) {
                System.out.println(visited[to]);
            } else {
                System.out.println("Impossible");
            }
        }
        br.close();
    }

    static class Node {
        int number, count;

        public Node(int number, int count) {
            this.number = number;
            this.count = count;
        }
    }
}
