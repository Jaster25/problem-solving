package boj1944;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};

    static int N, M;
    static char[][] MAP;
    static List<Position> positions;
    static int positionSize;

    static PriorityQueue<Node> priorityQueue;
    static int[] parents;

    // step1: S,K -> List<Position> positions
    // step2: positions 간 bfs 거리 계산 -> priorityQueue
    // step3: MST-Kruskal
    // step4: check result

    static void bfs(int a) {
        Position start = positions.get(a);

        Queue<Position> queue = new LinkedList<>();
        int[][] visited = new int[N][N];
        queue.offer(new Position(start.y, start.x));
        visited[start.y][start.x] = 1;

        while (!queue.isEmpty()) {
            Position popped = queue.poll();
            int y = popped.y;
            int x = popped.x;

            if (visited[y][x] != 1 && (MAP[y][x] == 'S' || MAP[y][x] == 'K')) {
                for (int b = 0; b < positionSize; b++) {
                    Position position = positions.get(b);
                    if (position.y == y && position.x == x) {
                        priorityQueue.offer(new Node(a, b, visited[y][x] - 1));
                        break;
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                    if (MAP[ny][nx] != '1') {
                        if (visited[ny][nx] == 0) {
                            visited[ny][nx] = visited[y][x] + 1;
                            queue.offer(new Position(ny, nx));
                        }
                    }
                }
            }
        }
    }

    static int[] makeParents() {
        int[] array = new int[positionSize];
        for (int i = 0; i < positionSize; i++) {
            array[i] = i;
        }
        return array;
    }

    static int findParent(int a) {
        if (parents[a] == a) {
            return a;
        }
        return parents[a] = findParent(parents[a]);
    }

    static boolean isSameParent(int a, int b) {
        return findParent(a) == findParent(b);
    }

    static void unionParent(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa < pb) {
            parents[pa] = pb;
        } else {
            parents[pb] = pa;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // step1
        positions = new ArrayList<>();
        MAP = new char[N][N];
        for (int i = 0; i < N; i++) {
            String row = br.readLine();
            for (int j = 0; j < N; j++) {
                MAP[i][j] = row.charAt(j);
                if (MAP[i][j] == 'S' || MAP[i][j] == 'K') {
                    positions.add(new Position(i, j));
                }
            }
        }
        br.close();

        // step2
        priorityQueue = new PriorityQueue<>(Comparator.comparingInt(o -> o.cost));
        positionSize = positions.size();
        for (int i = 0; i < positionSize; i++) {
            bfs(i);
        }

        // step3
        int total = 0;
        parents = makeParents();
        while (!priorityQueue.isEmpty()) {
            Node popped = priorityQueue.poll();
            int a = popped.a;
            int b = popped.b;
            int cost = popped.cost;

            if (!isSameParent(a, b)) {
                unionParent(a, b);
                total += cost;
            }
        }

        // step4
        Set<Integer> set = new HashSet<>();
        for (int parent : parents) {
            set.add(parent);
        }

        if (set.size() == 1) {
            System.out.println(total);
        } else {
            System.out.println(-1);
        }
    }

    static class Position {
        int y, x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
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
