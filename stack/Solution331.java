import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.util.LinkedList;

class Solution331 {
    public boolean isValidSerialization(String preorder) {
        int space = 1;
       	for(String s: preorder.split(",")){
       		space -= 1;
       		if(space < 0){
       			return false;
       		}

       		if(!s.equals("#")){
       			space += 2;
       		}
       	}
       	return space == 0;
    }

    public static void main(String[] args){
    	Solution331 s = new Solution331();
    	String s1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    	System.out.println(s.isValidSerialization(s1));

        LinkedList<Integer> x1 = new LinkedList<>();
        LinkedList<String> x2 = new LinkedList<>();
        LinkedList<Solution331> x3 = new LinkedList<>();
    	System.out.println(x1.getClass());
        System.out.println(x2.getClass() == x1.getClass());
        System.out.println(x3.getClass() == x1.getClass());

        String x = "[-1]";
		System.out.println(x.substring(1, 2));
    }
}