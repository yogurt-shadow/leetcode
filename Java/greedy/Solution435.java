import java.util.Comparator;
import java.util.Arrays;

class Solution435 {
    public int eraseOverlapIntervals(int[][] intervals) {
    	if(intervals.length == 0){
    		return 0;
    	}
    	Comparator<int[]> cmp = (x, y) -> x[1] - y[1];
    	Arrays.sort(intervals, cmp);
    	int right = intervals[0][1];
    	int no_cover = 1;
    	for(int i = 1; i < intervals.length; i++){
    		if(intervals[i][0] >= right){
    			no_cover += 1;
    			right = intervals[i][1];
    		}
    	}
    	return intervals.length - no_cover;
    }

    public static void main(String[] args){
    	Solution435 s = new Solution435();
    	int[][] test1 = new int[][]{new int[]{1, 2}, new int[]{2, 3}, new int[]{3, 4}, new int[]{1, 3}};
    	System.out.println(s.eraseOverlapIntervals(test1));
    }
}