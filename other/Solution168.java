class Solution168 {
   public String convertToTitle(int n) {
    StringBuilder ans = new StringBuilder();
    while (n != 0) {
        int remain = n % 26;
        if (remain == 0) {
            //n-1是为了回退一个
            n--;
            ans.append("Z");
        } else {
            ans.append((char) (remain + 64));
        }
        n = n / 26;
    }
    return ans.reverse().toString();
}
}