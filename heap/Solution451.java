import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashSet;
import java.util.Comparator;

class Solution451 {
    public String frequencySort(String s) {
    	int[] freq = new int[127];
    	Set<Character> set = new HashSet<>();
    	Comparator<Character> cmp = new Comparator<>(){
    		public int compare(Character x, Character y){
    			return freq[y] - freq[x];
    		}
    	};

    	Queue<Character> pq = new PriorityQueue<>(cmp);

    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(set.contains(cur)){
    			freq[cur] += 1;
    			pq.remove(cur);
    			pq.add(cur);
    		}
    		else{
    			freq[cur] = 1;
    			set.add(cur);
    			pq.add(cur);
    		}
    	}

    	StringBuilder str = new StringBuilder();
    	while(pq.size() > 0){
    		char cur = pq.poll();
    		for(int i = 0; i < freq[cur]; i++){
    			str.append(String.valueOf(cur));
    		}
    	}

    	return str.toString();
    }



    public static void main(String[] args){
    	Solution451 s = new Solution451();
    	System.out.println(s.frequencySort("tree"));
    	System.out.println(s.frequencySort("cccaaa"));
    	System.out.println(s.frequencySort("Aabb"));
    }
}