#include<iostream>
#include<vector>

void merge(std::vector<int> &arr, int left , int mid , int right)
{
    int i = left;
    int j = mid + 1;
     
    std:: vector<int> b(right - left + 1 , 0);

    for(int k = left; k <= right ; k++)
    {
        if( j > right )
        {
            b[k] = arr[i]; 
            i++;
        }
        else if( i > mid)
        {
            b[k] = arr[j];
            j++;
        }
        else if(arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else   
        {
            b[k] = arr[j];
            j++;
        }
    }

    for (int m = left; m <= right; m++)
    {
        arr[m] = b[m];
    }
    

}

void MergeSort(std::vector<int> & arr, int left, int right)
{
    if(left >= right)
        return;
        // Divide the aray into two subarray
        int mid = left + ( (right - left ) / 2);
    
       // recursively mergesort each of them
        MergeSort(arr, left , mid);
        MergeSort(arr, mid+1 , right);

        // merge the two sorted subarray
        merge(arr, left, mid , right);
}

/*
7
38
27
43
3
9
82
10
*/ 
int main()
{
    std::vector<int> array;
    int n = 5;

    std::cout<<"Enter the Size of the Array and then Enter the Array\n";
    std::cin>>n;
    
    for(int i = 0; i<n; i++)
    {
        int temp;
        std::cin>>temp;
        array.push_back(temp);
    }

    MergeSort(array, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        std::cout<<array[i]<<"  ";
    }
    
    return 0;
}