
package other;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution3 {
    public static int lengthOfLongestSubstring(String s) {
        if(s.length() <= 0){
            return 0;
        }
        int start = 0;
        int end = 1;
         int max  = end - start;
         int current = end - start;

        while(end < s.length()){
        String x = s.substring(start, end);
        if(!x.contains(String.valueOf(s.charAt(end)))){
            end += 1;
            current = end - start;
            x = s.substring(start, end);
        }
        else{
            start += x.indexOf(s.charAt(end)) + 1;
            x = s.substring(start, end);
        }
        if(current > max){
            max = current;
        }
    }
    return max;
}

public static void main(String[] args){
        String x = "abacbas";
        System.out.println(lengthOfLongestSubstring(x));
}
}