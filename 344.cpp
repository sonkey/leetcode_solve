class Solution {
public:
    string reverseString(string s) {
        // string res;
        // for (auto it = s.rbegin(); it != s.rend(); ++it) {
        // 	res.push_back(*it);
        // }
        // return res;
        int size = s.size();
        for (int i = 0; i < s.size() / 2; ++i) {
        	std::swap(s[i], s[size - i - 1]);
        }
        return s;
    }
};
