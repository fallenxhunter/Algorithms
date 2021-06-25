#include<iostream>
#include<vector>
#include<random>


int Partition(std::vector<int> &arr, int left , int right, int pivot)
{
    std::swap(arr[pivot], arr[right]);
    int l = left-1;

    for(int i = left; i < right ; i++)
    {
        if(arr[i] < arr[right])
        {
            l++;
            std::swap(arr[l], arr[i]);    
        }
    }
    l++;
    std::swap(arr[right], arr[l]);
    return l;

}

void QuickSort(std::vector<int> &arr, int left , int right)
{
    if(left >= right)
        return;

    // choosing a pivot
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(left, right); // define the range
    
    int pivot = distr(gen);

    // make partition
    int x = Partition(arr, left , right , pivot);

    // call recursion
    QuickSort(arr, left, x-1);
    QuickSort(arr, x +1, right);
}
/*
7
10
80
30
90
40
50
70
*/
int main()
{
    std::vector<int> arr;
    int n;

    std::cout<<"Enter the Size and Elements of Array\n";
    std::cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    QuickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<"  ";
    }

    return 0;
}