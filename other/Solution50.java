import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution50 {
    public double myPow(double x, int n) {
        return n > 0 ? myPow2(x, (long) n) : 1 / myPow2(x, -(long) n);
    }

    private double myPow2(double x, long n){
        if(n == 0){
            return 1;
        }
        double last = myPow2(x, n / 2);
        return n % 2 == 1 ? last * last * x : last * last;
    }

    public static void main(String[] args){
    	Solution50 s = new Solution50();
    	System.out.println(s.myPow(2.0000, -2));
    }
}