/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.

你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
*/

struct Lock {
  Lock():one(0),two(0),three(0),four(0),res(0) {}

  int one;
  int two;
  int three;
  int four;

  int res;

  Lock one_left() {
    one = (one + 9) % 10;
    return *this;
  }

  Lock one_right() {
    one = (one + 1) % 10;
    return *this;
  }

  Lock two_left() {
    two = (two + 9) % 10;
    return *this;
  }

  Lock two_right() {
    two = (two + 1) % 10;
    return *this;
  }

  Lock three_left() {
    three = (three + 9) % 10;
    return *this;
  }

  Lock three_right() {
    three = (three + 1) % 10;
    return *this;
  }


  Lock four_left() {
    four = (four + 9) % 10;
    return *this;
  }

  Lock four_right() {
    four = (four + 1) % 10;
    return *this;
  }

  string String() {
    return to_string(one) + to_string(two) + to_string(three) + to_string(four);
  }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      queue<Lock> que;
      que.push(Lock()); 
      set<string> forid(deadends.begin(), deadends.end());
      set<string> dup;

      while (!que.empty()) {
        auto lock = que.front();
        string val = lock.String();
        if (val == target) return lock.res;
        if (forid.count(val)) que.pop();
        else {
          lock.res++;

          Lock tmp = lock;
          Lock tmp2 = tmp.one_left();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.one_right();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.two_left();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.two_right();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.three_left();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.three_right();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.four_left();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          tmp = lock;
          tmp2 = tmp.four_right();
          if (!dup.count(tmp2.String())) {
            que.push(tmp2);
            dup.insert(tmp2.String());
          }

          que.pop();
        }
      }

      return -1;
    }
};