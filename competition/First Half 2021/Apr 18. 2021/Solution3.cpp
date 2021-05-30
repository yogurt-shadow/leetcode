#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>
#include<queue>

using namespace std;
using ll = long long;


static bool cmp(vector<int>& vec1, vector<int>& vec2){
    return vec1[1] < vec2[1];
}

struct Node{
    int index;
    int eTime;
    int pTime;
    Node(int x, int y, int z){
        index = x;
        eTime = y;
        pTime = z;
    }
};

struct cmp2{
    bool operator()(Node& node2, Node& node1){
        if(node2.pTime < node1.pTime){
            return false;
        }
        if(node2.pTime == node1.pTime){
            return node2.index >= node1.index;
        }
        return true;
    }
};

class Solution3{
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        vector<vector<int>> copy(tasks.size(), vector<int>(3));
        for(int i = 0; i < tasks.size(); i++){
            copy[i][0] = i;
            copy[i][1] = tasks[i][0];
            copy[i][2] = tasks[i][1];
        }
        sort(copy.begin(), copy.end(), cmp);
        priority_queue<Node, vector<Node>, cmp2> pq;
        int index2 = 0;
        ll time = copy[0][1];
        //cout << "dqwd" << endl;
        while(ans.size() < tasks.size()){
            if(pq.size() == 0 && index2 < tasks.size()){
                time = max(time, (ll) copy[index2][1]);
            }
            //cout << time << endl;
            while(index2 < tasks.size() && copy[index2][1] <= time){
                auto ele = copy[index2];
                pq.push(Node(ele[0], ele[1], ele[2]));
                index2++;
            }
            //cout << pq.size() << endl;
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.index);
            time += cur.pTime;
        }
        return ans;
    }
};

int main(){
    Solution3 s;
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    auto vec = s.getOrder(tasks);
    for(auto ele: vec){
        cout << ele << endl;
    }
    return 0;
}