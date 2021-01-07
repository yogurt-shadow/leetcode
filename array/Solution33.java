class Solution33 {
    public int search(int[] nums, int target) {
    	if(nums.length == 1){
    		if(nums[0] == target){
    			return 0;
    		}
    		else{
    			return -1;
    		}
    	}

    	int start = nums[0];
    	int middle = nums[(nums.length - 1)/ 2];
    	int end = nums[nums.length - 1];
    	if(middle >= start){
    		if(target >= start && target <= middle){
    			int[] left = new int[(nums.length - 1)/ 2 + 1];
    			System.arraycopy(nums, 0, left, 0, (nums.length - 1)/ 2 + 1);
    			return search(left, target);
    		}

    		else{
    			int[] right = new int[nums.length - ((nums.length  - 1)/ 2 + 1)];
    			System.arraycopy(nums, (nums.length - 1) / 2 + 1, right, 0, nums.length - ((nums.length  - 1)/ 2 + 1));
                if(search(right, target) == -1){
                    return -1;
                }
    			return (nums.length - 1)/ 2 + 1 + search(right, target);
    		}
    	}

    	else{
    		if(target > middle && target <= end){
    			int[] right = new int[nums.length - ((nums.length  - 1)/ 2 + 1)];
                System.arraycopy(nums, (nums.length - 1) / 2 + 1, right, 0, nums.length - ((nums.length  - 1)/ 2 + 1));
                 if(search(right, target) == -1){
                    return -1;
                }
                return (nums.length - 1)/ 2 + 1 + search(right, target);
    		}

    		else{
    			int[] left = new int[(nums.length - 1)/ 2 + 1];
                System.arraycopy(nums, 0, left, 0, (nums.length - 1)/ 2 + 1);
                return search(left, target);
    		}
    	}
    }

    public static void main(String[] args){
    	Solution33 s = new Solution33();
    	int[] test1 = new int[]{5, 1, 3};
    	System.out.println(s.search(test1, 1));
    }
}