#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1604 {
public:
    unordered_map<string, vector<int>> mp;
    unordered_set<string> st;

    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime){
        vector<string> ans;
        for (int i = 0; i < keyName.size(); i++){
            if (st.count(keyName[i])){
                continue;
            }
            mp[keyName[i]].push_back(convert(keyTime[i]));
            if (mp[keyName[i]].size() >= 3){
                int size = mp[keyName[i]].size();
                sort(mp[keyName[i]].begin(), mp[keyName[i]].end());
                for (int k = 0; k + 2 < size; k++){
                    int time = mp[keyName[i]][k + 2] - mp[keyName[i]][k];
                    if (time >= 0 && time <= 100){
                        ans.push_back(keyName[i]);
                        //cout << keyName[i] << endl;
                        st.insert(keyName[i]);
                        break;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    int convert(string time){
        string s = time.substr(0, 2) + time.substr(3, 2);
        int ans = 0;
        for (int i = 0; i < 4; i++){
            auto cur = s[i];
            ans = ans * 10 + (cur - '0');
        }
        return ans;
    }
};

int main(){
    unordered_map<string, bool> m;
    if(m["123"]){
        cout << 123 << endl;
    }
    return 0;
}