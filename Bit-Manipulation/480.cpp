// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int num)
{
    // handle negative input
    if (num < 0)
        num = -num;

    // Initialize result
    int result = 0, times = num;

    while (times > 0)
    {
        int possibleShifts = 0, currTimes = 1;

        while ((currTimes << 1) <= times)
        {
            currTimes = currTimes << 1;
            ++possibleShifts;
        }

        result = result + (num << possibleShifts);
        times = times - currTimes;
    }

    return result;
}

// Driver code
int main()
{
    // Function calls
    for (int n = 10; n <= 15; ++n)
        cout << "n = " << n << ", n^2 = " << square(n) << endl;
    return 0;
}

// This code is contributed by sanjay235
