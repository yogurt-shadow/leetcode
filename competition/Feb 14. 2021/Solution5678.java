import java.util.*;

class Solution5678 {
    private boolean check(int[] nums, int maxOperations, int value){
        int count = 0;
        for(int ele: nums){
            if(ele > value){
                count += (ele - 1) / value;
            }
        }
        return count <= maxOperations;
    }
    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1;
        int right = -1;
        for(int ele: nums){
            right = Math.max(right, ele);
        }
        while(right > left + 1){
            int mid = (left + right) / 2;
            if(check(nums, maxOperations, mid)){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return check(nums, maxOperations, left) ? left : right;
    }
    public static void main(String[] args){
        Solution5678 s = new Solution5678();
        int[] nums = {1};
        System.out.println(s.minimumSize(nums, 1));
    }
}