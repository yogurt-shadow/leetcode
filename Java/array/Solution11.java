class Solution11 {
    public int maxArea(int[] height) {
    	int result = 0;
    	if(height.length < 2){
    		return result;
    	}
    	for(int i = 0; i < height.length; i++){
    		for(int j = i + 1; j < height.length; j++){
    			int cur = volume(height, i, j);
    			if(cur > result){
    				result = cur;
    			}
    		}
    	}
    	return result;
    }

    private int volume(int[] height, int left, int right){
    	int width = right - left;
    	int length = Math.min(height[left], height[right]);
    	return width * length;
    }

    public static void main(String[] args){
    	Solution11 s = new Solution11();
    	int[] test1 = new int[]{1,8,6,2,5,4,8,3,7};
    	System.out.println(s.maxArea(test1));
    }
}