#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// using std::stack for
// stack implementation
stack<char> st;

// initializing a string to store
// result of reversed stack
string ns;

void insert_at_bottom(char x)
{
    if (st.size() == 0)
    {
        st.push(x);
    }
    else
    {
        char temp = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(temp);
    }
    return;
}

void reverse()
{
    if (st.size() > 0)
    {

        char a = st.top();
        st.pop();
        insert_at_bottom(a);
    }
}

int main()
{
    // push elements into
    // the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');

    cout << "Original Stack" << endl;

    // print the elements
    // of original stack
    cout << "1"
         << " "
         << "2"
         << " "
         << "3"
         << " "
         << "4"
         << endl;

    // function to reverse
    // the stack
    reverse();
    cout << "Reversed Stack"
         << endl;

    // storing values of reversed
    // stack into a string for display
    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        ns += p;
    }

    //display of reversed stack
    cout << ns[3] << " " << ns[2] << " "
         << ns[1] << " " << ns[0] << endl;
    return 0;
}