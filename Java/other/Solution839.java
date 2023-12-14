class Solution839 {
    public int numSimilarGroups(String[] strs) {
    	int number = strs.length;
    	UnionFind uf = new UnionFind(number);
 	for(int i = 0; i < number; i++){
    		String str = strs[i];
    		for(int j = 0; j < i; j++){
    			if(similar(str, strs[j])){
    				uf.connect(i, j);
    			}
    		}
    	}
    	return uf.size();
    }

    private boolean similar(String str1, String str2){
    	int difference = 0;
    	for(int i = 0; i < str1.length(); i++){
    		if(str1.charAt(i) != str2.charAt(i)){
    			difference += 1;
    		}
    	}
    	return difference == 2 || difference == 0;
    }

    public static void main(String[] args){
        Solution839 s = new Solution839();
        String[] test1 = {"tars", "arts","rats"};
        System.out.println(s.numSimilarGroups(test1));
    }
}