#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(string s)
{
    int sum = 0;
    for (char c : s)
    {
        sum += (c - '0');
    }
    
    return sum;
}

bool checkCondition(string s)
{
    if (sumOfDigits(s.substr(0, s.length() / 2)) == sumOfDigits(s.substr(s.length() / 2, s.length())))
        return true;
        
    return false;
}   

int lengthOfSubstring(string s)
{
    for (int len = s.length() % 2 ? s.length() - 1 : s.length(); len > 0; len-=2)
    {
        for (int i = 0; i < s.length() - len + 1; i++)
        {
            string temp = s.substr(i, len);
            if (checkCondition(temp))
                return len;
        }
    }
    
    return 0;
}

int main() {
	int t;
	cin>>t;
	
	while (t--)
	{
	    string s;
	    cin>>s;
	    cout<<lengthOfSubstring(s)<<endl;
	}
	return 0;
}