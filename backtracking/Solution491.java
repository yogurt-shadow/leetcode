import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;
import java.util.Set;

class Solution491 {
   public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> result = new LinkedList<>();
        List<Integer> path = new LinkedList<>();
        put(nums, result, path, 0);
        return result;
    }

    private void put(int[] nums, List<List<Integer>> result, List<Integer> path, int index){
        Set<Integer> set = new HashSet<>();
        for(int i = index; i < nums.length; i++){
            if((path.size() >= 1 && path.get(path.size() - 1) > nums[i]) || set.contains(nums[i])){
                continue;
            }
            path.add(nums[i]);
            set.add(nums[i]);
            if(path.size() >= 2){
                List<Integer> copy = new LinkedList<>(path);
                result.add(copy);
            }
            if(i < nums.length - 1){
                put(nums, result, path, i + 1);
            }
            path.remove(path.size() - 1);
        }
    }


    public static void main(String[] args){
        Solution491 s = new Solution491();
        int[] test1 = new int[]{4, 3, 2, 1};
        List<List<Integer>> result = s.findSubsequences(test1);
    }
}