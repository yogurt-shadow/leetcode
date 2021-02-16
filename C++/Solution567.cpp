#include<iostream>
#include<vector>


using namespace std;

class Solution567 {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.length();
        int size2 = s2.length();
        if(size2 < size1){
            return false;
        }
        int count1[26] = {0}, count2[26] = {0};
        for(auto ele: s1){
            count1[ele - 'a']++;
        }
        int left = 0, right = size1 - 1;
        for(int i = left; i <= right; i++){
            count2[s2[i] - 'a']++;
        }
        if(check(count1, count2)){
            return true;
        }
        while(right + 1 < size2){
            right++;
            count2[s2[right] - 'a']++;
            count2[s2[left] - 'a']--;
            left++;
            if(check(count1, count2)){
                return true;
            }
        }
        return false;
    }

    bool check(int a[], int b[]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;    
            }
        }
        return true;
    }
};

int main(){
    Solution567 s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl;
    
    return 0;
}