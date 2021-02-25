#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

class Solution1178 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int size1 = words.size(), size2 = puzzles.size();
        vector<int> answer(size2);
        unordered_map<int, int> map;
        for(auto word: words){
            map[digit(word)]++;
        }
        for(int index = 0; index < size2; index++){
            string puzzle = puzzles[index];
            int k = digit(puzzle);
            int ans = 0;
            for(int j = k; j != 0; j = (j - 1) & k){
                char first = puzzle[0];
                if((1 << (first - 'a')) & j){
                    ans += map[j];
                }
            }
            answer[index] = ans;
        }
        return answer;
    }

    int digit(string str){
        int res = 0;
        for(auto ele: str){
            res = res | (1 << (ele - 'a'));
        }
        return res;
    }
};

int main(){
    Solution1178 s;
    vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    vector<int> answer = s.findNumOfValidWords(words, puzzles);
    for(auto ele: answer){
        cout << ele << " ";
    }
    return 0;
}