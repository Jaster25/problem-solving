import java.util.ArrayList;
import java.util.List;

class Solution {

    static List<Integer> answer;
    static int N, M;
    static int[][] MAP;

    public static int rotate(int y1, int x1, int y2, int x2) {
        int min = MAP[y1][x1];
        int temp;
        int before = MAP[y1][x1];

        // to right
        for (int x = x1 + 1; x < x2; x++) {
            temp = MAP[y1][x];
            MAP[y1][x] = before;
            before = temp;
            min = Math.min(min, before);
        }
        // to down
        for (int y = y1; y < y2; y++) {
            temp = MAP[y][x2];
            MAP[y][x2] = before;
            before = temp;
            min = Math.min(min, before);
        }
        // to left
        for (int x = x2; x > x1; x--) {
            temp = MAP[y2][x];
            MAP[y2][x] = before;
            before = temp;
            min = Math.min(min, before);
        }
        // to up
        for (int y = y2; y > y1; y--) {
            temp = MAP[y][x1];
            MAP[y][x1] = before;
            before = temp;
            min = Math.min(min, before);
        }
        MAP[y1][x1] = before;

        return min;
    }

    public int[] solution(int rows, int columns, int[][] queries) {
        answer = new ArrayList<>();
        N = rows;
        M = columns;
        MAP = new int[N][M];
        int count = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                MAP[i][j] = count++;
            }
        }

        for (int[] query : queries) {
            answer.add(rotate(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1));
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }
}