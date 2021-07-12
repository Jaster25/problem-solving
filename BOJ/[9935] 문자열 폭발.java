package boj9935;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String bombStr = br.readLine();
        br.close();

        int bombLen = bombStr.length();
        char lastCharOfBomb = bombStr.charAt(bombLen - 1);

        Stack<Character> stack = new Stack<>();
        for (char c : str.toCharArray()) {
            stack.add(c);

            if (stack.size() >= bombLen && c == lastCharOfBomb) {
                Stack<Character> temp = new Stack<>();
                boolean isSameWord = true;
                for (int i = 0; i < bombLen; i++) {
                    char popped = stack.pop();
                    temp.add(popped);
                    if (popped != bombStr.charAt(bombLen - 1 - i)) {
                        isSameWord = false;
                        break;
                    }
                }

                if (!isSameWord) {
                    while (!temp.isEmpty()) {
                        stack.add(temp.pop());
                    }
                }
            }
        }

        if (stack.isEmpty()) {
            System.out.println("FRULA");
        } else {
            StringBuilder sb = new StringBuilder();
            stack.forEach(sb::append);
            System.out.println(sb);
        }
    }
}
