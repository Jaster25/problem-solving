import java.util.LinkedList;
import java.util.Queue;


class Solution {
        
    static final int[] DY = {-1, 0, 1, 0};
    static final int[] DX = {0, 1, 0, -1};
    
    static class Node {
        int y, x;
        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    public int solution(int[][] maps) {
        
        final int HEIGHT = maps.length;
        final int WIDTH = maps[0].length;
        
        Queue<Node> queue = new LinkedList<>();
        int[][] visited = new int[maps.length][maps[0].length];
        
        queue.offer(new Node(0, 0));
        visited[0][0] = 1;
        while (queue.size() > 0) {
            Node popped = queue.poll();
            int y = popped.y;
            int x = popped.x;
            if (y == HEIGHT - 1 && x == WIDTH - 1) {
                return visited[HEIGHT - 1][WIDTH - 1];
            }
            
            for (int d = 0; d < 4; d++) {
                int ny = y + DY[d];
                int nx = x + DX[d];
                if (0 <= ny && ny < HEIGHT && 0 <= nx && nx < WIDTH) {
                    if (maps[ny][nx] == 1) {
                        if (visited[ny][nx] == 0) {
                            queue.offer(new Node(ny, nx));
                            visited[ny][nx] = visited[y][x] + 1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
}