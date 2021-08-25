#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution443 {
public:
    int compress(vector<char> &chars){
        int write = 0, left = 0;
        int size = chars.size();
        for (int read = 0; read < size; read++){
            if (read == size - 1 || chars[read + 1] != chars[read]){
                chars[write++] = chars[read];
                int len = read - left + 1;
                int start = write;
                if (len > 1){
                    while (len){
                        chars[write++] = '0' + len % 10;
                        len /= 10;
                    }
                    reverse(chars.begin() + start, chars.begin() + write);
                }
                left = read + 1;
            }
        }
        return write;
    }
};

void print(vector<int>& vec){
    for(int i = 0; i < vec.size() - 1; i++){
        cout << vec[i] << ", ";
    }
    cout << vec.back() << endl;
}

int main(){
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    vector<int> vec2 = {1, 2, 3, 4, 5, 6};
    reverse(vec1.begin() + 1, vec1.begin() + 3);
    print(vec1);
    reverse(&vec2[1], &vec2[3]);
    print(vec2);
    vector<int> vec3 = {1, 2, 3, 4, 5, 6};
    cout << *(vec3.begin() + 2) << endl;
    return 0;
}