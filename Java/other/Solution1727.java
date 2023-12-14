import java.util.Arrays;

class Solution1727 {
    public int largestSubmatrix(int[][] matrix) {
    	int[][] heights = new int[matrix.length][matrix[0].length];
    	for(int i = 0; i < heights.length; i++){
    		for(int j = 0; j < heights[0].length; j++){
    			if(i == 0){
    				heights[i][j] = matrix[i][j];
    			}
    			else{
    				heights[i][j] = matrix[i][j] == 1 ? heights[i - 1][j] + 1 : 0;
    			}
    		}
    	}
    	int max = -1;
    	for(int i = 0; i < heights.length; i++){
    		Arrays.sort(heights[i]);
    		for(int j = 0; j < heights[0].length; j++){
    			int area = heights[i][j] * (heights[0].length - j);
    			max = Math.max(max, area);
    		}
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution1727 s = new Solution1727();
    	int[][] test = new int[][]{new int[]{0, 0, 1}, new int[]{1, 1, 1}, new int[]{1, 0, 1}};
    	System.out.println(s.largestSubmatrix(test));
    }
}