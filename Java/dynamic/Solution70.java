class Solution70 {
    public int climbStairs(int n) {
    	if(n <= 2){
    		return n;
    	}
    	int first = 1;
    	int last = 2;
    	for(int i = 3; i < n; i++){
    		int cur = first + last;
    		first = last;
    		last = cur;
    	}
    	return first + last;
    }
}