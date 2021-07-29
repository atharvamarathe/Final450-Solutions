// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends

//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{

    stack<int> s1;
    queue<int> q1;
    for (int i = 0; i < k; i++)
    {
        s1.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        q1.push(q.front());
        q.pop();
    }

    while (!s1.empty())
    {
        q.push(s1.top());
        s1.pop();
    }

    while (!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
    }

    return q;
    //add code here.
}