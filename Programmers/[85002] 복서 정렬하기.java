package wk6;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {

    public int[] solution(int[] weights, String[] head2head) {
        List<Boxer> boxers = new ArrayList<>();

        for (int i = 0; i < weights.length; i++) {
            Boxer boxer = new Boxer();
            boxer.index = i;
            boxer.weight = weights[i];

            int gameCount = 0;
            int winCount = 0;
            for (int j = 0; j < weights.length; j++) {
                char record = head2head[i].charAt(j);
                if (record != 'N') {
                    gameCount++;
                }
                if (record == 'W') {
                    winCount++;
                    if (weights[j] > boxer.weight) {
                        boxer.winHeavyBoxerCount++;
                    }
                }
            }
            boxer.winningRate = winCount != 0 ? (double) winCount / gameCount : 0.0;

            boxers.add(boxer);
        }

        Collections.sort(boxers);

        return boxers.stream()
                .mapToInt(x -> x.index + 1)
                .toArray();
    }

    static class Boxer implements Comparable<Boxer> {
        int index;
        int weight;
        double winningRate;
        int winHeavyBoxerCount;

        @Override
        public int compareTo(Boxer o) {
            if (this.winningRate != o.winningRate)
                return Double.compare(o.winningRate, this.winningRate);
            if (this.winHeavyBoxerCount != o.winHeavyBoxerCount)
                return Integer.compare(o.winHeavyBoxerCount, this.winHeavyBoxerCount);
            if (this.weight != o.weight)
                return Integer.compare(o.weight, this.weight);
            return Integer.compare(this.index, o.index);
        }
    }
}