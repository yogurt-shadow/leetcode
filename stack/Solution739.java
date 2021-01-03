class Solution739 {
    public int[] dailyTemperatures(int[] T) {
    	int[] result = new int[T.length];
    loop1: for(int i = 0; i < T.length; i++){
    		int cur = T[i];
    		for(int j = i + 1; j < T.length; j++){
    			if(T[j] > cur){
    				result[i] = j - i;
    				continue loop1;
    			}
    		}
    		result[i] = 0;
    	}
    	return result;
    }

    public static void main(String[] args){
    	int[] test = new int[]{73, 74, 75, 71, 69, 72, 76, 73};
    	Solution739 s = new Solution739();
    	int[] output = s.dailyTemperatures(test);
    	for(int i = 0; i < output.length; i++){
    		System.out.println(output[i]);
    	}
    }
}