package other;
import java.util.Set;
import java.util.HashSet;

class Solution1704 {


    public boolean halvesAreAlike(String s) {
    	String a = s.substring(0, s.length() / 2);
    	String b = s.substring(s.length() / 2 , s.length());
    	return count(a) == count(b);
    }

    private int count(String x){
        Set<Character> ele = new HashSet<>();
        ele.add('a');
        ele.add('e');
        ele.add('i');
        ele.add('o');
        ele.add('u');

        ele.add('A');
        ele.add('E');
        ele.add('I');
        ele.add('O');
        ele.add('U');

        int result = 0;
        for(int i = 0; i < x.length(); i++){
            if(ele.contains(x.charAt(i))){
                result += 1;
            }
        }
        return result;
    }

    }