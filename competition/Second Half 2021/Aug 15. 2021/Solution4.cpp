#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class UnionFind {
private:
    vector<int> f, sz;

public:
    UnionFind(int n) : f(n), sz(n) {
        for (int i = 0; i < n; i++){
            f[i] = i;
            sz[i] = 1;
        }
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    int find(int x){
        if (f[x] == x){
            return x;
        }
        int newf = find(f[x]);
        f[x] = newf;
        return f[x];
    }

    void merge(int x, int y){
        int fx = find(x), fy = find(y);
        if (fx == fy){
            return;
        }
        f[fx] = fy;
        sz[fy] += sz[fx];
    }

    int size(int x){
        return sz[find(x)];
    }
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

class Solution4 {
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        UnionFind uf(row * col + 2);
        int day = cells.size();
        vector<vector<int>> world(row, vector<int>(col, 1));
        for(auto ele: cells){
            world[ele[0]][ele[1]] = 0;
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(world[i][j] == 0){
                    continue;
                }
                if(i == 0){
                    uf.merge(convert(row, col, i, j), row * col);
                }
                if(i == row - 1){
                    uf.merge(convert(row, col, i, j), row * col + 1);
                }
                for(int k = 0; k < 4; k++){
                    int ii = i + dir[k][0], jj = j + dir[k][1];
                    if(ii >= 0 && ii < row && jj >= 0 && jj < col && world[ii][jj] == 1){
                        uf.merge(convert(row, col, i, j), convert(row, col, ii, jj));
                    }
                }
            }
        }
        if(uf.isConnected(row * col, row * col + 1)){
            return day;
        }
        while(day > 0){
            day --;
            int changeX = cells[day][0], changeY = cells[day][1];
            world[changeX][changeY] = 1;
            if(changeX == 0){
                uf.merge(convert(row, col, changeX, changeY), row * col);
            }
            if(changeX == row - 1){
                uf.merge(convert(row, col, changeX, changeY), row * col + 1);
            }
            for (int k = 0; k < 4; k++) {
                int ii = changeX + dir[k][0], jj = changeY + dir[k][1];
                if (ii >= 0 && ii < row && jj >= 0 && jj < col && world[ii][jj] == 1){
                    uf.merge(convert(row, col, changeX, changeY), convert(row, col, ii, jj));
                }
            }
            if(uf.isConnected(row * col, row * col + 1)){
                return day;
            }
        }
        return 0;
    }

    int convert(int row, int col, int x, int y){
        return x * col + y;
    }
};

int main(){
    
    return 0;
}