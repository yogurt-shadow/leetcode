import java.util.*;

class Solution5675 {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        int n1 = (n + 1) / 2;
        int n2 = n - n1;
        int[] f1 = new int[(1 << n1)];
        int[] f2 = new int[(1 << n2)];
        for(int i = 0; i < (1 << n1); ++i){
            for(int j = 0; j < n1; ++j){
                if(((i >> j) & 1) == 1){
                    f1[i] += nums[j];
                }
            }
        }
        for(int i = 0; i < (1 << n2); ++i){
            for(int j = 0; j < n2; ++j){
                if(((i >> j) & 1) == 1){
                    f2[i] += nums[n1 + j];
                }
            }
        }
        Arrays.sort(f2);
        int min = Integer.MAX_VALUE;
        /**
        for(int i = 0; i < f1.length; ++i){
            int target = goal - f1[i];
            int index = lower_bound(f2, target);
            if(index < f2.length){
                min = Math.min(min, Math.abs(f1[i] + f2[index] - goal));
            }
            if(index - 1 >= 0){
                min = Math.min(min, Math.abs(f1[i] + f2[index - 1] - goal));
            }
        }
        return min;
         }*/
        int index1 = 0;
        int index2 = f2.length - 1;
        Arrays.sort(f1);
        while(index1 < f1.length && index2 >= 0){
            int sum = f1[index1] + f2[index2];
            min = Math.min(min, Math.abs(sum - goal));
            if(min == 0){
                return 0;
            }
            if(sum > goal){
                index2 -= 1;
            }
            else{
                index1 += 1;
            }
        }
            return min;
         }

    public static void main(String[] args){
        Solution5675 s = new Solution5675();
        int[] test = {5, -7, 3, 5};
        System.out.println(s.minAbsDifference(test, 6));
    }
}