class Solution367 {
    public boolean isPerfectSquare(int num) {
    	int number = 1;
    	while(num > 0){
    		num -= number;
    		number += 2;
    	}
    	return num == 0;
    }
}