package wk5;

import java.util.ArrayList;
import java.util.List;

class Solution {

    static final Character[] chars = {'A', 'E', 'I', 'O', 'U'};
    static List<String> words;

    static void dfs(StringBuilder sb) {
        if (sb.length() == 5) {
            return;
        }

        for (int i = 0; i < 5; i++) {
            sb.append(chars[i]);
            if (!words.contains(sb.toString())) {
                words.add(sb.toString());
                dfs(sb);
            }
            sb.setLength(sb.length() - 1);
        }
    }

    public int solution(String word) {
        words = new ArrayList<>();

        dfs(new StringBuilder());

        return words.indexOf(word) + 1;
    }
}