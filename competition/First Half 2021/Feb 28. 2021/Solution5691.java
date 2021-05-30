import java.util.Arrays;

class Solution5691 {
    public int minOperations(int[] nums1, int[] nums2) {
    	int sum1 = 0, sum2 = 0;
    	Arrays.sort(nums1);
    	Arrays.sort(nums2);
    	for(int ele: nums1){
    		sum1 += ele;
    	}
    	for(int ele: nums2){
    		sum2 += ele;
    	}
    	if(sum1 == sum2){
    		return 0;
    	}
    	int res = 0;
		int diff = sum1 - sum2;
    	if(sum1 < sum2) {
			int[] copy = nums1;
			nums1 = nums2;
			nums2 = copy;
			diff = -diff;
		}
    		int index1 = nums1.length - 1;
    		int index2 = 0;
    		while(diff > 0){
    			while(index1 >= 0 || index2 < nums2.length){
    				if(index1 < 0 || nums1[index1] == 1){
    					if(index2 >= nums2.length || nums2[index2] == 6){
    						return -1;
    					}
    					else{
    						if(diff <= 6 - nums2[index2]){
    							diff = 0;
    							res++;
    							return res;
    						}
    						
    						diff -= (6 - nums2[index2]);
    						nums2[index2] = 6;
    						res++;
    						index2++;
    					}
    				}
    				else if(index2 >= nums2.length || nums2[index2] == 6){
    					if(index1 < 0 || nums1[index1] == 1){
    						return -1;
    					}
    					else{
    						if(diff <= nums1[index1] - 1){
    							diff = 0;
    							res++;
    							return res;
    						}
    						
    						diff -= (nums1[index1] - 1);
    						nums1[index1] = 1;
    						index1--;
    						res++;
    					}
    				}
    				else{
    					int diff1 = nums1[index1] - 1;
    					int diff2 = 6 - nums2[index2];
    					if(diff1 >= diff){
    						diff -= (6 - nums2[index2]);
    						nums2[index2] = 6;
    						res++;
    						return res;
    					}
    					else if(diff2 >= diff){
    						diff -= (nums1[index1] - 1);
    						nums1[index1] = 1;
    						res++;
    						return res;
    					}
    					else{
    						if(diff1 > diff2){
	    						diff -= (nums1[index1] - 1);
	    						nums1[index1] = 1;
	    						res++;
	    						index1--;
    						}
    						else{
    							diff -= (6 - nums2[index2]);
    							nums2[index2] = 6;
    							index2++;
    							res++;
    						}
    					}
    				}
    			}
    		}
    	return res;
    }

    public static void main(String[] args){
        Solution5691 s = new Solution5691();
        int[] test1 = {2,2,4,3,1,1,5,2,5,2,5,6,1,1,6,4,5,2,5,3};
        int[] test2 = {3,3,4};
        System.out.println(s.minOperations(test1, test2));
    }
}