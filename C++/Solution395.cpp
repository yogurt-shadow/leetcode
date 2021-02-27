#include<iostream>
#include<vector>

using namespace std;

class Solution395 {
public:
    int longestSubstring(string s, int k) {
        int size = s.length();
        vector<int> freq(26);
        for(auto ele: s){
            freq[ele - 'a']++;
        }
        char spliter = '1';
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0 && freq[i] < k){
                spliter = 'a' + i;
                break;
            }
        }
        if(spliter == '1'){
            return size;
        }
        vector<string> str = split(s, spliter);
        int len = 0;
        for(auto ele: str){
            len = max(len, longestSubstring(ele, k));
        }
        return len;
    }

    vector<string> split(string str, char cur){
        vector<string> result;
        int left = 0;
        int size = str.length();
        while(left < size){
            while(left < size && str[left] == cur){
                left++;
            }
            if(left == size){
                break;
            }
            int right = left;
            while(right < size && str[right] != cur){
                right++;
            }
            int end = right - 1;
            result.push_back(str.substr(left, end - left + 1));
            left = right;
        }
        return result;
    }
};

int main(){
    Solution395 s;
    string test = "weitong";
    cout << s.longestSubstring(test, 2);
}