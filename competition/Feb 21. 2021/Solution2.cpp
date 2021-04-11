#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution2 {
public:
    int size;
    int orchestraLayout(int num, int xPos, int yPos) {
        size = num;
        int level = min(xPos, min(yPos, min(num - 1 - xPos, num - 1 - yPos)));
        ll value = levelfunc(level);
        int curx = level;
        int cury = level;
        ll res;
        //cout << level << endl;
        //cout << value << endl;
        if(xPos == curx){
            res = value + (yPos - cury);
           if(res % 9 == 0){
            res = 9;
        }
        else{
            res %= 9;
        }
            return res;
        }
        //cout << curx << cury << endl;
        cury += (size - (2 * level + 1));
        value += (size - (2 * level + 1));
        if(value % 9 == 0){
            value = 9;
        }
        else{
            value %= 9;
        }
                //cout << curx << cury << endl;

        if(cury == yPos){
            res = value + (xPos - curx);
        if(res % 9 == 0){
            res = 9;
        }
        else{
            res %= 9;
        }
            return res;
        }
                

        curx += (size - (2 * level + 1));
        value += (size - (2 * level + 1));
        if(value % 9 == 0){
            value = 9;
        }
        else{
            value %= 9;
        }
                //cout << curx << cury << endl;

        if(curx == xPos){
            res = value + abs(yPos - cury);
            //cout << "12d" << endl;
           if(res % 9 == 0){
            res = 9;
        }
        else{
            res %= 9;
        }
            return res;
        }
               
        cury = level;
        value += (size - (2 * level + 1));
        if(value % 9 == 0){
            value = 9;
        }
        else{
            value %= 9;
        }
        //cout << curx << cury << endl;
        //cout << value << endl;
        res = value + abs(xPos - curx);
        //cout << res << endl;
        if(res % 9 == 0){
            res = 9;
        }
        else{
            res %= 9;
        }
        return res;
    }

    int levelfunc(int level){
        ll res = 0;
        if(level == 0){
            return 1;
        }
        res = (levelfunc(level - 1) % 9) + ((size - (2 * level - 1)) * 4 % 9);
        if(res == 9){
            return 9;
        }
        return res % 9;
    }
};

int main(){
    Solution2 s;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << s.orchestraLayout(5, i, j) << endl;
        }
    }
    
    return 0;
}