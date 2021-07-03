package pg42842;

class Solution {
    public int[] solution(int brown, int yellow) {
        int total = brown + yellow;
        int rows, columns, borderCnt;
        for (rows = 3; rows < total; rows++) {
            if (total % rows == 0) {
                columns = total / rows;
                borderCnt = 2 * columns + 2 * rows - 4;
                if (borderCnt == brown) {
                    return new int[]{columns, rows};
                }
            }
        }
        return null;
    }
}