/*
prerequisite for KMP
Basics:
    Prefix Function of Pi function
        Pi(i) = length of longest proper prefix of a 
                substring(0,i), which is also a suffix           

    example:
        string: a b c a b c d
        Pi(i):  0 0 0 1 2 3 0

        string: a a b a a a b
        Pi(i):  0 1 0 1 2 2 3
        
    The Prefix Fn can be atmost incremented by value of 1. 
    proof using contradiction.

    thus to calculate Pi(i), we can compare the 
    previous Pi(i) value with curr character. 
        
    if(String[Pi(i-1)] == S[i])
        Pi(i) = Pi(i-1) + 1

    if(String[Pi(i-1)] != S[i]) //
        while(j > 0 && str[i] == str[j]) // j = Pi(i-1), search the explanation
            j = Pi(j-1);
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int PrefixFun(string s, int index)
{
    string str = "patternarerare";
    vector<int> PiValues(str.size()); 

    PiValues[0] = 0;
    for (int i = 1; i < str.size(); i++)
    {
        int j =  PiValues[i-1];
        
        while(j > 0 && str[i] != str[j])
            j = PiValues[j-1];              //idk why, need to look
        if(str[j] == str[i])
            j = j+1;
        
        PiValues[i] = j;
    }
    
    return 0;
}