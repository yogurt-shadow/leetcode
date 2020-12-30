public class Solution9 {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int copy = x;
        int reverse = 0;
        while(copy != 0){
            reverse  = reverse * 10;
            reverse += copy % 10;
            copy = copy / 10;
        }
        return x == reverse;
    }
}