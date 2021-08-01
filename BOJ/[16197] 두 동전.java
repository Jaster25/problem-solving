package boj16197;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};
    static int N, M;
    static char[][] map;
    static int minCount = 11;

    static boolean isOutOfRange(Position coin) {
        return coin.y == 0 || coin.y == N + 1 || coin.x == 0 || coin.x == M + 1;
    }

    static void dfs(Position coin1, Position coin2, int count) {
        if (count > 10 || coin1.equals(coin2)) return;

        if (isOutOfRange(coin1) && isOutOfRange(coin2)) {
            return;
        }
        // XOR 연산
        if (isOutOfRange(coin1) ^ isOutOfRange(coin2)) {
            minCount = Math.min(count, minCount);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny1 = coin1.y + dy[i];
            int nx1 = coin1.x + dx[i];
            int ny2 = coin2.y + dy[i];
            int nx2 = coin2.x + dx[i];

            if (map[ny1][nx1] == '#') {
                ny1 = coin1.y;
                nx1 = coin1.x;
            }
            if (map[ny2][nx2] == '#') {
                ny2 = coin2.y;
                nx2 = coin2.x;
            }

            Position nCoin1 = new Position(ny1, nx1);
            Position nCoin2 = new Position(ny2, nx2);

            dfs(nCoin1, nCoin2, count + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[N + 2][M + 2];
        for (int i = 0; i < N + 2; i++) {
            Arrays.fill(map[i], '.');
        }

        for (int i = 0; i < N; i++) {
            String row = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i + 1][j + 1] = row.charAt(j);
            }
        }
        br.close();

        List<Position> coins = new ArrayList<>();
        for (int i = 1; i < N+1; i++) {
            for (int j = 1; j < M+1; j++) {
                if (map[i][j] == 'o') {
                    coins.add(new Position(i, j));
                }
            }
        }

        dfs(coins.get(0), coins.get(1), 0);

        if (minCount == 11) {
            System.out.println("-1");
        } else {
            System.out.println(minCount);
        }
    }

    static class Position {
        int y, x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Position position = (Position) o;

            if (y != position.y) return false;
            return x == position.x;
        }

        @Override
        public int hashCode() {
            int result = y;
            result = 31 * result + x;
            return result;
        }
    }
}
