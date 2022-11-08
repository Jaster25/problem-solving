class Solution {
    
    static int answer = 0;
    
    static void dfs(int[] numbers, int target, int index, int sum) {
        if (index == numbers.length) {
            if (sum == target) {
                answer += 1;
            }
            return;
        }
        
        dfs(numbers, target, index + 1, sum + numbers[index]);
        dfs(numbers, target, index + 1, sum - numbers[index]);
    }
    
    public int solution(int[] numbers, int target) {
        
        dfs(numbers, target, 0, 0);
                
        return answer;
    }
}