class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int min_sz = strs[0].size();
        for (auto str : strs) {
            if (str.size() < min_sz)
                min_sz = str.size();
        }

        if (min_sz == 0) return "";

        string res;
        int index = 0;
        bool flag = true;
        while (index < min_sz) {
            char ch = strs[0][index];
            for (auto str : strs) {
                if (str[index] != ch) {
                    flag = false;
                    break;
                }
            }
            if (flag) { 
                res.push_back(ch);
                index++;
            } else {
                break;
            }
        }

        return res;
    }
};
