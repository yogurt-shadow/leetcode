
package other;
public class Solution5 {
    public static String longestPalindrome(String s) {
        if(s.length() <= 1){
            return s;
        }
        String current = String.valueOf(s.charAt(0));
        int max_len = 1;
        for(int start = 1; start < s.length(); start++){
            if(start - (max_len + 1) / 2 >= 0 && start + (max_len + 1) / 2  + 1<= s.length()){
            String odd = s.substring(start - (max_len + 1) / 2, start +( max_len + 1)/ 2 + 1);
            if(isPalindrome(odd)){
                max_len = odd.length();
                current = odd;
                start--;
            }
        }
        if(start - (max_len + 2)/ 2  >= 0 && start + (max_len + 2) / 2  <= s.length()){
            String even = s.substring(start - (max_len + 2) / 2 , start + (max_len + 2)/ 2 );
            if(isPalindrome(even)){
                current = even;
                max_len = even.length();
                start--;
            }
        }
        }
        return current;
    }

    private static boolean isPalindrome(String s){
        if(s.length() < 2){
            return true;
        }
        char x = s.charAt(0);
        char y = s.charAt(s.length() - 1);
        if(x != y){
            return false;
        }
        return isPalindrome(s.substring(1, s.length() - 1));
    }

    public static void main(String[] args){
        String x = "ptmykvjanwiihepqhzupneckpzomgvzmyoybzfeggbgcillisyoskdodzlpbltefiz";
        System.out.println(longestPalindrome(x));
    }

}