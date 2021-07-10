import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static final int[] dy = {-1, 0, 1, 0};
    static final int[] dx = {0, 1, 0, -1};
    static int R, C;
    static char[][] board;
    static Set<Character> visited = new HashSet<>();
    static int maxCnt = 0;

    static void dfs(int y, int x, int cnt) {
        maxCnt = Math.max(maxCnt, cnt);
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                if (!visited.contains(board[ny][nx])) {
                    visited.add(board[ny][nx]);
                    dfs(ny, nx, cnt + 1);
                    visited.remove(board[ny][nx]);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        StringTokenizer st;

        s = br.readLine();
        st = new StringTokenizer(s);
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new char[R][C];

        for (int i = 0; i < R; i++) {
            s = br.readLine();
            board[i] = s.toCharArray();
        }

        visited.add(board[0][0]);
        dfs(0, 0, 1);

        System.out.println(maxCnt);
    }
}
