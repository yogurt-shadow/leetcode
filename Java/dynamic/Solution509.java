class Solution509 {
    public int fib(int n) {
    	if(n <= 1){
    		return n;
    	}
    	int last1 = 0;
    	int last2 = 1;
    	for(int i = 2; i < n; i++){
    		int cur = last1 + last2;
    		last1 = last2;
    		last2 = cur;
    	}
    	return last1 + last2;
    }
}