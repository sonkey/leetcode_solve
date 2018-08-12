class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;

        for (int i = 0; i < matrix.size(); ++i) {
        	for (int j = i + 1; j < matrix[i].size(); ++j) {
        		std::swap(matrix[i][j], matrix[j][i]);
        	}
        }

        for (int i = 0; i < matrix.size(); ++i) {
        	reverse(matrix[i]);
        }
    }

private:
	void reverse(vector<int>& vec) {
		for (int i = 0; i < vec.size() / 2; ++i) {
			std::swap(vec[i], vec[vec.size() - i - 1]);
		}
	}
};
