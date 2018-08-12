class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i += 3) {
        	for (int j = 0; j < board[i].size(); j += 3) {
        		if (!isValidSmallSudoku(board, i, i+3, j, j+3))
        			return false;
        	}
        }

        for (int i = 0; i < board.size(); ++i) {
        	set<char> tool_row;
        	set<char> tool_col;
        	
        	for (int j = 0; j < board[i].size(); ++j) {
        		if (tool_row.count(board[i][j]) || tool_col.count(board[j][i])) {
        			return false;
        		} else {
        			if (isNumber(board[i][j])) tool_row.insert(board[i][j]);
        			if (isNumber(board[j][i])) tool_col.insert(board[j][i]);
        		}
        	}
        }

        return true;
    }

private:
	bool isNumber(char ch) {
		return ch != '.';
	}

	bool isValidSmallSudoku(vector<vector<char>>& board, int row_begin, int row_end, int col_begin, int col_end) {
		set<char> tool;
		for (int i = row_begin; i < row_end; ++i) {
			for (int j = col_begin; j < col_end; ++j) {
				if (!isNumber(board[i][j])) continue;
				
				if (tool.count(board[i][j])) {
					return false;
				} else {
					tool.insert(board[i][j]);
				}
			}
		}
		return true;
	}
};
