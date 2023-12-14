class Solution135 {
    public int candy(int[] ratings) {
    	int[] candies = new int[ratings.length];
        candies[0] = 1;
        for(int i = 1; i < ratings.length; i++){
            candies[i] = ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : 1;
        }
        for(int i = candies.length - 2; i >= 0; i--){
           if(ratings[i] > ratings[i + 1]){
            candies[i] = Math.max(candies[i], candies[i + 1] + 1);
           }
        }
        int sum = 0;
        for(int ele: candies){
            sum += ele;
        }
        return sum;
    }

    public static void main(String[] args){
    	Solution135 s = new Solution135();
    	int[] test1 = new int[]{1, 3, 2, 2, 1};
    	System.out.println(s.candy(test1));
    }
}