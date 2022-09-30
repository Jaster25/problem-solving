import java.util.*;

public class Solution {
    public int solution(int n) {
        
        String nString = String.valueOf(n);
        int nLength = nString.length();

        int sum = 0;
        for (int i = 0; i < nLength; i++) {
            // sum += nString.charAt(i) -'0';
            sum += Integer.parseInt(nString.substring(i, i+1));
        }

        return sum;
    }
}