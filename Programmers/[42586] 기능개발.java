import java.util.*;

class Solution {
  public int[] solution(int[] progresses, int[] speeds) {
      List<Integer> answer = new ArrayList<Integer>();
      Queue<Integer> requiredDays = new LinkedList<Integer>();

      for (int i = 0; i < progresses.length; i++) {
          requiredDays.add((int) Math.ceil((double) (100 - progresses[i]) / speeds[i]));
      }

      while (!requiredDays.isEmpty()) {
          int completedWorkCnt = 1;
          int currentDay = requiredDays.poll();

          while (!requiredDays.isEmpty() && currentDay >= requiredDays.peek()) {
              completedWorkCnt++;
              requiredDays.poll();
          }

          answer.add(completedWorkCnt);
      }

      int[] answerToIntArray = new int[answer.size()];
      for (int i = 0; i < answer.size(); i++) {
          answerToIntArray[i] = answer.get(i);
      }

      return answerToIntArray;
  }
}