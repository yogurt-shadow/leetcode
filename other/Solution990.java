import java.util.Set;
import java.util.HashSet;

class Solution990 {
    public boolean equationsPossible(String[] equations) {
    	UnionFind uf = new UnionFind(26);
    	Set<int[]> set = new HashSet<>();
    	for(String str: equations){
    		int a = (int) str.charAt(0) - 'a';
    		int b = (int) str.charAt(3) - 'a';
    		if(str.charAt(1) == '!'){
    			set.add(new int[]{a, b});
    			continue;
    		}
    		uf.connect(a, b);
    	}
    	for(int[] ele: set){
    		if(uf.is_connected(ele[0], ele[1])){
    			return false;
    		}
    	}
    	return true;
    }
}