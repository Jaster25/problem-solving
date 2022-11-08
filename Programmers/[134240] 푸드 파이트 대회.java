import java.util.Stack;
import java.lang.StringBuilder;

class Solution {
    public String solution(int[] food) {
        
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>();
        
        for (int calorie = 1; calorie < food.length; calorie++) {
            int number = food[calorie];
            while (number >= 2) {
                sb.append(calorie);
                stack.push(calorie);
                number -= 2;
            }
        }
        
        sb.append("0");

        while (!stack.empty()) {
            int number = stack.pop();
            sb.append(number);
        }
        
        String answer = sb.toString();
        return answer;
    }
}