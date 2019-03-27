/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int size = grid.size();
        if (size == 0) return 0;
        int col_size = grid[0].size();
        if (col_size == 0) return 0;
        int res = 0;

        vector<vector<bool>> visited(size, vector<bool>(col_size, false));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row >= grid.size() || row < 0) return;
        if (col >= grid[0].size() || col < 0) return;
        if (visited[row][col]) return;
        if (grid[row][col] == '0') return;
        visited[row][col] = true;

        dfs(grid, visited, row-1, col);
        dfs(grid, visited, row, col-1);
        dfs(grid, visited, row+1, col);
        dfs(grid, visited, row, col+1);
    }
};