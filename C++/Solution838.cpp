#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution838 {
public:
    string pushDominoes(string dominoes) {
        int size = dominoes.length();
        vector<int> distL(size);
        vector<int> distR(size);
        int dist = size;
        for(int i = 0; i < size; i++){
            if(dominoes[i] == 'R'){
                distR[i] = 0;
                dist = 0;
            }
            else if(dominoes[i] == 'L'){
                dist = size;
                distR[i] = dist;
            }
            else{
                if(dist == size){
                    distR[i] = size;
                }
                else{
                    distR[i] = ++ dist;
                }
            }
        }
        dist = size;
        for(int i = size - 1; i >=0; i--){
            if(dominoes[i] == 'L'){
                dist = 0;
                distL[i] = 0;
            }
            else if(dominoes[i] == 'R'){
                dist = size;
                distL[i] = size;
            }
            else{
                if(dist == size){
                    distL[i] = size;
                }
                else{
                    distL[i] = ++ dist;
                }
            }
        }
        /*
        for(auto ele: distR){
            cout << ele << " ";
        }
        cout << endl;
        for(auto ele: distL){
            cout << ele << " ";
        }
        */
       string res = "";
       for(int i = 0; i < size; i++){
           if(dominoes[i] == '.'){
               if(distL[i] < distR[i]){
                   res += "L";
               }
               else if(distR[i] < distL[i]){
                   res += "R";
               }
               else{
                   res += ".";
               }
           }
           else{
               res += dominoes[i];
           }
       }
        return res;
    }
};

int main(){
    Solution838 s;
    string str = ".L.R...LR..L..";
    cout << s.pushDominoes(str) << endl;
    return 0;
}