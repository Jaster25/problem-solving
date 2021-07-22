package pg42628;

import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minQueue = new PriorityQueue<>();

        int number;
        for (String operation : operations) {
            if (operation.charAt(0) == 'I') {
                number = Integer.parseInt(operation.substring(2));
                maxQueue.offer(number);
                minQueue.offer(number);
            } else if (!maxQueue.isEmpty()) {
                if (operation.charAt(2) == '1') {
                    number = maxQueue.poll();
                    maxQueue.remove(number);
                    minQueue.remove(number);
                } else {
                    number = minQueue.poll();
                    maxQueue.remove(number);
                    minQueue.remove(number);
                }
            }
        }

        if (maxQueue.isEmpty()) {
            return new int[]{0, 0};
        } else {
            return new int[]{maxQueue.peek(), minQueue.peek()};
        }
    }
}
