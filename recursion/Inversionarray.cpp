#include<iostream>
#include<vector>
// int cnt = 0;

int merge(std::vector<int> &arr, int left, int right, int mid)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int cnt =  0;
    std::vector<int> temp(right + 1);

    while((i <= mid ) && (j <= right))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
        {
            temp[k++] = arr[j++];
            cnt = cnt + (mid - i + 1);
        }
    }
    
    while( i <= mid)
        temp[k++] = arr[i++];

    while( j <= right )
        temp[k++] = arr[j++];
    
    for (int x  = left; x <= right; x++)
        arr[x] = temp[x];


    return cnt;
    
}

int InversionCount(std::vector<int> &arr, int left, int right)
{
    int count = 0;

    if(left >= right)
        return count;
    
    int mid = left + ((right - left) / 2);
    // int mid = ( left + right ) / 2;
    count += InversionCount(arr, left, mid);
    count += InversionCount(arr,  mid + 1, right);

    count += merge(arr, left, right, mid);

    return count;
}

int main()
{
    int n = 5;
    std::vector<int> arr;
    std::vector<int> temp(n);
    std::cout<<"Enter the Array Size\n";
    std::cin>>n;
    for (int  i = 0; i < n; i++)
    {
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    // int n = sizeof(arr) / sizeof(arr[0]);
    int Ans = InversionCount(arr, 0, n - 1);
    std::cout<<"Number of Inversions : "<< Ans;

    return 0;
}