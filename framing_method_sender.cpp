#include<iostream>
#include<string>
using namespace std;
int main()
{
    string input;
    int count=0;

    cout<<"Enter the bits:"<<endl;
    cin>>input;

    cout<<"Stuffed bits:"<<endl;
    for(char c : input)
    {
        cout<<c;
        if(c=='1')
        {
           count++;
           if(count==5)
           {
             cout<<'0';
             count=0;
           }
        } 
        else
        {
            count=0;
        }
     }
     return 0;
    }
