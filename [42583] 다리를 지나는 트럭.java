package pg42583;

import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Solution {

    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int curTime = 0;
        int curBridgeWeight = 0;

        int truckIndex = 0;
        int truckCount = 0;

        Queue<Truck> queue = new LinkedList<>();
        queue.offer(new Truck(0, 0));

        while (!queue.isEmpty()) {
            curTime++;

            if (queue.peek().arrivalTime <= curTime) {
                curBridgeWeight -= queue.poll().weight;
                truckCount--;
            }

            if (truckIndex < truck_weights.length &&
                    curBridgeWeight + truck_weights[truckIndex] <= weight &&
                    truckCount < bridge_length) {
                queue.offer(new Truck(curTime + bridge_length, truck_weights[truckIndex]));
                curBridgeWeight += truck_weights[truckIndex];
                truckCount++;
                truckIndex++;
            }
        }

        return curTime;
    }

    @Test
    void test() throws Exception {
        assertEquals(8, solution(2, 10, new int[]{7, 4, 5, 6}));
    }

    static class Truck {
        int arrivalTime;
        int weight;

        public Truck(int arrivalTime, int weight) {
            this.arrivalTime = arrivalTime;
            this.weight = weight;
        }
    }
}