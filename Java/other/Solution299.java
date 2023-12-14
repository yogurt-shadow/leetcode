import java.util.Set;
import java.util.HashSet;

class Solution299 {
    public String getHint(String secret, String guess) {
    	int[] count = new int[10];
    	Set<Integer> set = new HashSet<>();
    	for(int i = 0; i < secret.length(); i++){
    		char cur = secret.charAt(i);
    		count[cur - '0'] += 1;
    	}
    	int a = 0;
    	int b = 0;
    	for(int i = 0; i < secret.length(); i++){
    		if(secret.charAt(i) == guess.charAt(i)){
    			count[secret.charAt(i) - '0'] -= 1;
    			a += 1;
    			set.add(i);
    		}
    	}
    	for(int i = 0; i < secret.length(); i++){
    		if(set.contains(i)){
    			continue;
    		}
    		char cur = guess.charAt(i);
    		if(count[cur - '0'] > 0){
    			b += 1;
    			count[cur - '0'] -= 1;
    		}
    	}
    	return String.valueOf(a) + "A" + String.valueOf(b) + "B"; 
    }
}