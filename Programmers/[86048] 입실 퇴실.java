package wk7;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

class Solution {

    public int[] solution(int[] enter, int[] leave) {
        Queue<Integer> leaveQueue = new LinkedList<>();
        for (int number : leave) {
            leaveQueue.offer(number);
        }

        Node[] nodes = new Node[enter.length + 1];
        for (int i = 1; i <= enter.length; i++) {
            nodes[i] = new Node(i);
        }

        Set<Node> room = new HashSet<>(1000);
        for (int i : enter) {
            Node enterNode = nodes[i];

            enterNode.meetCount = room.size();
            for (Node node : room) {
                node.meetCount++;
            }

            room.add(enterNode);

            while (!leaveQueue.isEmpty()) {
                Node peek = nodes[leaveQueue.peek()];
                if (room.contains(peek)) {
                    room.remove(peek);
                    leaveQueue.poll();
                } else {
                    break;
                }
            }
        }

        int[] answer = new int[enter.length];
        for (int i = 1; i <= enter.length; i++) {
            answer[i - 1] = nodes[i].meetCount;
        }
        return answer;
    }

    static class Node {
        int index;
        int meetCount;

        public Node(int index) {
            this.index = index;
            this.meetCount = 0;
        }
    }
}