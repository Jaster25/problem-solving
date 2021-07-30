package pg67258;

import java.util.*;

class Solution {

    static final int MAX_INT = 987654321;

    static Set<String> gemsSet;
    static Map<String, Integer> curGemsMap;

    static boolean hasAllGems() {
        return curGemsMap.size() == gemsSet.size();
    }

    public int[] solution(String[] gems) {
        gemsSet = new HashSet<>(Arrays.asList(gems));
        curGemsMap = new HashMap<>();

        int startIndex = 0;
        int endIndex = 0;

        int shortestLength = MAX_INT;
        int shortestStartIndex = MAX_INT;

        while (endIndex <= gems.length) {
            if (!hasAllGems()) {
                if (endIndex == gems.length) {
                    break;
                }

                if (curGemsMap.containsKey(gems[endIndex])) {
                    curGemsMap.put(gems[endIndex], curGemsMap.get(gems[endIndex]) + 1);
                } else {
                    curGemsMap.put(gems[endIndex], 1);
                }
                endIndex++;
            } else {
                int curLength = endIndex - startIndex;
                if (curLength < shortestLength) {
                    shortestLength = curLength;
                    shortestStartIndex = startIndex;
                } else if (curLength == shortestLength && startIndex < shortestStartIndex) {
                    shortestStartIndex = startIndex;
                }

                curGemsMap.put(gems[startIndex], curGemsMap.get(gems[startIndex]) - 1);
                if (curGemsMap.get(gems[startIndex]) == 0) {
                    curGemsMap.remove(gems[startIndex]);
                }

                startIndex++;
            }
        }

        return new int[]{shortestStartIndex + 1, shortestStartIndex + shortestLength};
    }
}
