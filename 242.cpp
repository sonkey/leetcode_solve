class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size()) return false;

        map<char, int> tool;
        for (auto c : s) tool[c]++;
       	for (auto c : t) tool[c]--;
        for (auto it = tool.begin(); it != tool.end(); ++it) {
        	if (it->second != 0) return false;
        }
        return true;
    }
};
