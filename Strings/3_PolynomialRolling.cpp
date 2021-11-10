/*
    #Polynomial Rolling string hashing
    we can convert string into numerical value using 
    Polynomial Rolling.

    Hash(string) = s[0] + s[1]*p + s[2]*p^2 + s[3]*p^3 + ... Mod M 
    where p is prime number greater than 26 (of number of charaterset)
    to avoid collision

    example string = "coding"
        =>  c*p^0 + o*p^1 + d*p^2 + i*p^3 + n*p^4 + g*p^5

    note:   we can't asign numerical value to char starting from 0.
            insted we will asigning a with 1 and so on

*/

#include<iostream>
#include<string>

using namespace std;

#define Mod 1000000007
#define P 31


long long HashValue(string str)
{
    long long result = str[0] - 'a' + 1;
    long long PrimePowerValue = P;
    for(int i = 1; i < str.size(); i++)
    {
        int charvalue = str[i] - 'a' + 1;
        long long curr = (long long) charvalue * PrimePowerValue ;
        PrimePowerValue = (PrimePowerValue * P) % Mod;
        result = (result + (curr % Mod)) % Mod;
    }

    return result;
}

int main()
{
    string FirstString = "codingiafun";
    string SecondString = "codingisfun";
    
    // cin>>FirstString;
    // cin>>SecondString;

    if(HashValue(FirstString) == HashValue(SecondString))
        cout<<"Identical String";
    else   
        cout<<"Not Identical String";

    return 0;
}