import java.util.List;
import java.util.LinkedList;

class Bag01{
	/**
	* Backtracking
	public int maxValue1(int v, int[] weight, int[] value){
		List<List<Integer>> result = new LinkedList<>();
		List<Integer> list = new LinkedList<>();
		put(result, list, v, weight, 1, 0);
		int max_value = -1;
		for(List<Integer> ele: result){
			int cost = 0;
			for(Integer ele2: ele){
				cost += value[ele2 - 1];
			}
			max_value = Math.max(max_value, cost);
		}
		return max_value;
	}

	private void put(List<List<Integer>> result, List<Integer> list, int volume, int[] weight, int cur, int cur_weight){
		if(cur == weight.length){
			result.add(new LinkedList<>(list));
			if(cur_weight + weight[cur - 1] <= volume){
				list.add(cur);
				result.add(new LinkedList<>(list));
				list.remove(list.size() - 1);
			}
			return;
		}
		put(result, list, volume, weight, cur + 1, cur_weight);
		if(cur_weight + weight[cur - 1] <= volume){
			list.add(cur);
			put(result, list, volume, weight, cur + 1, cur_weight + weight[cur - 1]);
			list.remove(list.size() - 1);
		}
	}
	*/


	public int maxValue2(int v, int[] weight, int[] value){
		int number = weight.length;
		int[][] dp = new int[number][v + 1];
		for(int j = v; j >= weight[0]; j--){
			dp[0][j] = value[0];
		}
		for(int i = 1; i < number; i++){
			for(int j = 0; j <= v; j++){
				dp[i][j] = j >= weight[i] ? Math.max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]) : dp[i - 1][j];
			}
		}
		return dp[number - 1][v];
	}

	public static void main(String[] args){
		Bag01 bag = new Bag01();
		int[] weight = {1, 3, 4};
		int[] value = {15, 20, 30};
		System.out.println(bag.maxValue2(4, weight, value));
	}
}
