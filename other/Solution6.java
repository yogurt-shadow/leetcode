public class Solution6 {
    public static String convert(String s, int numRows) {
       if(numRows == 1){return s;}
       char[][] result = new char[numRows][100];
       int[] index = new int[numRows];
       int dir = -1;
       int current = 0;
       for(int i = 0; i < numRows; i++){
       	index[i] = 0;
       }
       int stringindex = 0;
       while(stringindex < s.length()){
       	if(stringindex % (numRows - 1) == 0){
       		dir = - dir;
       	}
       	result[current][index[current]] = s.charAt(stringindex);
       	index[current] += 1;
       	if(dir > 0){
       		current += 1;
       	}
       	else{
       		current -= 1;
       	}
       	stringindex += 1;
       }
       String r = "";
       for(int row = 0; row < numRows; row++){
       	for(int col = 0; col <= index[row] - 1; col ++){
       		r += String.valueOf(result[row][col]);
       	}
       }
       return r;
    }


    public static void main(String[] args){
    	String s = "LEETCODEISHIRING";
    	int n = 3;
    	System.out.println(convert(s, 4));
    }
}