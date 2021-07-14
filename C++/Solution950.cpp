#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

typedef long long ll;

class Solution950 {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(deck.size());
        for(int i = 1; i <= deck.size(); i++){
            q.push(i);
        }
        int index = 0;
        while(!q.empty()){
            int cur = q.front();
            //cout << cur << endl;
            q.pop();
            ans[cur - 1] = deck[index++];
            int cur2 = q.front();
            q.pop();
            q.push(cur2);
        }
        return ans;
    }
};

int main(){
    Solution950 s;
    vector<int> input = {17,13,11,2,3,5,7};
    auto vec = s.deckRevealedIncreasing(input);
    return 0;
}