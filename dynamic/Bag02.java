class Bag02{
	public int maxValueOneD(int volume, int[] weight, int[] value){
		int number = weight.length;
		int[] dp = new int[volume + 1];
		for(int j = volume; j >= weight[0]; j--){
			dp[j] = value[0];
		}
		for(int i = 1; i < number; i++){
			for(int j = volume; j >= weight[i]; j--){
				dp[j] = Math.max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		return dp[volume];
	}

	public static void main(String[] args){
		Bag02 bag = new Bag02();
		int[] weight = {1, 3, 4};
		int[] value = {15, 20, 30};
		System.out.println(bag.maxValueOneD(4, weight, value));
	}
}