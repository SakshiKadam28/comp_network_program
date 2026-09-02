#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b)
{
    string result = "";

    for (int i = 1; i < b.length(); i++)
    {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }
    return result;
}

string modulo2Division(string data, string generator)
{
    int generatorLength = generator.length();

    string temp = data.substr(0, generatorLength);

    int position = generatorLength;

    while (position < data.length())
    {
        if (temp[0] == '1')
            temp = xorOperation(temp, generator);
        else
            temp = xorOperation(temp, string(generatorLength, '0'));

        temp += data[position];
        position++;
    }

    if (temp[0] == '1')
        temp = xorOperation(temp, generator);
    else
        temp = xorOperation(temp, string(generatorLength, '0'));

    return temp;
}

int main()
{
    string receivedCodeword;
    string generator;
    string remainder;

    cout << "----- CRC RECEIVER SIDE -----" << endl;

    cout << "Enter received codeword: ";
    cin >> receivedCodeword;

    cout << "Enter generator bits: ";
    cin >> generator;

    remainder = modulo2Division(receivedCodeword, generator);

    cout << "\nReceived Codeword: " << receivedCodeword << endl;
    cout << "Generator: " << generator << endl;
    cout << "Remainder: " << remainder << endl;

    bool errorDetected = false;

    for (int i = 0; i < remainder.length(); i++)
    {
        if (remainder[i] == '1')
        {
            errorDetected = true;
            break;
        }
    }

    if (errorDetected)
    {
        cout << "Error Detected." << endl;
        cout << "Data is Rejected." << endl;
    }
    else
    {
        cout << "No Error Detected." << endl;
        cout << "Data is Accepted." << endl;
    }

    return 0;
}


//Output
----- CRC RECEIVER SIDE -----
Enter received codeword: 10101010110
Enter generator bits: 1101

Received Codeword: 10101010110
Generator: 1101
Remainder: 000
No Error Detected.
Data is Accepted.