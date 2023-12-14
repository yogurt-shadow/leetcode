class Solution57 {
    public int[][] insert(int[][] intervals, int[] newInterval) {
    	if(intervals.length == 0){
    		return new int[][]{newInterval};
    	}
    	int[][] result = new int[intervals.length + 1][2];
    	int index = 0;
    	int left = newInterval[0];
    	int right = newInterval[1];
    	boolean done = false;
    	

    	for(int i = 0; i < intervals.length; i++){
    		if(intervals[i][1] < left){
    			result[index] = intervals[i];
    			index += 1;
    		}
    		else if(intervals[i][0] > right){
    			if(!done){
    				result[index] = new int[]{left, right};
    				index += 1;
    				done = true;
    			}
    			result[index] = intervals[i];
    			index += 1;
    		}
    		else{
    			
    			left = Math.min(left, intervals[i][0]);
    			right = Math.max(right, intervals[i][1]);
    		}
    	}
    	if(!done){
    		result[index] = new int[]{left, right};
    		index += 1;
    	}
    	int[][] copy = new int[index][2];
    	System.arraycopy(result, 0, copy, 0, index);
    	return copy;
    }

    public static void main(String[] args){
    	Solution57 s = new Solution57();
    	int[][] test = {{1, 5}};
    	int[] intervals = {6, 8};
    	int[][] result = s.insert(test, intervals);
    }
}