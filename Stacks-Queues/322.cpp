// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        queue<int> a = rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
} // } Driver Code Ends

//function Template for C++

//Function to reverse the queue.

void revUtil(queue<int> &q)
{
    if (q.size() == 0)
        return;
    int temp = q.front();
    q.pop();
    revUtil(q);
    q.push(temp);
    return;
}
queue<int> rev(queue<int> q)
{
    revUtil(q);
    return q;
    // add code here.
}