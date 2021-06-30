import java.util.Arrays;
import java.util.HashMap;

public class Solution {
    static int answer = 0;
    static HashMap<Character, Integer> map = new HashMap<>();
    static int[] position = new int[8];
    static String[] conditions;

    public int solution(int n, String[] data) {

        // 이거 해줘야 함. 근데 왜
        answer = 0;

        Arrays.fill(position, -1);
        conditions = data;
        map.put('A', 0);
        map.put('C', 1);
        map.put('F', 2);
        map.put('J', 3);
        map.put('M', 4);
        map.put('N', 5);
        map.put('R', 6);
        map.put('T', 7);

        dfs(0);

        return answer;
    }

    public static boolean check() {
        for (String condition : conditions) {
            char a = condition.charAt(0);
            char b = condition.charAt(2);
            char operator = condition.charAt(3);
            int criterion = Character.getNumericValue(condition.charAt(4)) + 1;

            int aPosition = position[map.get(a)];
            int bPosition = position[map.get(b)];
            int distance = Math.abs( bPosition - aPosition);

            switch (operator) {
                case '<':
                    if (distance >= criterion) {
                        return false;
                    }
                    break;
                case '>':
                    if (distance <= criterion) {
                        return false;
                    }
                    break;
                default:
                    if (distance != criterion) {
                        return false;
                    }
            }
        }
        return true;
    }

    public static void dfs(int index) {
        if (index == 8) {
            if (check()) {
                answer++;
            }
            return;
        }

        for (int i = 0; i < 8; i++) {
            if (position[i] == -1) {
                position[i] = index;
                dfs(index + 1);
                position[i] = -1;
            }
        }
    }
}
