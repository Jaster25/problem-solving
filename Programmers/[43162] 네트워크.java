import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] isVisited = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                Queue<Integer> queue = new LinkedList<>();
                queue.offer(i);
                isVisited[i] = true;
                while (queue.size() > 0) {
                    int popped = queue.poll();
                    for (int j = 0; j < n; j++) {
                        if (computers[j][popped] == 1) {
                            if (!isVisited[j]) {
                                queue.offer(j);
                                isVisited[j] = true;
                            }
                        }
                    }
                }
                answer += 1;
            }
        }
        
        return answer;
    }
}