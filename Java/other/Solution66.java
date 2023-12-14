class Solution66 {
    public int[] plusOne(int[] digits) {
    	if(digits.length == 1 && digits[0] == 9){
    		return new int[]{1, 0};
    	}

    	if(digits[digits.length - 1] < 9){
    		int[] result = new int[digits.length];
    		System.arraycopy(digits, 0, result, 0, digits.length);
    		result[result.length - 1] += 1;
    		return result;
    	}

    	int[] input = new int[digits.length - 1];
    	System.arraycopy(digits, 0, input, 0, digits.length - 1);
    	int[] output = plusOne(input);
    	int[] result = new int[output.length + 1];
    	System.arraycopy(output, 0, result, 0, output.length);
    	result[result.length - 1] = 0;
    	return result;
    }

    public static void main(String[] args){
    	Solution66 s = new Solution66();
    	int[] test1 = new int[]{1, 2, 3};
    	int[] test11 = s.plusOne(test1);
    	for(int ele: test11){
    		System.out.print(ele + " ");
    	}
    	System.out.println();
    	int[] test2 = new int[]{9, 9, 9, 9};
    	int[] test21 = s.plusOne(test2);
    	for(int ele: test21){
    		System.out.print(ele + " ");
    	}
    }
}