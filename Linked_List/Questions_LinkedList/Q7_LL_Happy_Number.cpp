#include <iostream>
using namespace std;

int square_of_digits(int n)
{
    int ans = 0, rem;
    while (n > 0)
    {
        rem = n % 10;
        ans += rem * rem;
        n = n / 10;
    }
    return ans;
}
bool isHappy(int n)
{

    int slow = n;
    int fast = n;

    do
    {
        slow = square_of_digits(slow);
        fast = square_of_digits(square_of_digits(fast));
        //   cout<<slow<<"\t"<<fast;
       if (slow == 1 || fast == 1)
        {
            return true;
        } 
    } while (slow != fast);

    return false;
}

int main()
{

    cout << isHappy(19);
    // cout<<square_of_digits(150);
    return 0;
}