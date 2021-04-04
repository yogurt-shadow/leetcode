#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution927 {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int number = 0;
        int size = arr.size();
        for(auto ele: arr){
            if(ele){
                number++;
            }
        }
        if(number % 3 && number > 0){
            return {-1, -1};
        }
        if(number == 0){
            return {0, size - 1};
        }
        int start1 = -1, end1 = -1, start2 = -1, end2 = -1, start3 = -1, end3 = -1;
        int num = 0;
        for(int i = 0; i < size; i++){
            if(arr[i]){
                num++;
                if(num == 1 && start1 == -1){
                    start1 = i;
                }
                if(num == number / 3 && end1 == -1){
                    end1 = i;
                }
                if(num == number / 3 + 1 && start2 == -1){
                    start2 = i;
                }
                if(num == number / 3 * 2 && end2 == -1){
                    end2 = i;
                }
                if(num == number / 3 * 2 + 1 && start3 == -1){
                    start3 = i;
                }
                if(num == number && end3 == -1){
                    end3 = i;
                }
            }
        }
        if(end3 - start3 != end2 - start2 || end2 - start2 != end1 - start1){
            return {-1, -1};
        }
        int zero_num = size - 1 - end3;
        if(start2 - end1 - 1 < zero_num || start3 - end2 - 1 < zero_num){
            return {-1, -1};
        }
        return {end1 + zero_num, end2 + zero_num + 1};
    }
};

int main(){
    vector<int> vec = {1, 1, 0, 0, 1};
    Solution927 s;
    cout << s.threeEqualParts(vec)[0] << endl;;
    return 0;
}