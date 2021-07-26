package pg42885;

import java.util.*;

class Solution {

    public int solution(int[] people, int limit) {
        Deque<Integer> deque = new ArrayDeque<>(50001);
        List<Integer> list = new ArrayList<>();
        for (int person : people) {
            list.add(person);
        }
        Collections.sort(list);

        for (int person : list) {
            deque.offer(person);
        }

        int answer = 0;
        int lightest = deque.peekFirst();
        while (!deque.isEmpty()) {
            answer++;
            int curWeight = deque.pollLast();
            if (!deque.isEmpty() && curWeight + lightest <= limit) {
                deque.pollFirst();
                if (!deque.isEmpty()) {
                    lightest = deque.peekFirst();
                }
            }
        }

        return answer;
    }
}