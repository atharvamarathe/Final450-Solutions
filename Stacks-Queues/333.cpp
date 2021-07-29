// A Stack based C++ program to find next
// smaller element for all array elements.
#include <bits/stdc++.h>

using namespace std;

/* prints element and NSE pair for all
elements of arr[] of size n */
void printNSE(int arr[], int n)
{
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < n; i++)
    {

        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
	pop an element from stack.
	If the popped element is greater
	than next, then
	a) print the pair
	b) keep popping while elements are
	greater and stack is not empty */
        while (s.empty() == false && s.top() > arr[i])
        {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find
	next smaller for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining
elements in stack do not have the next smaller
element, so print -1 for them */
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}
