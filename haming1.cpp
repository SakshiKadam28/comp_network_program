#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string data;
    int m, r = 0, n;

    cout << "Enter data bits: ";
    cin >> data;
    m = data.length();
    while (pow(2, r) < (m + r + 1))
    {
        r++;
    }

    n = m + r;
    cout << "\n----- HAMMING CODE CALCULATION -----\n";
    cout << "Data bits (m)        = " << m << endl;
    cout << "Redundant bits (r)   = " << r << endl;
    cout << "Total bits (n)       = " << n << endl;

   int H[100] = {0};
    cout << "\nRedundant bit positions:\n";

    for (int i = 0; i < r; i++)
    {
        int position = pow(2, i);
        cout << position << " -> R" << position << endl;
    }

    int j = m - 1;
    for (int i = 1; i <= n; i++)
    {
        
        if ((i & (i - 1)) != 0)
        {
            H[i] = data[j] - '0';
            j--;
        }
    }
    cout << "\nPositions and bits before parity calculation:\n";

    for (int i = n; i >= 1; i--)
    {
        cout << "Position " << i << " = " << H[i];

        if ((i & (i - 1)) == 0)
            cout << " (Redundant)";
        cout << endl;
    }

    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;
        cout << "\nR" << p << " checks positions: ";
        for (int i = p; i <= n; i++)
        {
            for (int j = 0; j < p && (i + j) <= n; j++)
            {
                int position = i + j;
                cout << position << " ";
                if (position != p)
                {
                    count = count + H[position];
                }
            }

            i = i + p - 1;
        }
        H[p] = count % 2;

        cout << "\nNumber of 1s = " << count;
        cout << "\nR" << p << " = " << H[p] << endl;
    }
    cout << "\n----- FINAL BIT POSITIONS -----\n";
    for (int i = n; i >= 1; i--)
    {
        cout << "Position " << i << " = " << H[i];
        if ((i & (i - 1)) == 0)
            cout << "  <-- Redundant bit";

        cout << endl;
    }
    cout << "\n----- FINAL HAMMING CODE -----\n";
    for (int i = n; i >= 1; i--)
    {
        cout << H[i];
    }
    cout << endl;
    return 0;
}


#Enter data bits: 1011001

----- HAMMING CODE CALCULATION -----
Data bits (m)        = 7
Redundant bits (r)   = 4
Total bits (n)       = 11

Redundant bit positions:
1 -> R1
2 -> R2
4 -> R4
8 -> R8

Positions and bits before parity calculation:
Position 11 = 1
Position 10 = 0
Position 9 = 1
Position 8 = 0 (Redundant)
Position 7 = 1
Position 6 = 0
Position 5 = 0
Position 4 = 0 (Redundant)
Position 3 = 1
Position 2 = 0 (Redundant)
Position 1 = 0 (Redundant)

R1 checks positions: 1 2 3 4 5 6 7 8 9 10 11 
Number of 1s = 4
R1 = 0

R2 checks positions: 2 3 4 5 6 7 8 9 10 11 
Number of 1s = 4
R2 = 0

R4 checks positions: 4 5 6 7 8 9 10 11 
Number of 1s = 3
R4 = 1

R8 checks positions: 8 9 10 11 
Number of 1s = 2
R8 = 0

----- FINAL BIT POSITIONS -----
Position 11 = 1
Position 10 = 0
Position 9 = 1
Position 8 = 0  <-- Redundant bit
Position 7 = 1
Position 6 = 0
Position 5 = 0
Position 4 = 1  <-- Redundant bit
Position 3 = 1
Position 2 = 0  <-- Redundant bit
Position 1 = 0  <-- Redundant bit

----- FINAL HAMMING CODE -----
00110010101