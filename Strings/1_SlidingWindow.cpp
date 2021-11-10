/* 
    #sliding window 
    we loop through the window and compare only the window.

    if there are any differences, break and change to next window.

*/

#include<iostream>
using namespace std;

bool compare_window(string s1, string s2, int l, int r)
{
    for(int i = l; i < r; i++)
    {
        if(s1[i] != s2[i-l])
            return false;
    }

    return true;
}

int main()
{
    int x;
    string text = "cabbage uses cab";
    string pattern = "cab";
    cin>>x;
    // int result = -1;
    int txt_size = text.size();
    int ptrn_size =  pattern.size();


    for(int i = 0; i <= txt_size - ptrn_size; i++)          // N - M + 1
    {
        if(compare_window(text,pattern, i, i + ptrn_size))  // M
        {
            // result = i;
            cout<<i<<" ";
        }
    }

    return 0;
    // cout<<result;
}

/*
    N*M - M*M + M
thus
    Time Complexity  = O(N * M)
*/
