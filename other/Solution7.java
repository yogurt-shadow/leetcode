public class Solution7{
	 public int reverse(int x) {
	 	if(x == 0){
	 		return x;
	 	}
	 	int copy = x;
	 	long result = 0;
	 	while(copy != 0){
	 		result = result * 10;
	 		int digit = copy % 10;
	 		result += digit;
	 		copy = copy / 10;
	 	}
	 	if((int) result == result){
             return (int) result;
         }
         else{
             return 0;
         }
    }
}