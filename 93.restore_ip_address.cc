/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> vec;

    backtrace(s, 0, 1, 3, vec, res);
    if (s.substr(0, 1) != "0") {
      backtrace(s, 0, 2, 3, vec, res);
      backtrace(s, 0, 3, 3, vec, res);
    }
    return res;           
  }

private:
  void backtrace(string &s, int begin, int length, int point, vector<string> &vec, vector<string> &res) {
    if (begin > s.size() || begin + length > s.size()) return;
    string tmp = s.substr(begin, length);
    if (point == 0 && isValid(tmp) && begin+length == s.size()) {
      //st.push(tmp);
      string ans = buildAns(vec);
      ans += tmp;
      res.push_back(ans);
      return;
    }

    if (point > 0 && isValid(tmp)) {
      vec.push_back(tmp);
      backtrace(s, begin+length, 1, --point, vec, res);
      vec.pop_back();
      ++point;

      if (s.substr(begin+length, 1) != "0") {
        for (int i = 2; i <= 3; ++i) {
          vec.push_back(tmp);
          backtrace(s, begin+length, i, --point, vec, res);
          vec.pop_back();
          ++point;
        }
      }
    }
    return;
  }

  bool isValid(string str) {
    if (str.size() < 3) return true;
    int num = stoi(str);
    return num < 256;
  }

  string buildAns(vector<string>& vec) {
    string ans;
    for (auto str : vec) {
      ans += str;
      ans += ".";
    }
    return ans;
  }

};