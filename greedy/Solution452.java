import java.util.Arrays;
import java.util.Comparator;

class Solution452 {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0){
            return 0;
        }
        Comparator<int[]> cmp = (x, y) -> x[0] < y[0] ? -1 : 1;
        Arrays.sort(points, cmp);
        int arrow = 1;
        int left = points[0][0];
        int right = points[0][1];
        for(int[] balloon: points){
            if(balloon[0] > right){
                arrow += 1;
                left = balloon[0];
                right = balloon[1];
            }
            else{
                left = Math.max(left, balloon[0]);
                right = Math.min(right, balloon[1]);
            }
        }
        return arrow;
    }

    public static void main(String[] args){
    	Solution452 s = new Solution452();
    	int[][] test1 = new int[][]{new int[]{10, 16}, new int[]{2, 8}, new int[]{1, 6}, new int[]{7, 12}};
    	System.out.println(s.findMinArrowShots(test1));
    }
}