import java.util.Arrays;

class Solution {
    
    public String solution(int[] numbers) {
        String[] strNumbers = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            strNumbers[i] = Integer.toString(numbers[i]);
        }

        Arrays.sort(strNumbers, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        if (strNumbers[0].equals("0")) {
            return "0";
        }

        StringBuilder answer = new StringBuilder();
        for (String strNumber : strNumbers) {
            answer.append(strNumber);
        }
        return answer.toString();
    }
}
