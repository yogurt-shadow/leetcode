class Solution1105 {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int len = books.length;
        int[] dp = new int[len + 1];
        for(int i = 0; i < len; i++){
            dp[i] = Integer.MAX_VALUE;
        }
        for(int i = len - 1; i >= 0; i--){
            int width = 0, height = 0;
            for(int j = i; j < len && width + books[j][0] <= shelfWidth; j++){
                height = Math.max(height, books[j][1]);
                dp[i] = Math.min(dp[i], dp[j + 1] + height);
                width += books[j][0];
            }
        }
        return dp[0];
    }
}