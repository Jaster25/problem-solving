import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Solution {

    static Character grading(double score) {
        if (score >= 90) {
            return 'A';
        } else if (score >= 80) {
            return 'B';
        } else if (score >= 70) {
            return 'C';
        } else if (score >= 50) {
            return 'D';
        } else {
            return 'F';
        }
    }

    public String solution(int[][] scores) {
        StringBuilder answer = new StringBuilder();
        int studentCount = scores.length;

        for (int i = 0; i < studentCount; i++) {
            Map<Integer, Integer> curScores = new HashMap<>();
            int gradingCount = studentCount - 1;

            for (int j = 0; j < studentCount; j++) {
                if (i == j) continue;
                curScores.merge(scores[j][i], 1, Integer::sum);
            }

            int maxKey = Collections.max(curScores.keySet());
            int minKey = Collections.min(curScores.keySet());
            if (minKey <= scores[i][i] && scores[i][i] <= maxKey) {
                gradingCount++;
                curScores.merge(scores[i][i], 1, Integer::sum);
            }

            int totalScore = 0;
            for (Integer score : curScores.keySet()) {
                totalScore += score * curScores.get(score);
            }
            double aver = totalScore /= gradingCount;
            answer.append(grading(aver));
        }

        return answer.toString();
    }
}