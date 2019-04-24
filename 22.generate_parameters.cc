// https://leetcode-cn.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursive(res, "", n, n);
        return res;
    }
private:
    void recursive(vector<string>& res, string str, int left, int right) {
        if (left > right) return;
        if (right == 0 && left == 0) {
            res.push_back(str);
            return;
        }
        if (right > 0) recursive(res, str+")", left, right-1);
        if (left > 0) recursive(res, str+"(", left-1, right);
    }
};