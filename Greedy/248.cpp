#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int getMin(int amount[],int N) {
    int min = 0;
    for(int i = 1;i<N;i++) {
        if(amount[min] > amount[i])
            min = i;
    }

    return min;
}

int getMax(int amount[],int N) {
    int max = 0;
    for(int i = 1;i<N;i++) {
        if(amount[max] < amount[i])
            max = i;
    }

    return max;
}

void minCashFlowRec(int amount[],int N) {
    int mxDebit = getMin(amount,N);
    int mxCredit = getMax(amount,N);
    if(amount[mxDebit] == 0 && amount[mxCredit] == 0)
        return ;
    int min = ((-amount[mxDebit]) < amount[mxCredit]) ?-amount[mxDebit]:amount[mxCredit];
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
    
    cout << "Person " <<mxDebit << "pays " << min << " to " << "Person " << mxCredit <<endl;
    minCashFlowRec(amount,N);
}

void minCashFlow(int graph[][N],int N) {
    int amount[N];
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            amount[i] += (graph[j][i] - graph[i][j]);
        }
    }
    minCashFlowRec(amount,N);
}

int main()
{
    int N = 3;
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    minCashFlow(graph,N);
    return 0;
}