import java.util.Queue;
import java.util.PriorityQueue;

import java.util.Comparator;
import java.util.List;
import java.util.LinkedList;



class Solution373 {

	public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
		PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> compare(o2, o1));
		for (int i : nums1) {
			for (int j : nums2) {
				int[] arr = new int[]{i, j};
				if (queue.size() < k) {
					queue.offer(arr);
				} else if (!queue.isEmpty() && compare(queue.peek(), arr) > 0) {
					queue.poll();
					queue.offer(arr);
				}
			}
		}
		LinkedList<List<Integer>> res = new LinkedList<>();
		while (!queue.isEmpty()) {
			int[] poll = queue.poll();
			List<Integer> cur = new LinkedList<>();
			cur.add(poll[0]);
			cur.add(poll[1]);
			res.addFirst(cur);
		}
		return res;
	}

	private int compare(int[] arr1, int[] arr2) {
		return (arr1[0] + arr1[1]) - (arr2[0] + arr2[1]);
	}

	public static void main(String[] args){
		Solution373 s = new Solution373();
		List<List<Integer>> result = s.kSmallestPairs(new int[]{1,7,11}, new int[]{2, 4, 6}, 3);
		for(List<Integer> ele: result){
			for(Integer ele2: ele){
				System.out.println(ele2);
			}

		}
	}
}