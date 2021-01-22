class Solution88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    	int[] copy = new int[m];
    	System.arraycopy(nums1, 0, copy, 0, m);
    	int index1 = 0;
    	int index2 = 0;
    	int index = 0;
    	while(index1 < copy.length || index2 < nums2.length){
    		if(index1 >= copy.length){
    			nums1[index] = nums2[index2];
    			index2 += 1;
    			
    		}
    		else if(index2 >= nums2.length){
    			nums1[index] = copy[index1];
    			index1 += 1;
    			
    		}
    		else{
    			if(copy[index1] < nums2[index2]){
    				nums1[index] = copy[index1];
    				index1 += 1;
       			}
       			else{
       				nums1[index] = nums2[index2];
       				index2 += 1;
       			}
    		}
    		index += 1;
    	}
    }

    public static void main(String[] args){
    	Solution88 s = new Solution88();
    	int[] test1 = new int[]{1, 2, 3, 0, 0, 0};
    	int[] test2 = new int[]{2, 5, 6};
    	s.merge(test1, 3, test2, 3);
    	for(int ele: test1){
    		System.out.print(ele + " ");
    	}
    }
}