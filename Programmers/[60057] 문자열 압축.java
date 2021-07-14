package pg60057;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public int solution(String s) {
        int sLength = s.length();
        List<Integer> result = new ArrayList<>();
        result.add(sLength);

        for (int i = 1; i <= sLength / 2; i++) {
            StringBuilder regex = new StringBuilder("(");
            regex.append(".".repeat(Math.max(0, i)));
            regex.append(")");

            Pattern pattern = Pattern.compile(String.valueOf(regex));
            Matcher match = pattern.matcher(s);
            List<String> sList = new ArrayList<>();
            while (match.find()) {
                sList.add(match.group());
            }
            if (sLength % i != 0) {
                sList.add(s.substring((sLength / i) * i, sLength));
            }

            StringBuilder compressedStr = new StringBuilder();
            for (int j = 0; j < sList.size(); j++) {
                int sameWordCnt = 1;
                for (int k = j + 1; k < sList.size(); k++) {
                    if (!sList.get(j).equals(sList.get(k))) {
                        break;
                    }
                    sameWordCnt++;
                }

                if (sameWordCnt > 1) {
                    compressedStr.append(sameWordCnt);
                }
                compressedStr.append(sList.get(j));
                j += sameWordCnt - 1;
            }
            result.add(compressedStr.length());
        }

        return Collections.min(result);
    }
}