class Solution995 {
    public int minKBitFlips(int[] A, int K) {
    	int size = A.length;
    	int count = 0;
    	for(int i = 0; i < size; i++){
    		if(A[i] == 0){
    			if(i + K - 1 >= size){
    				return -1;
    			}
    			for(int j = i; j <= i + K - 1; j++){
    				A[j] = A[j] ^ 1;
    			}
    			count++;
    		}
    	}
    	return count;
    }
}