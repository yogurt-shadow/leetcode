class Solution880 {
    public String decodeAtIndex(String S, int K) {
        long total = 0;
        for(int i = 0; i < S.length(); i++){
            char cur = S.charAt(i);
            if(cur >= 'a' && cur <= 'z'){
                total += 1;
            }
            else if(cur >= '2' && cur <= '9'){
                total = total * (cur - '0');
            }
        }
        if(K > total){
            return "";
        }
        char last = S.charAt(S.length() - 1);
        if(last >= '2' && last <= '9'){
            long size = total / (last - '0');
            if(size == (long) 1){
                return String.valueOf(S.charAt(0));
            }
            if(K % size == 0){
				return decodeAtIndex(S.substring(0, S.length() - 1), (int) size);
			}
            return decodeAtIndex(S.substring(0, S.length() - 1), (int) (K % size));
        }
        if(total == K){
            return String.valueOf(last);
        }
        return decodeAtIndex(S.substring(0, S.length() - 1), K);
    }

    public static void main(String[] args){
        Solution880 s = new Solution880();
        System.out.println(s.decodeAtIndex("a2b3c4d5e6f7g8h9", 3));
    }
}
