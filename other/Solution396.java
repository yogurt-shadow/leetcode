class Solution396 {
    public int maxRotateFunction(int[] A) {
    	int sum = 0;
    	for(int ele: A){
    		sum += ele;
    	}
    	int max = 0;
    	for(int i = 0; i < A.length; i++){
    		max += i * A[i];
    	}
    	int last = max;
    	for(int i = 1; i < A.length; i++){
    		int position = A.length - i;
    		int cur = last + sum - A.length * A[position];
    		max = Math.max(max, cur);
    		last = cur;
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution396 s = new Solution396();
    	int[] test1 = new int[]{4, 3, 2, 6};
    	System.out.println(s.maxRotateFunction(test1));
    }
}