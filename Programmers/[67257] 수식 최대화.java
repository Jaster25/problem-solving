package pg67257;

import java.util.*;

class Solution {

    static boolean isOperator(Character ch) {
        return ch == '*' || ch == '+' || ch == '-';
    }

    static List<List<Character>> combination() {
        List<List<Character>> combinations = new ArrayList<>();
        combinations.add(new ArrayList<>(Arrays.asList('*', '+', '-')));
        combinations.add(new ArrayList<>(Arrays.asList('*', '-', '+')));
        combinations.add(new ArrayList<>(Arrays.asList('+', '*', '-')));
        combinations.add(new ArrayList<>(Arrays.asList('+', '-', '*')));
        combinations.add(new ArrayList<>(Arrays.asList('-', '*', '+')));
        combinations.add(new ArrayList<>(Arrays.asList('-', '+', '*')));
        return combinations;
    }

    static long calculate(String operand1, String operand2, Character operator) {
        long number1 = Long.parseLong(operand1);
        long number2 = Long.parseLong(operand2);

        if (operator == '*') {
            return number1 * number2;
        } else if (operator == '+') {
            return number1 + number2;
        } else {
            return number1 - number2;
        }
    }

    static List<String> calculateExpression(List<String> expression, Character operator) {
        Stack<String> stack = new Stack<>();
        for (int i = 0; i < expression.size(); i++) {
            // 숫자일 경우
            if (i % 2 == 0) {
                stack.push(expression.get(i));
            } else {
                if (expression.get(i).charAt(0) == operator) {
                    long result = calculate(stack.pop(), expression.get(i + 1), operator);
                    stack.push(String.valueOf(result));
                    i++;
                } else {
                    stack.push(expression.get(i));
                }
            }
        }
        return new ArrayList<>(stack);
    }

    public long solution(String expression) {
        List<String> exp = new ArrayList<>(100);
        StringBuilder sb = new StringBuilder();
        for (Character ch : expression.toCharArray()) {
            if (isOperator(ch)) {
                exp.add(sb.toString());
                exp.add(ch.toString());
                sb = new StringBuilder();
            } else {
                sb.append(ch);
            }
        }
        exp.add(sb.toString());

        List<List<Character>> priorities = combination();

        List<Long> result = new ArrayList<>();
        for (List<Character> priority : priorities) {

            List<String> curExpression = new ArrayList<>(exp);
            for (Character operator : priority) {
                curExpression = calculateExpression(curExpression, operator);
            }

            result.add(Math.abs(Long.parseLong(curExpression.get(0))));
        }

        return Collections.max(result);
    }
}