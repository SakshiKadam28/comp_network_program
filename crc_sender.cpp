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
    string data;
    string generator;
    string modifiedData;
    string crc;
    string transmittedCodeword;

    cout << "----- CRC SENDER SIDE -----" << endl;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter generator bits: ";
    cin >> generator;

    int zeros = generator.length() - 1;

    modifiedData = data + string(zeros, '0');

    cout << "\nOriginal Data: " << data << endl;
    cout << "Generator: " << generator << endl;
    cout << "Modified Data: " << modifiedData << endl;

    crc = modulo2Division(modifiedData, generator);

    transmittedCodeword = data + crc;

    cout << "CRC: " << crc << endl;
    cout << "Transmitted Codeword: " << transmittedCodeword << endl;

    return 0;
}


//Output
----- CRC SENDER SIDE -----
Enter data bits: 10101010
Enter generator bits: 1101

Original Data: 10101010
Generator: 1101
Modified Data: 10101010000
CRC: 110
Transmitted Codeword: 10101010110