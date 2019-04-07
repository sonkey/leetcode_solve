// https://leetcode-cn.com/problems/number-of-boomerangs/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (const auto& p : points) {
            map<int, int> dist;
            for (const auto& pp : points) 
                dist[dis(p, pp)]++;

            for (const auto d : dist)
                res += d.second * (d.second - 1);
        }
        return res;
    }

private:
    int dis(const pair<int, int>& a, const pair<int, int>& b) {
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
};