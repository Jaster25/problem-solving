package wk12;

class Solution {

    static int maxCount = -987654321;
    static int[][] dungeons;
    static int dungeonCount;
    static boolean[] isVisited;


    // 탐험한 던전 수, 현재 피로도
    static void dfs(int count, int current) {
        maxCount = Math.max(count, maxCount);
        if (current < 1) {
            return;
        }

        for (int i = 0; i < dungeonCount; i++) {
            if (!isVisited[i] && current >= dungeons[i][0]) {
                isVisited[i] = true;
                dfs(count + 1, current - dungeons[i][1]);
                isVisited[i] = false;
            }
        }
    }

    public int solution(int k, int[][] dungeons_) {
        dungeons = dungeons_;
        dungeonCount = dungeons_.length;
        isVisited = new boolean[dungeonCount];

        dfs(0, k);

        return maxCount;
    }
}