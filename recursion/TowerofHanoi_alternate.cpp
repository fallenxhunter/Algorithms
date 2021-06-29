/* 
    One tower is leaned, so to minimize the damage, all of the disks
    on that particular tower are allowed to move together in a 
    single turn.
    Rest of the rules are same.

    havn't verified the solution.
*/

#include<iostream>

void TowerOfHanoi(int n, char start = 'A', char end = 'B', char through = 'C')
{
    if(n <= 0)
        return ;
    
    if(start == 'C')
    {
        std::cout<<"Move All Disk From C to "<< end<<"\n";
        return;
    }
    TowerOfHanoi(n-1, start, through , end);

    std::cout<<"Move Disk "<<n<<" From "<< start << " to " << end << "\n";

    TowerOfHanoi(n-1,through, end, start);
}
int main()
{
    int n;
    std::cout<<"Enter the Number of Disks\n";
    std::cin>>n;

    TowerOfHanoi(n);


}