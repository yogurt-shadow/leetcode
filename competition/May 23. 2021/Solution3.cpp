#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;

class Solution3{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int len = s.length();
        if (s[len - 1] == '1')
        {
            return false;
        }
        vector<int> position;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '0')
            {
                position.push_back(i);
            }
        }
        int index = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            if(cur == len - 1){
                return true;
            }
            q.pop();
            while(index < position.size() && position[index] <= cur + maxJump){
                if(position[index] >= cur + minJump){
                    q.push(position[index]);
                }
                index ++;
            }
        }   
        return false;
    }
};

int main(){
    
    
    return 0;
}