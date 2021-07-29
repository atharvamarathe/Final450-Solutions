
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1])
            {
                if (find(begin(matrix[i]), end(matrix[i]), target) != end(matrix[i]))
                {
                    return true;
                }
            }
        }
        return false;
    }
};