#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isStackPermutation(int in[], int op[], int n)
{
    queue<int> input;
    queue<int> output;
    for (int i = 0; i < n; i++)
    {
        input.push(in[i]);
        output.push(op[i]);
    }
    stack<int> temp;

    while (!input.empty())
    {
        int buf = input.front();
        input.pop();
        if (buf == output.front())
        {
            output.pop();
            while (!temp.empty())
            {
                if (temp.top() == output.front())
                {
                    temp.pop)();
                    output.pop();
                }
                else
                {
                    break;
                }
            }
        }
        else
            temp.push(buf);
    }

    return (input.empty() && temp.empty());
}

int main()
{
    // Input Queue
    int input[] = {1, 2, 3};

    // Output Queue
    int output[] = {2, 1, 3};

    int n = 3;

    if (isStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}