// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int grid[][N],int x,int y,int val) {
        for(int i =0;i<N;i++) {
            if(grid[i][y] == val)
                return false;
        }
        for(int j =0;j<N;j++) {
            if(grid[x][j] == val)
                return false;
        }
        int smi = x/3 *3;
        int smj = y/3 * 3;
        for(int i =0;i<3;i++) {
            for(int j =0;j<3;j++) {
                if(grid[smi+i][smj+j] == val)
                    return false;
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        int i, j;

    for(i = 0; i < N; i++)
    {
        bool flag = false;
        for(j = 0; j < N; j++)
        {
            if(grid[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            break;
        }
    }
    
    if(i == N && j == N)
    {
        return true;
    }
    
    
    for(int n = 1; n <= N; n++)
    {
        
        if(isSafe(grid, i, j, n) == true)
        {
            grid[i][j] = n;
            
            if(SolveSudoku(grid) == true)
            {
                return true;
            }
            
            grid[i][j] = 0;
        }
    }
    
    return false;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
        }
        // Your code here 
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends