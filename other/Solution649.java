import java.util.Set;
import java.util.HashSet;

class Solution649 {
    public String predictPartyVictory(String senate) {
    	Set<Integer> set = new HashSet<>();
    	while(true){
    loop: for(int i = 0; i < senate.length(); i++){
    		if(set.contains(i)){
    			continue;
    		}
    		char cur = senate.charAt(i);
    		for(int j = i + 1; j < senate.length(); j++){
    			if(set.contains(j)){
    				continue;
    			}
    			char other = senate.charAt(j);
    			if(cur != other){
    				set.add(j);
    				continue loop;
    			}
    		}
            for(int j = 0; j < i; j++){
                if(set.contains(j)){
                    continue;
                }
                char other = senate.charAt(j);
                if(cur != other){
                    set.add(j);
                    continue loop;
                }
            }
    		return cur == 'R' ? "Radiant" : "Dire";
    	}
    }
    }

    public static void main(String[] args){
        Solution649 s = new Solution649();
        System.out.println(s.predictPartyVictory("DRRDRDRDRDDRDRDR"));
    }
}