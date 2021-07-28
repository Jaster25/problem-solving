package boj2910;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        br.close();

        HashMap<Integer, Frequency> frequencyMap = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int number = Integer.parseInt(st.nextToken());
            if (!frequencyMap.containsKey(number)) {
                frequencyMap.put(number, new Frequency(number, 1, i));
            } else {
                frequencyMap.get(number).addCount();
            }
        }

        List<Frequency> frequencyList = new ArrayList<>(frequencyMap.values());

        Collections.sort(frequencyList);

        frequencyList.forEach(x ->
                System.out.print((x.number + " ").repeat(x.count)));
    }

    static class Frequency implements Comparable<Frequency> {
        int number;
        int count;
        int firstIndex;

        public Frequency(int number, int count, int firstIndex) {
            this.number = number;
            this.count = count;
            this.firstIndex = firstIndex;
        }

        public void addCount() {
            this.count++;
        }

        @Override
        public int compareTo(Frequency o) {
            if (o.count == this.count) {
                return this.firstIndex - o.firstIndex;
            }
            return o.count - this.count;
        }
    }
}
