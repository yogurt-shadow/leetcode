class Solution496 {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    	int[] result = new int[nums1.length];
    	for(int i = 0; i < nums1.length; i++){
    		result[i] = find_larger(nums2, nums1[i]);
    	}
    	return result;
    }

    private int find_larger(int[] source, int x){
    	int index = find(source, x);
    	for(int i = index + 1; i < source.length; i++){
    		if(source[i] > x){
    			return source[i];
    		}
    	}

    	return -1;

    }

    private int find(int[] source, int x){
    	for(int i = 0; i < source.length; i++){
    		if(source[i] == x){
    			return i;
    		}
    	}
    	return -1;
    }

    public static void main(String[] args){
    	Solution496 s = new Solution496();
    	int[] test11 = new int[]{4, 1, 2};
    	int[] test12 = new int[]{1, 3, 4, 2};


    	int[] test21 = new int[]{2, 4};
    	int[] test22 = new int[]{1, 2, 3, 4};

    	int[] test1 = s.nextGreaterElement(test11, test12);
    	int[] test2 = s.nextGreaterElement(test21, test22);

    	for(int i = 0; i < test1.length; i++){
    		System.out.println(test1[i]);
    	}

    	for(int i = 0; i < test2.length; i++){
    		System.out.println(test2[i]);
    	}

    }
}