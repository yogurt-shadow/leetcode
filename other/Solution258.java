class Solution258 {
    public int addDigits(int num) {
    	int sum = 0;
    	while(num != 0){
    		sum += num % 10;
    		num = num / 10;
    	}
    	if(sum < 10){
    		return sum;
    	}
    	return addDigits(sum);
    }
}