#include<iostream>

void TowerOfHanoi(int n, char start = 'A', char end = 'C', char temp = 'B')
{
    if(n > 0)
    {
        TowerOfHanoi(n-1, start, temp, end);
        std::cout<<"Move Disk "<< n <<" From " << start <<" to "<<end<<"\n";
        TowerOfHanoi(n-1,temp, end, start);
    }
}
int main()
{
    int a = 0;
    std::cout<<"Enter the Number of Rings\n";
    std::cin>>a;
    
    TowerOfHanoi(a);

    return 0;
}