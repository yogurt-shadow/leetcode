/** jiazhi offer */
class Solution58_2 {
    public String reverseLeftWords(String s, int n) {
    	String a = s.substring(0, n);
    	String b = s.substring(n, s.length());
    	return b + a;
    }
}