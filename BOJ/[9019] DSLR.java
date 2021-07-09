package boj9019;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static String parseToStr(int num) {
        int numLength = String.valueOf(num).length();
        return ("0000" + num).substring(numLength);
    }

    static String bfs(int from, int to) {
        String result = "";
        boolean[] visited = new boolean[10000];
        Queue<Node> queue = new LinkedList<>();
        visited[from] = true;
        queue.offer(new Node(from, ""));

        while (!queue.isEmpty()) {
            Node popped = queue.poll();
            int num = popped.num;
            String command = popped.command;

            if (num == to) {
                result = command;
                break;
            }

            // D: n * 2, if (n*2 > 9999) % 10000
            int d = (num * 2) % 10000;
            if (!visited[d]) {
                visited[d] = true;
                queue.offer(new Node(d, command + 'D'));
            }

            // S: n-1, if (n == 0) 9999
            int s = num == 0 ? 9999 : num - 1;
            if (!visited[s]) {
                visited[s] = true;
                queue.offer(new Node(s, command + 'S'));
            }

            // L: rotate <-
            String temp = parseToStr(num);
            int l = Integer.parseInt(temp.substring(1, 4) + temp.charAt(0));
            if (!visited[l]) {
                visited[l] = true;
                queue.offer(new Node(l, command + 'L'));
            }

            // R: rotate ->
            temp = parseToStr(num);
            int r = Integer.parseInt(temp.charAt(3) + temp.substring(0, 3));
            if (!visited[r]) {
                visited[r] = true;
                queue.offer(new Node(r, command + 'R'));
            }
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            bw.write(bfs(a, b));
            bw.newLine();
        }

        br.close();
        bw.flush();
        bw.close();
    }

    static class Node {
        int num;
        String command;

        public Node(int num, String command) {
            this.num = num;
            this.command = command;
        }
    }
}
