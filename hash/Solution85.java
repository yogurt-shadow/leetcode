class Solution85 {
    public int maximalRectangle(char[][] matrix) {
    	if(matrix.length == 0){
    		return 0;
		}
    	int[][] height = new int[matrix.length][matrix[0].length];
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(i == 0){
                    height[i][j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j] == '0'){
                        height[i][j] = 0;
                    }
                    else{
                        height[i][j] = height[i - 1][j] + 1;
                    }
                }
            }
        }
        int area = 0;
        for(int k = 0; k < matrix.length; k++){
           int cur = area_line(height[k]);
           if(cur > area){
            area = cur;
           }
        }
        return area;
    }

    private int area_line(int[] nums){
    	int area = 0;
    	for(int i = 0; i < nums.length; i++){
    		for(int value = 1; value <= nums[i]; value++){
    			int left = 1;
    			while(i - left >= 0 && nums[i - left] >= value){
    				left += 1;
    			}
    			int cur_area = left * value;
    			if(cur_area > area){
    				area = cur_area;
    			}
    		}
    	}
    	return area;
    }

    public static void main(String[] args){
    	Solution85 s = new Solution85();
    	char[][] test = new char[][]{new char[]{'1','0','1','0','0'},new char[]{'1','0','1','1','1'}, new char[]{'1','1','1','1','1'}, new char[]{'1','0','0','1','0'}};
        System.out.println(s.maximalRectangle(test));
    }
}