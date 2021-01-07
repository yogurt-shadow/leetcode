class Solution34 {
    public int[] searchRange(int[] nums, int target) {
    	if(nums.length == 0){
    		return new int[]{-1, -1};
    	}

    	if(nums.length == 1){
    		if(nums[0] == target){
    			return new int[]{0, 0};
    		}
    		else{
    			return new int[]{-1, -1};
    		}
    	}

    	
    	int middle = (nums.length - 1) / 2;
    	if(nums[middle] == target){
    		int left = 1;
    		while(middle - left >= 0 && nums[middle - left] == target){
    			left += 1;
    		}

    		int right = 1;
    		while(middle + right < nums.length && nums[middle + right] == target){
    			right += 1;
    		}
    		return new int[]{middle - (left - 1), middle + (right - 1)};
    	}

    	else if(target > nums[middle]){
    		int[] right = new int[nums.length - 1 - middle];
    		System.arraycopy(nums, middle + 1, right, 0, nums.length - 1 - middle);
    		int[] next = searchRange(right, target);
    		if(next[0] == -1){
    			return next;
    		}

    		else{
    			return new int[]{next[0] + middle + 1, next[1] + middle + 1};
    		}
    	}

    	else{
    		int[] left = new int[middle];
    		System.arraycopy(nums, 0, left, 0, middle);
    		return searchRange(left, target);
    	}
    }

    public static void main(String[] args){
    	Solution34 s = new Solution34();
    	int[] test1 = new int[]{5,7,7,8,8,10};
    	int[] output1 = s.searchRange(test1, 6);
    	System.out.println(output1[0] + " " + output1[1]);
    }
}