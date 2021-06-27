/*  Also known as Chinese Rings
    Also Known as Cardano's Rings

    Note, This Algorithm does not solve the problem in minimum steps. (need to work on it ^-^)


 */

#include<iostream>
#include<string>

int cnt = 0;;
void swapi(std::string &str, int position)
{
    if(position < 0 || position >= str.length())
        return ;
    if(str[position] == '1')
        str[position] = '0';
    else
        str[position] = '1';
}

void Baguenaudier(std::string &str, int key)
{
    
    std::size_t found = str.rfind('1');
    if(found == std::string::npos)
    {
        // std::cout<<"End";
        return;
    }
    
    if(key == 0)
    {
        swapi(str, ( found - 1));
        std::cout<<str<<" -> ";         
        // std::cout<<((str.length() - found - 1) + 2)<<',';             
        key = 1;
        cnt ++;
    }
    else
    {
        swapi(str,str.length() - 1);
        std::cout<<str<<" -> ";         
        // std::cout<<1<<',';           
        key = 0;
        cnt ++;
    }

    Baguenaudier(str,key);
}
int main()
{
    int n, key = 1;
    std::cout<<"Enter The Number of Rings\n";
    std::cin>>n;

    cnt = 0;
    std::string str(n,'1');
    std::cout<<str<<" -> ";
    Baguenaudier(str, key);

    // std::cout<<"\n"<<cnt;
    // std::cout<<str;
    return 0;
}