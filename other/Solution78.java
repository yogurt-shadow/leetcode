package other;
import java.util.List;
import java.util.LinkedList;


public class Solution78{

	private List<Integer> connect(List<Integer> list, int current){
		List<Integer> result = new LinkedList<>();
		for(Integer ele: list){
			result.add(ele);
		}

		result.add(current);
		return result;
	}

	public List<List<Integer>> subsets(int[] nums) {
		if(nums.length == 0){
			List<Integer> list = new LinkedList<>();
			List<List<Integer>> result = new LinkedList<>();
			result.add(list);
			return result;
		}
		else{

			List<List<Integer>> result = new LinkedList<>();
			int[] copy = new int[nums.length - 1];
			System.arraycopy(nums, 0, copy, 0, nums.length - 1);

			for(List<Integer> previous: subsets(copy)){
				result.add(previous);
				result.add(connect(previous, nums[nums.length - 1]));
			}

			return result;
		}



    }
	public static void main(String[] args){
		int[] input = new int[]{1, 2, 3};
		Solution78 s = new Solution78();
		for(List<Integer> list: s.subsets(input)){
			for(Integer ele: list){
				System.out.print(" " + ele + " ");
			}
			System.out.println();
		}
	}
}