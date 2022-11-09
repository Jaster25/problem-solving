class Solution {
    public long solution(int n, int[] times) {

        long left = 0;
        long right = (long) n * times[times.length - 1];
        while (left + 1 < right) {
            long mid = (long) (left + right) / 2;

            long total = 0;
            for (int time : times) {
                total += (long) mid / time;
            }
            
            if (total >= n) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return right;
    }
}