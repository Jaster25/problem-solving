import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Point {
    int y;
    int x;

    public Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {

    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, -1, 0, 1};
    static int[][] visited;
    static int rowLength;
    static int colLength;

    void bfs(int[][] maps) {
        Queue<Point> queue = new LinkedList<>();
        queue.offer(new Point(0, 0));
        visited[0][0] = 1;

        while (!queue.isEmpty()) {
            Point cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (0 <= ny && ny < rowLength && 0 <= nx && nx < colLength) {
                    if (maps[ny][nx] == 1 && visited[ny][nx] == -1) {
                        visited[ny][nx] = visited[cur.y][cur.x] + 1;
                        queue.offer(new Point(ny, nx));
                        if (ny == rowLength - 1 && nx == colLength - 1) {
                            queue.clear();
                            break;
                        }
                    }
                }
            }
        }
    }

    public int solution(int[][] maps) {

        rowLength = maps.length;
        colLength = maps[0].length;
        visited = new int[rowLength][colLength];
        for (int[] row : visited) {
            Arrays.fill(row, -1);
        }

        bfs(maps);

        return visited[rowLength - 1][colLength - 1];
    }
}