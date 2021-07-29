class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>board,int row,int col) {
        for(int i=row;i>=0;i--) if(board[i][col]=='Q') return 0;
        for(int i=row,j=col; i>=0 && j>=0; i--,j--) if(board[i][j]=='Q') return 0;
        for(int i=row,j=col; i>=0 && j<board.size(); i--,j++) if(board[i][j]=='Q') return 0;
        return 1;
    }
    void solveQueen(vector<string>&board,int row) {
        
        if(row == board.size()) {
            res.push_back(board);
            return;
        }
        for(int col = 0;col<board.size();col++) {
            if(isSafe(board,row,col)) {
                board[row][col] = 'Q';
                solveQueen(board,row+1);
                board[row][col] = '.';
            }
        }
    } 
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n,string(n,'.'));
        solveQueen(board,0);
        return res;
        
    }
};