#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
typedef long long ll;

class Solution1700 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int num[2];
       num[0] = 0; num[1] = 0;
       for(auto ele: students){
           num[ele] ++;
       }
       for(auto ele: sandwiches){
           if(num[ele]){
               num[ele] --;
           }
           else{
               return num[1 - ele];
           }
       }
       return 0;
    }
};