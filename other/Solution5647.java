class Solution5647 {
    public int[] decode(int[] encoded) {
    	int total = 1;
    	for(int i = 2; i <= encoded.length + 1; i++){
    		total = total ^ i;
    	}
    	int cur = encoded[0];
    	int index = 2;
    	while(index < encoded.length){
    		cur = cur ^ encoded[index];
    		index += 2;
    	}
    	cur = cur ^ encoded[encoded.length - 1];
    	int last_two = cur ^ total;
    	int last = encoded[encoded.length - 1] ^ last_two;
    	int[] result = new int[encoded.length + 1];
    	result[result.length - 1] = last;
    	result[result.length - 2] = last_two;
    	for(int i = result.length - 3; i >= 0; i--){
    		result[i] = result[i + 1] ^ encoded[i];
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution5647 s = new Solution5647();
    	int[] test1 = new int[]{3, 1};
    	int[] result1 = s.decode(test1);
    	for(int ele: result1){
    		System.out.print(ele + " ");
    	}
    }
}