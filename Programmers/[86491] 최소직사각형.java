package wk8;

class Solution {

    public int solution(int[][] sizes) {
        int minWidth = 0; // longer
        int minHeight = 0; // shorter

        for (int[] size : sizes) {
            int longer = Math.max(size[0], size[1]);
            int shorter = Math.min(size[0], size[1]);

            minWidth = Math.max(minWidth, longer);
            minHeight = Math.max(minHeight, shorter);
        }

        return minWidth * minHeight;
    }
}