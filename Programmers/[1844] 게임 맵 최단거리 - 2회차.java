import java.util.*;

class Solution {
    
    class Node {
        int y, x;
        public Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0 , -1};
    static int[][] isVisited;
        
    public int solution(int[][] maps) {
        
        int height = maps.length;
        int width = maps[0].length;
        isVisited = new int[height][width];
        
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0));
        isVisited[0][0] = 1;
        
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.y == height - 1 && node.x == width - 1) {
                return isVisited[node.y][node.x];
            }
            
            for (int i = 0; i < 4; i++) {
                int ny = node.y + dy[i];
                int nx = node.x + dx[i];
                if (0<=ny && ny<height && 0<=nx && nx<width) {
                    if (maps[ny][nx] == 1 && isVisited[ny][nx] == 0) {
                        isVisited[ny][nx] = isVisited[node.y][node.x] + 1;
                        queue.offer(new Node(ny, nx));
                    }
                }
            }   
        }
        
        return -1;
    }
}