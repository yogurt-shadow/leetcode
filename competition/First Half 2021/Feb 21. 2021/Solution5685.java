class Solution5685 {
    public String mergeAlternately(String word1, String word2) {
    	char[] w1 = word1.toCharArray();
    	char[] w2 = word2.toCharArray();
    	int index1 = 0, index2 = 0;
    	int size1 = w1.length, size2 = w2.length;
    	StringBuilder str = new StringBuilder();
    	while(index1 < size1 && index2 < size2){
    		str.append(w1[index1]);
    		index1++;
    		str.append(w2[index2]);
    		index2++;
    	}
    	if(index1 == size1){
    		while(index2 < size2){
    			str.append(w2[index2]);
    			index2++;
    		}
    	}
    	else{
    		while(index1 < size1){
    			str.append(w1[index1]);
    			index1++;
    		}
    	}
    	return str.toString();
    }
}