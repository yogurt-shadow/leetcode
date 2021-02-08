import java.util.*;

class Solution5660 {
    public int maxValue(int[][] events, int k) {
    	int n = events.length;
        Comparator<int[]> cmp = (x, y) -> x[1] - y[1];
        Arrays.sort(events, cmp);
        int[][] dp = new int[n][k + 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k + 1; j++){
                dp[i][j] = Integer.MIN_VALUE;
            }
        }
        dp[0][0] = 0;
        dp[0][1] = events[0][2];

        for(int i = 1; i < n; i++){
            int l = 0, r = i;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(events[mid][1] >= events[i][0]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            if(events[l][1] < events[i][0]){
                for(int j = 1; j <= k; j++){
                    dp[i][j] = Math.max(dp[i][j], dp[l][j - 1] + events[i][2]);
                }
            }
            else{
                dp[i][1] = Math.max(dp[i][1], events[i][2]);
            }

            for(int j = 0; j <= k; j++){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            }
        }
        int min = 0;
        for(int i = 0; i <= k; i++){
            min = Math.max(min, dp[n - 1][i]);
        }
        return min;
    }
}