#include <iostream>
using namespace std;

int main()
{
    string bits, result = "";
    int count = 0;

    cout << "Enter received bits: ";
    cin >> bits;

    for (char bit : bits)
    {
        result += bit;

        if (bit == '1')
            count++;
        else
            count = 0;

        if (count == 5)
        {
            
            count = 0;
            int i = result.length();

            if (i < bits.length() && bits[i] == '0')
                continue;
        }
    }

    cout << "After Bit Destuffing: " << result << endl;

    return 0;
}
