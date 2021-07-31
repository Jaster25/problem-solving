package boj1541;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String expression = br.readLine();
        br.close();

        List<Integer> operands = Arrays
                .stream(expression.split("[+\\-]"))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        List<Character> operators = new ArrayList<>();
        for (char c : expression.toCharArray()) {
            if (c == '+' || c == '-') {
                operators.add(c);
            }
        }

        while (operators.contains('+')) {
            int index = operators.indexOf('+');
            operands.set(index, operands.get(index) + operands.get(index + 1));

            operands.remove(index + 1);
            operators.remove(index);
        }

        while (!operators.isEmpty()) {
            operands.set(0, operands.get(0) - operands.get(1));
            operands.remove(1);
            operators.remove(0);
        }

        System.out.println(operands.get(0));
    }
}
