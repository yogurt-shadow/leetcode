import java.util.List;
import java.util.ArrayList;

class Solution68 {
    
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> res = new ArrayList<>();
        int i = 0, width = maxWidth + 1;
        while (i < words.length) {
            if (words[i].length() == maxWidth) {
                res.add(words[i]);
                i++;
                continue;
            }
            //判断后面能接几个单词
            int j = i + 1, len = words[i].length() + 1;
            while (j < words.length) {
                if (words[j].length() + len + 1 <= width) {
                    len += (words[j].length() + 1);
                    j++;
                } else {
                    break;
                }
            }
            // 每一行的最后一个单词后面不用空格
            len--;
            int leftSpace = maxWidth - len;
            StringBuilder s = new StringBuilder();
            // (j - i)个字符串 words[i]...words[j - 1]
            int num = j - i;
            if (j == words.length) {
                for (int k = i; k < j; k++) {
                    if (k == j - 1) {
                        s.append(words[k]);
                        break;
                    }
                    s.append(words[k]).append(" ");
                }
                // 剩余的空格
                s.append(" ".repeat(leftSpace));
            } else {
                if (num > 1) {
                    int t = (leftSpace / (num - 1));
                    int x = t * (num - 1);
                    for (int k = i; k < j; k++) {
                        if (k == j - 1) {
                            s.append(words[k]);
                            break;
                        }
                        s.append(words[k]).append(" ");
                        if (x >= leftSpace) {
                            s.append(" ".repeat(t));
                        } else {
                            s.append(" ".repeat(t + 1));
                            x++;
                        }
                    }
                } else {
                    s.append(words[i]).append(" ".repeat(maxWidth - words[i].length()));
                }
            }
            res.add(s.toString());
            i = j;
        }
        return res;
    }


    public static void main(String[] args){
        Solution68 s = new Solution68();
        String[] str = {"Science","is","what","we","understand","well","enough","to","explain", "to","a","computer.","Art","is","everything","else","we","do"};
        List<String> list = s.fullJustify(str, 20);
        for(String ele: list){
            System.out.println(ele);
        }
    }
}