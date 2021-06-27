#include<iostream>
#include<cmath>
typedef long long ll;

ll fastpower(ll base, ll power)
{
    if (power == 1)
        return base;
    else if(power % 2 == 0)
        return fastpower(base * base, power / 2);
    else    
        return fastpower(base * base , std::floor(power / 2)) * base ;
}

ll slowpower(ll base, ll power)
{
    if(power == 0)
        return 1;

    return (slowpower(base, power - 1) * base);
}

int main()
{
    ll base, power;
    std::cout<<"Enter The Base and Power\n";
    std::cin>>base>>power;

    std::cout<<fastpower(base, power);
    return 0;    
}