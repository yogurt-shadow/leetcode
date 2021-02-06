class Solution1423 {
    public int maxScore(int[] cardPoints, int k) {
    	int length = cardPoints.length;
    	if(length <= k){
    		int sum = 0;
    		for(int ele: cardPoints){
    			sum += ele;
    		}
    		return sum;
    	}
    	int[] cardPoints2 = new int[length * 2];
    	System.arraycopy(cardPoints, 0, cardPoints2, 0, length);
    	System.arraycopy(cardPoints, 0, cardPoints2, length, length);
    	int sum = 0;
    	int left = length;
    	int right = left + k - 1;
    	for(int i = left; i <= right; i++){
    		sum += cardPoints2[i];
    	}
    	int max = sum;
    	while(right >= length){
    		left -= 1;
    		sum += cardPoints2[left];
    		sum -= cardPoints2[right];
    		right -= 1;
    		max = Math.max(max, sum);
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution1423 s = new Solution1423();
    	int[] test = {1,2,3,4,5,6,1};
    	System.out.println(s.maxScore(test, 3));
    }
}