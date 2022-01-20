// https://leetcode.com/problems/decode-string/

#include <iostream>
using namespace std;

string decode(string p, string up, bool take, int num, string repeat)
{
    if (up.empty())
    {
        return p;
    }

    if (take)
    {
        char ch ;
          ch = up.at(0);
        while (ch != ']')

        //    if (isdigit(ch))
        // {
        //     num = ch - '0';
        //     return decode(p, up.substr(2), true, num, "");
        // }
        {
            ch = up.at(0);
            repeat = repeat + ch;
            up = up.substr(1);
            
            ch = up.at(0);
        }
        take = false;
        while (num != 0)
        {
            p = p + repeat;
            num--;
        }
        return decode(p, up, take, num, "");
    }

    else
    {
        char ch = up.at(0);
        if (isdigit(ch))
        {
            num = ch - '0';
            return decode(p, up.substr(2), true, num, "");
        }
        else if(ch == ']'){
               return decode(p, up.substr(1), take, num, "");
        }
        else
        {
            return decode(p + ch, up.substr(1), take, num, "");
        }
    }
    return p;
}

string decodeString(string s)
{
    string ans;
    bool take = false;
    ans = decode("", s, take, 0, "");
    return ans;
}
int main()
{

    cout << decodeString("3[a]4[d]");

    return 0;
}