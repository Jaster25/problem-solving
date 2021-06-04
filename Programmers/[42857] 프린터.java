import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {

    public int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());
        for (int priority : priorities) {
            queue.add(priority);
        }

        while (!queue.isEmpty()) {
            for (int i = 0; i < priorities.length; i++) {
                if (queue.peek() == priorities[i]) {
                    queue.poll();
                    answer++;
                    if (location == i) {
                        queue.clear();
                        break;
                    }
                }
            }
        }

        return answer;
    }
}