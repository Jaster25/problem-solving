import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Integer> stack = new Stack<Integer>();
        int k = scanner.nextInt();

        for (int i = 0; i < k; i++) {
            int num = scanner.nextInt();
            if (num == 0) {
                stack.pop();
            } else {
                stack.add(num);
            }
        }
        scanner.close();

        int totalNum = 0;
        while (!stack.isEmpty()) {
            totalNum += stack.pop();
        }

        System.out.println(totalNum);
    }
}