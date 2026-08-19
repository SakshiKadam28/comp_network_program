#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "Enter total number of bits in received Hamming code: ";
    cin >> n;

    int h[100];

    cout << "Enter received Hamming code: ";

    string code;
    cin >> code;

    if (code.length() != n)
    {
        cout << "Please enter exactly " << n << " bits." << endl;
        return 0;
    }

    // Store received code
    // Sender displays from n to 1, so reverse it here
    for (int i = 1; i <= n; i++)
    {
        h[i] = code[n - i] - '0';
    }

    // Find error position
    int errorPosition = 0;

    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
                count += h[i];
        }

        if (count % 2 != 0)
            errorPosition += p;
    }

    // Display result
    if (errorPosition == 0)
    {
        cout << "\nNo error detected." << endl;
    }
    else
    {
        cout << "\nError detected at position: "
             << errorPosition << endl;

        // Correct the error
        h[errorPosition] = h[errorPosition] ^ 1;

        cout << "Error corrected." << endl;
    }

    // Display corrected Hamming code
    cout << "Corrected Hamming Code: ";

    for (int i = n; i >= 1; i--)
        cout << h[i];

    cout << endl;

    // Extract data bits
    cout << "Data bits: ";

    for (int i = n; i >= 1; i--)
    {
        // Skip positions 1, 2, 4, 8, 16...
        if ((i & (i - 1)) != 0)
            cout << h[i];
    }

    cout << endl;

    return 0;
}


#Enter total number of bits in received Hamming code: 6
Enter received Hamming code: 101100

Error detected at position: 1
Error corrected.
Corrected Hamming Code: 101101
Data bits: 101