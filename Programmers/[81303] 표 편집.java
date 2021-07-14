package pg81303;

import java.util.Stack;

class Solution {
    static Node initialList(int n, int k) {
        Node curNode = new Node(-1); // head

        Node newNode;
        for (int i = 0; i < n; i++) {
            newNode = new Node(i);
            curNode.down = newNode;
            newNode.up = curNode;
            curNode = newNode;
        }

        newNode = new Node(-1); // tail
        curNode.down = newNode;
        newNode.up = curNode;

        while (curNode.index != k) {
            curNode = curNode.up;
        }
        return curNode;
    }

    public String solution(int n, int k, String[] cmd) {
        Node curNode = initialList(n, k);
        Stack<Node> stack = new Stack<>();
        int number;

        for (String s : cmd) {
            switch (s.charAt(0)) {
                case 'U':
                    number = Integer.parseInt(s.substring(2));
                    for (int i = 0; i < number; i++) {
                        curNode = curNode.up;
                    }
                    break;
                case 'D':
                    number = Integer.parseInt(s.substring(2));
                    for (int i = 0; i < number; i++) {
                        curNode = curNode.down;
                    }
                    break;
                case 'C':
                    stack.add(curNode);
                    curNode.remove();
                    if (curNode.canMoveDown()) {
                        curNode = curNode.down;
                    } else {
                        curNode = curNode.up;
                    }
                    break;
                case 'Z':
                    stack.pop().restore();
                    break;
            }
        }

        StringBuilder answer = new StringBuilder("O".repeat(n));
        while (!stack.isEmpty()) {
            answer.setCharAt(stack.pop().index, 'X');
        }
        return answer.toString();
    }

    static class Node {
        int index;
        Node up, down;

        public Node(int index) {
            this.index = index;
        }

        boolean canMoveDown() {
            return down.index != -1;
        }

        void remove() {
            up.down = down;
            down.up = up;
        }

        void restore() {
            up.down = this;
            down.up = this;
        }
    }
}