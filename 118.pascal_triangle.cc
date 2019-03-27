/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
      res.push_back(vector<int>{1});
    }
    //init
  	for (int i = 1; i < numRows; ++i) {
  		res[i].resize(i+1);
  		res[i][res[i].size() - 1] = 1;
  	}  

  	for (int row = 2; row < numRows; ++row) {
  		//if (res[row][col] == 1) continue;
  		for (int col = 1; col < numRows; ++col) {
  			if (res[row][col] == 1) break;
  			res[row][col] = res[row-1][col-1] + res[row-1][col];
  		}
  	}

  	return res;
  }
};