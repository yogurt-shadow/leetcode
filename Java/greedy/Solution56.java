import java.util.Arrays;
import java.util.Comparator;

class Solution56 {
    public int[][] merge(int[][] intervals) {
    	Comparator<int[]> cmp = (x, y) -> x[0] - y[0];
    	Arrays.sort(intervals, cmp);
    	int[][] result = new int[intervals.length][2];
    	int index = 0;
    	int left = intervals[0][0];
    	int right = intervals[0][1];
    	for(int i = 1; i < intervals.length; i++){
    		if(intervals[i][0] > right){
    			result[index] = new int[]{left, right};
    			index += 1;
    			left = intervals[i][0];
    			right = intervals[i][1];
    		}
    		else{
    			right = Math.max(right, intervals[i][1]);
    		}
    	}
    	result[index] = new int[]{left, right};
    	index += 1;
    	int[][] result2 = new int[index][2];
    	System.arraycopy(result, 0, result2, 0, index);
    	return result2;
    }

    public static void main(String[] args){
    	Solution56 s = new Solution56();
    	int[][] test1 = new int[][]{new int[]{1, 3}, new int[]{2, 6}, new int[]{8, 10}, new int[]{15, 18}};
    	int[][] result1 = s.merge(test1);
    }
}