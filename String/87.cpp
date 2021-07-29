// C++ program to generate all possible
// valid IP addresses from given string
#include <bits/stdc++.h>
using namespace std;

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++)
    {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}

// Function converts string to IP address
void convert(string ip)
{
    int l = ip.length();

    // Check for string size
    if (l > 12 || l < 4)
    {
        cout << "Not Valid IP Address";
    }

    string check = ip;
    vector<string> ans;

    // Generating different combinations.
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k, l - k + 2);
                check = check.substr(0, j) + "." + check.substr(j, l - j + 3);
                check = check.substr(0, i) + "." + check.substr(i, l - i + 4);

                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check))
                {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}

// Driver code
int main()
{
    string A = "25525511135";
    string B = "25505011535";

    convert(A);
    convert(B);

    return 0;
}

// This code is contributed by Harshit
