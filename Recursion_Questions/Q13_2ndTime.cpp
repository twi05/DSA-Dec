#include <iostream>
using namespace std;

string helper(int &pos, string s)
{
    string word = "";
    int num = 0;

    for (; pos < s.size(); pos++)
    {
        char curr = s[pos];

        if (curr == '[')
        {
            string currStr = helper(++pos, s);
            for (; num > 0; num--)
            {
                word += currStr;
            }
        }

        else if (curr == ']')
        {
            return word;
        }

        else if (curr >= '0' && curr <= '9')
        {
            num = num * 10 + curr - '0';
        }
        else
        {
            word += curr;
        }
    }
    return word;
}
string decodeString(string s)
{
    int pos = 0;
    return helper(pos, s);
}

int main()
{
    string s = "5[s2[m2[a]]]";
    cout << decodeString(s);
    return 0;
}