/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      int size = T.size();
      vector<int> res(size, 0);
      stack<int> st;

      st.push(size - 1);
      for (int i = size - 2; i >= 0; i--) {
        while (!st.empty()) {
          if (T[i] >= T[st.top()]) st.pop();
          else {
            res[i] = st.top() - i;
            break;
          }
        }
        st.push(i);
      }

      return res;
    }
};