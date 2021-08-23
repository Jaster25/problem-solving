package wk4;

import java.util.HashMap;
import java.util.Map;

class Solution {

    public String solution(String[] table, String[] languages, int[] preference) {

        Map<String, Integer> preferenceMap = new HashMap<>();
        for (int i = 0; i < languages.length; i++) {
            preferenceMap.put(languages[i], preference[i]);
        }

        int maxTotal = -1;
        String maxJob = "";
        for (String job : table) {
            String[] info = job.split(" ");
            String curJob = info[0];
            int total = 0;

            for (int i = 1; i < info.length; i++) {
                if (preferenceMap.containsKey(info[i])) {
                    total += (5 - i + 1) * preferenceMap.get(info[i]);
                }
            }

            if (maxTotal < total) {
                maxTotal = total;
                maxJob = curJob;
            } else if (maxTotal == total) {
                maxJob = maxJob.compareTo(curJob) > 0 ? curJob : maxJob;
            }
        }

        return maxJob;
    }
}