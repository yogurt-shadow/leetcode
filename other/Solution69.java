class Solution69 {
    public int mySqrt(int x) {
    	long result = 0;
    	while(x >= result * result){
    		result += 1;
    	}
    	return (int) result - 1;
    }

    public static void main(String[] args){
    	Solution69 s = new Solution69();
    	System.out.println(s.mySqrt(2147395600));
    }
}