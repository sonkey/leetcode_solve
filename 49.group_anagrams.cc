//https://leetcode-cn.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> res;
        for (const auto& str : strs) {
            auto tmp = str;
            sort(tmp.begin(), tmp.end());
            res[tmp].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& vec: res) {
            ans.push_back(vector<string>(vec.second.begin(), vec.second.end()));
        }
        return ans;
    }
};