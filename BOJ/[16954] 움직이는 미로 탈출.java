package boj16954;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static final int[] dy = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
    static final int[] dx = {0, 1, 0, -1, 1, 1, -1, -1, 0};

    static final int MAP_SIZE = 8;
    static char[][] MAP;

    static void moveWall() {
        // height: MAP_SIZE-1 ~ 1
        for (int i = MAP_SIZE - 1; i > 0; i--) {
            for (int j = 0; j < MAP_SIZE; j++) {
                MAP[i][j] = MAP[i - 1][j];
            }
        }
        // height: 0
        for (int x = 0; x < MAP_SIZE; x++) {
            MAP[0][x] = '.';
        }
    }

    static boolean isInWall(int y, int x) {
        return MAP[y][x] == '#';
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        MAP = new char[MAP_SIZE][MAP_SIZE];
        for (int i = 0; i < MAP_SIZE; i++) {
            String row = br.readLine();
            for (int j = 0; j < MAP_SIZE; j++) {
                MAP[i][j] = row.charAt(j);
            }
        }
        br.close();

        boolean isPossible = false;
        int curSecond = 0;

        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(MAP_SIZE - 1, 0, 0));

        while (!queue.isEmpty()) {
            Position popped = queue.poll();
            int y = popped.y;
            int x = popped.x;
            int second = popped.second;

            if (y == 0 && x == MAP_SIZE - 1) {
                isPossible = true;
                break;
            }

            // 벽 이동
            if (curSecond < second) {
                curSecond = second;
                moveWall();
            }

            // 벽에 낀 상태이면 종료
            if (isInWall(y, x)) {
                continue;
            }

            // 이동
            for (int i = 0; i < 9; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 <= ny && ny < MAP_SIZE && 0 <= nx && nx < MAP_SIZE) {
                    if (MAP[ny][nx] == '.') {
                        queue.offer(new Position(ny, nx, second + 1));
                    }
                }
            }
        }

        System.out.println(isPossible ? 1 : 0);
    }

    static class Position {
        int y, x, second;

        public Position(int y, int x, int second) {
            this.y = y;
            this.x = x;
            this.second = second;
        }
    }
}
