class Solution84 {
    public int largestRectangleArea(int[] heights) {
    	int area = 0;
    	for(int i = 0; i < heights.length; i++){
    		for(int value = 1; value <= heights[i]; value++){
    			int left = 1;
    			while(i - left >= 0 && heights[i - left] >= value){
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
}