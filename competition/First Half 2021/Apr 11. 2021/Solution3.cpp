#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution3 {
public:
    int minSideJumps(vector<int>& obstacles) {
        int res = 0;
        int cur = 0;
        int path = 2;
        while(cur < obstacles.size()){
            if(cur < obstacles.size() - 1 && obstacles[cur + 1] == path){
                //cout << cur << endl;
                res++;
                if(obstacles[cur] == 0){
                    vector<int> vec(4, obstacles.size());
                    vec[path] = cur + 1;
                    for(int i = 1; i <= 3; i++){
                        if(i == path){
                            continue;
                        }
                        for(int j = cur + 1; j < obstacles.size(); j++){
                            if(obstacles[j] == i){
                                vec[i] = j;
                                break;
                            }
                        }
                    }
                    int index = -1;
                    int number = -1;
                    for(int i = 1; i <= 3; i++){
                        if(vec[i] >= number){
                            index = i;
                            number = vec[i];
                        }
                    }
                    path = index;
                }
                else{
                    int left = 1 + 2 + 3 - path - obstacles[cur];
                    path = left;
                }
            }
            //cout << path << endl;
            cur++;
        }
        return res;
    }
};