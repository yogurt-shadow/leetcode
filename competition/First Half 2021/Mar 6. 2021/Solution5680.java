class Solution5680 {
    public int nearestValidPoint(int x, int y, int[][] points) {
    	int res = -1;
    	int max = Integer.MAX_VALUE;
    	for(int i = 0; i < points.length; i++){
    		int[] ele = points[i];
    		if(ele[0] == x || ele[1] == y){
    			int dist = Math.abs(ele[0] - x) + Math.abs(ele[1] - y);
    			if(dist < max){
    				max = dist;
    				res = i;
    			}
    		}
    	}
    	return res;
    }
}