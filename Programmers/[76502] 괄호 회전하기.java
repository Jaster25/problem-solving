import java.util.Stack;

class Solution {

    static boolean isSameParenthesis(char ch, char top) {
        if (ch == ']' && top == '[') return true;
        if (ch == '}' && top == '{') return true;
        if (ch == ')' && top == '(') return true;
        return false;
    }

    static boolean check(StringBuilder sb) {
        Stack<Character> stack = new Stack<>();

        for (char ch : sb.toString().toCharArray()) {
            if (ch == '[' || ch == '{' || ch == '(') {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.peek();
                if (isSameParenthesis(ch, top)) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    public int solution(String s) {
        int answer = 0;
        StringBuilder sb = new StringBuilder(s);
        int sLength = s.length();
        for (int i = 0; i < sLength; i++) {
            char popped = sb.charAt(0);
            sb.delete(0, 1);
            sb.append(popped);
            if (check(sb)) {
                answer++;
            }
        }

        return answer;
    }
}