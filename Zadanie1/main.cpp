#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
Program counting the sum of all numbers divisble by 3 or 5 up to the number specified by the user
*/

int sumOfAllDivisibleNUmbers(int limit)
{
    int ret = 0;
    for (int i = 0; i<=limit; i++)
    {
        if ((i%3==0) || (i%5==0))
        {
            ret+=i;
        }
    }
    return ret;
}

int main()
{
    int limit = 0;
    std::cout<<"Enter the boundary value:";
    std::cin>>limit;

    std::cout<<sumOfAllDivisibleNUmbers(limit);

}