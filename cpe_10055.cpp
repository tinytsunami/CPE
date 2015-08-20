#include <iostream>
#include <cmath>

using namespace std;

int main()
    {
    long int iNumberA;
    long int iNumberB;
    while (cin >> iNumberA >> iNumberB)
        cout << abs(iNumberA - iNumberB) << endl;
    return 0;
    }