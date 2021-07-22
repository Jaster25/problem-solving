package pg42890;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Solution {
    static String[][] relations;
    static List<Set<Integer>> candidateKeys;
    static int tupleCount;
    static int attributeCount;
    static int candidateKeyCount;

    public boolean checkUniqueness(Set<Integer> set) {
        Set<String> tupleSet = new HashSet<>();
        for (String[] relation : relations) {
            StringBuilder sb = new StringBuilder();
            for (Integer index : set) {
                sb.append(relation[index]);
            }

            if (tupleSet.contains(sb.toString())) {
                return false;
            }
            tupleSet.add(sb.toString());
        }
        return true;
    }

    public boolean checkMinimality(Set<Integer> set) {
        for (Set<Integer> candidateKey : candidateKeys) {
            if (set.containsAll(candidateKey)) {
                return false;
            }
        }

        candidateKeys.add(new HashSet<>(set));
        return true;
    }

    // Backtracking (selected indexSet, index to check, remainCount )
    public void combination(Set<Integer> set, int index, int remainCount) {
        if (remainCount == 0) {
            if (checkUniqueness(set)) {
                if (checkMinimality(set)) {
                    candidateKeyCount++;
                }
            }
            return;
        }

        for (int i = index; i < attributeCount; i++) {
            set.add(i);
            combination(set, i + 1, remainCount - 1);
            set.remove(i);
        }
    }

    public int solution(String[][] relation) {
        candidateKeys = new ArrayList<>();
        relations = relation;

        tupleCount = relation.length;
        attributeCount = relation[0].length;

        for (int i = 1; i <= attributeCount; i++) {
            combination(new HashSet<>(), 0, i);
        }

        return candidateKeyCount;
    }

    @Test
    public void test() {
        assertEquals(2, solution(new String[][]{{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}}));
    }
}