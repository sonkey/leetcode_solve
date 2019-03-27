/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
      queue<pair<int,int>> que;
      que.push(make_pair(0,n));
      vector<bool> visited(n+1, false);

      int ans;
      while (!que.empty()) {
        auto val = que.front();
        if (val.second == 0) return val.first;
        ans = ++val.first;
        for (int i = 1; i * i <= val.second; ++i) {
          if (!visited[val.second - i*i]) {
            que.push(make_pair(ans, val.second-i*i));
            visited[val.second-i*i] = true;
          }
        }
        que.pop();
      }

      return -1;
    }
};