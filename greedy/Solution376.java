class Solution376 {
    public int wiggleMaxLength(int[] nums) {
    	if(nums.length < 2){
    		return nums.length;
    	}
    	int prev = 0;
    	int sum;
    	if(nums[1] < nums[0]){
    		prev = -1;
    		sum = 2;
    	}
    	else if(nums[1] == nums[0]){
    		sum = 1;
    	}
    	else{
    		prev = 1;
    		sum = 2;
    	}
    	int cur = nums[1];
    	for(int i = 2; i < nums.length; i++){
    		if(prev == 1 && nums[i] < cur){
    			sum += 1;
    			prev = -1;
    		}

    		else if(prev == -1 && nums[i] > cur){
    			sum += 1;
    			prev = 1;
    		}

    		else if(prev == 0 && nums[i] != cur){
    			sum += 1;
    			if(nums[i] > cur){
    				prev = 1;
    			}
    			else{
    				prev = -1;
    			}
    		}
    		cur = nums[i];
    	}
    	return sum;
    }

    public static void main(String[] args){
    	Solution376 s = new Solution376();
    	int[] test1 = new int[]{1,7,4,9,2,5};
    	System.out.println(s.wiggleMaxLength(test1));
    	int[] test2 = new int[]{1,17,5,10,13,15,10,5,16,8};
    	System.out.println(s.wiggleMaxLength(test2));
    	int[] test3 = new int[]{1,2,3,4,5,6,7,8,9};
    	System.out.println(s.wiggleMaxLength(test3));
    }
}