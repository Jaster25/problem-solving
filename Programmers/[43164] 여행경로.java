import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {

    static List<String> answer = new ArrayList<>();
    static boolean[] visited;
    static String path = "";

    static void dfs(String[][] tickets, String destination, int visitCount) {
        path += destination + ",";

        if (visitCount == tickets.length) {
            answer.add(path);
            return;
        }

        for (int i = 0; i < tickets.length; i++) {
            String from = tickets[i][0];
            String to = tickets[i][1];
            if (from.equals(destination) && !visited[i]) {
                visited[i] = true;
                dfs(tickets, to, visitCount + 1);
                path = path.substring(0, path.length() - 4);
                visited[i] = false;
            }
        }
    }

    public String[] solution(String[][] tickets) {
        for (int i = 0; i < tickets.length; i++) {
            visited = new boolean[tickets.length];
            String from = tickets[i][0];
            String to = tickets[i][1];
            if (from.equals("ICN")) {
                path = "ICN,";
                visited[i] = true;
                dfs(tickets, to, 1);
            }
        }

        Collections.sort(answer);
        return answer.get(0).split(",");
    }
}
