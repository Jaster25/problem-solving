package workspace;

import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Solution {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < phone_book.length; i++) {
            map.put(phone_book[i], i);
        }

        for (int i = 0; i < phone_book.length; i++) {
            for (int j = 1; j < phone_book[i].length(); j++) {
                if (map.containsKey(phone_book[i].substring(0, j))) {
                    return false;
                }
            }
        }
        return true;
    }

    @Test
    void test() throws Exception {
        assertEquals(false, solution(new String[]{"119", "97674223", "1195524421"}));
        assertEquals(true, solution(new String[]{"123", "456", "789"}));
        assertEquals(false, solution(new String[]{"12", "123", "1235", "567", "88"}));
    }
}