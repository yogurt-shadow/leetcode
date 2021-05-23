#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

class Solution2{
public:
    bool check(vector<int> &dist, double hour, int speed)
    {
        double time = 0;
        for (int i = 0; i + 1 < dist.size(); i++)
        {
            double ele = dist[i];
            time += ele / (1.0 * speed);
            //cout << speed  << " "<< time << endl;
            time = ceil(time);
            //cout << speed  << " "<< time << endl;
        }
        time += 1.0 * dist[dist.size() - 1] / (1.0 * speed);
        //cout << endl;
        return time <= hour;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (hour <= dist.size() - 1)
        {
            return -1;
        }
        int lower = 1;
        int higher = 1e7;
        if (check(dist, hour, 1))
        {
            return 1;
        }
        while (higher - lower > 1)
        {
            int mid = (higher - lower) / 2 + lower;
            if (check(dist, hour, mid))
            {
                higher = mid;
            }
            else
            {
                lower = mid + 1;
            }
        }
        return check(dist, hour, lower) ? lower : higher;
    }
};

int main(){
    
    
    return 0;
}