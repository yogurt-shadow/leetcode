import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

class Solution621 {
    public int leastInterval(char[] tasks, int n) {
    	Map<Character, Integer> freq = new HashMap<>();
    	Map<Character, Integer> last = new HashMap<>();
    	for(Character ele: tasks){
    		if(!freq.containsKey(ele)){
    			freq.put(ele, 1);
    		}
    		else{
    			freq.put(ele, freq.get(ele) + 1);
    		}
    		if(!last.containsKey(ele)){
    			last.put(ele, -(n + 1));
    		}
    	}

    	int finished = 0;
    	int time = 0;
    	while(finished < tasks.length){
    		Set<Character> set = new HashSet<>();
    		for(Character ele: last.keySet()){
    			if(!set.contains(ele) && time - last.get(ele) > n){
    				set.add(ele);
    			}
    		}
    		char chosen = '1';
    		int number = -1;
    		for(Character ele: set){
    			if(freq.get(ele) > 0){
    				if(freq.get(ele) > number){
    					number = freq.get(ele);
    					chosen = ele;
    				}
    			}
    		}
    		if(chosen == '1'){
    			time += 1;
    			continue;
    		}
    		freq.put(chosen, freq.get(chosen) - 1);
    		last.put(chosen, time);
    		time += 1;
    		finished += 1;
    	}
    	return time;
    }

    public static void main(String[] args){
    	Solution621 s = new Solution621();
    	char[] test1 = new char[]{'A', 'A', 'A', 'B', 'B', 'B'};
        System.out.println(s.leastInterval(test1, 2));
        System.out.println(s.leastInterval(test1, 0));
	}
}