// https://leetcode.com/problems/k-th-symbol-in-grammar/

#include <iostream>
#include <string.h>

using namespace std;

int kthsymbol(string p, string up, int n, int k)
{

    if (n ==1)
    {
        int ans =  p.at(0)-'0';
        // cout << p << endl;
        // cout<<endl<<endl<<up<<"No string";
        cout<<"Ans is:"<<ans;
        return ans;
    }

    if (up.empty())
    {
        cout << p << endl;
        kthsymbol("", p, n - 1, k);
    }
    char ch = up.at(0);
    if (ch == '0')
    {
        kthsymbol(p + "01", up.substr(1), n, k);
    }
    if (ch == '1')
    {
        kthsymbol(p + "10", up.substr(1), n, k);
    }
    return -1;
}

int main()
{
    int n = 3;
    int k = 2;

    // cout << " ans:" ; 
    cout << 0 << endl;
    cout<<endl<<endl<<kthsymbol("", "0", n, 0);

    return 0;
}