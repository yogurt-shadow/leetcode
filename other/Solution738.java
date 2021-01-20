class Solution738 {
    public int monotoneIncreasingDigits(int N) {
        String str = String.valueOf(N);
        for(int i = 0; i < str.length() - 1; i++){
            if(str.charAt(i) > str.charAt(i + 1)){
                char[] array = str.toCharArray();
                array[i] -= 1;
                for(int j = i + 1; j < str.length(); j++){
                    array[j] = '9';
                }
                return monotoneIncreasingDigits(Integer.parseInt(String.valueOf(array)));
            }
        }
        return N;
    }

    public static void main(String[] args){
    	Solution738 s = new Solution738();
    	System.out.println(s.monotoneIncreasingDigits(332));
    }
}