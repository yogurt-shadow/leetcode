#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1105 {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int size = books.size();
        vector<int> dp(size + 1, INT_MAX); 
        // dp[i] stands for the total height when putting books[i] in the first of somelevel.
        dp.back() = 0;
        for(int i = size - 1; i >= 0; i--){
            int width = 0;
            int height = 0;
            for(int j = i; j < size && width + books[j][0] <= shelfWidth; j++){
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j + 1] + height);
                width += books[j][0];
            }
        }
        return dp[0];
    }
};