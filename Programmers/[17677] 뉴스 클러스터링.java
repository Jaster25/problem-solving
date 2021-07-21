package pg17677;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Solution {

    static final int MULTIPLY_NUMBER = 65536;

    boolean check(String str) {
        for (char c : str.toCharArray()) {
            if (c < 'a' || c > 'z') {
                return false;
            }
        }
        return true;
    }

    List<String> toMultipleSet(String str) {
        List<String> multipleSet = new ArrayList<>();
        for (int i = 0; i < str.length() - 1; i++) {
            String sub = str.substring(i, i + 2);
            if (check(sub)) {
                multipleSet.add(sub);
            }
        }
        return multipleSet;
    }

    public int solution(String str1, String str2) {
        String lowStr1 = str1.toLowerCase();
        String lowStr2 = str2.toLowerCase();

        List<String> list1 = toMultipleSet(lowStr1);
        List<String> list2 = toMultipleSet(lowStr2);

        int list1Count = list1.size();
        int list2Count = list2.size();

        List<String> intersectionSet = new ArrayList<>();
        for (String s1 : list1) {
            for (String s2 : list2) {
                if (s1.equals(s2)) {
                    intersectionSet.add(s1);
                    list2.remove(s2);
                    break;
                }
            }
        }

        int unionSetCount = list1Count + list2Count - intersectionSet.size();
        int intersectionSetCount = intersectionSet.size();

        if (unionSetCount == 0 && intersectionSetCount == 0) {
            return MULTIPLY_NUMBER;
        }
        return (int) (MULTIPLY_NUMBER * ((float) intersectionSetCount / unionSetCount));
    }

    @Test
    void test() {
        assertEquals(solution("FRANCE", "french"), 16384);
        assertEquals(solution("handshake", "shake hands"), 65536);
        assertEquals(solution("aa1+aa2", "AAAA12"), 43690);
        assertEquals(solution("E=M*C^2", "e=m*c^2"), 65536);
    }
}