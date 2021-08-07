package pg12952;

class Solution {

    static int N;
    static int[] array;
    static int answer;

    static boolean check(int count, int number) {
        for (int i = 0; i < count; i++) {
            if (array[i] == number) {
                return false;
            }
            if (Math.abs(array[i] - number) == Math.abs(i - count)) {
                return false;
            }
        }
        return true;
    }

    static void dfs(int count) {
        if (count == N) {
            answer += 1;
            return;
        }

        for (int i = 0; i < N; i++) {
            if (check(count, i)) {
                array[count] = i;
                dfs(count + 1);
            }
        }
    }

    public int solution(int n) {
        N = n;
        array = new int[N];

        dfs(0);

        return answer;
    }
}