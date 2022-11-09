import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        
        Map<String, Integer> map = new HashMap<>();
        
        for (String name : participant) {
            map.put(name, map.getOrDefault(name, 0) + 1);
        }
        
        for (String name : completion) {
            if (map.get(name) > 1) {
                map.put(name, map.get(name) - 1);
            } else {
                map.remove(name);
            }
        }
        
        String answer = "";
        for (String name : map.keySet()) {
            answer = name;
        }
        return answer;
    }
}