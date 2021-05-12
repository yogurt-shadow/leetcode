#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution690 {
public:
    unordered_map<int, Employee*> mp;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto ele: employees){
            mp[ele -> id] = ele;
        }
        return get(id);
    }

    int get(int id){
        Employee* emp = mp[id];
        int res = emp -> importance;
        for(auto ele: emp -> subordinates){
            res += get(ele);
        }
        return res;
    }
};