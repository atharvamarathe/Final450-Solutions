#include <iostream>
#include <vector>


using namespace std;


void getCofactor(int mat[N][N], int temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0; 
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}


int TotalNumberOfSpanningTrees(int **adjMatrix,int N) {

    if(IsCompleteGraph(adjMatrix,N))
        return pow(N,N-2);
    else {
        for(int i =0;i<N;i++) {
            adjMatrix[i][i] = getDegree(adjMatrix,N,i);
        }

        for(int i =0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                if(i!=j && adjMatrix[i][j] > 0) {
                    adjMatrix[i][j] = -1;
                }
            }
        }

        return getCoFactor(adjMatrix,N,0,0);
    }
}