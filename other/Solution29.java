class Solution29 {
    public int divide(int dividend, int divisor) {
    	return (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -divide2(Math.abs(dividend), Math.abs(divisor)) : divide2(Math.abs(dividend), Math.abs(divisor));
    }

    private int divide2(int x, int y){
    	int result = 0;
    	int cur = y;
    	while(x >= cur){
    		result += 1;
    		cur += y;
    	}
    	return result;
    }

}