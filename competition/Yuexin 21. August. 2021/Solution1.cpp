#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1{
public:
    double getAdmissionLine(int k, vector<double> &scores){
        sort(scores.begin(), scores.end());
        return scores[scores.size() - k];
    }
};

int main(){
    Solution1 s;
    vector<double> vec = {150, 300, 400, 500, 600, 700, 550, 450, 450, 500, 555.5};
    cout << s.getAdmissionLine(5, vec) << endl;
    return 0;
}