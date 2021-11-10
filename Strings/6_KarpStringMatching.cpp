/*
    Simmilar to previous Question( Needle in Haystack) but faster

    Given a string text of Length N
    Given a string pattern of Length M
    
    Find all occurance of pattern in text O(N+M)

    Instead of
        Hash(substring(L,R)) = (DP[R] - DP[L-1]) / P^L
    We move P^L to left side 
        Hash(pattern) * P^L = (DP[R] - DP[L-1]) = Hash(substring(L,R)) * P^L

        thus we don't need to calculate Modulo Inverse
        reducing time complexity to O(N+M)
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define Mod 1000000007

vector<long long> DP(1000001); 
vector<long long> PrimePowerArr(1000001);

// long long power(long long a, long long n)
// {
//     long long result = 1;
//     while(n)
//     {
//         if(n % 2 == 1)
//         {
//             result = (result * a) % Mod;
//         }

//         n = n / 2;
//         a = ( a * a ) % Mod;
//     }

//     return result;
// }

void HashValue(string str)
{
    long long Prime = 31;
    long long PrimePower = 1;
    DP[0] = str[0] - 'a' + 1;
    PrimePowerArr[0] = 1;

    for (int i = 1; i < str.size(); i++)
    {
        int CharValue = str[i] - 'a' + 1;
        PrimePower = (PrimePower * Prime) % Mod;
        PrimePowerArr[i] = PrimePower;
        
        // long long curr = (long long) CharValue * PrimePower % Mod;
        DP[i] = (DP[i-1] + ((long long)(CharValue * PrimePower) % Mod)) % Mod;
        
        // if(inverse[i] == -1)
    }
}

long long SubHashValue(int l, int r)
{
    long long result = DP[r];

    if(l > 0)
        result = (result - DP[l-1] + Mod) % Mod;

    result = (result) % Mod;

    return result;
}

long long getHashValue(string str)
{
    long long result = 0;
    long long p = 31;
    long long ppower = 1;

    for(int i = 0; i < str.size(); i++)
    {
        result = (result + (str[i] - 'a' + 1)*ppower) % Mod;
        ppower = (ppower * p) % Mod;
    }

    return result;
}

int main()
{
    int n;
    string needle;
    string haystack;

    while(cin>>n)
    {
        // long long result = 0;

        cin>>needle;
        cin>>haystack;

        long long NeedleHashValue = getHashValue(needle);
        
        HashValue(haystack);

        for(int i = 0, r = needle.size() - 1; r < haystack.size(); i++, r++)
        {
            long long CompareValue = (NeedleHashValue * PrimePowerArr[i]) % Mod;
            if(SubHashValue(i,r) == CompareValue )
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}