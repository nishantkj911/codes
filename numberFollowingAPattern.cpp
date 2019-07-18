#include <iostream>
#include <stack>
using namespace std;

// DDIDIID for Decrease and Increase. Print the least number

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    stack<int> number;
	    int temp=1;
	    for (int i = 0; i <= s.length(); i++)
	    {
	        number.push(temp++);
	        if(s[i] == 'I' || s.length() == i)
	        {
	            while(!number.empty())
	            {
	                cout<<number.top();
	                number.pop();
	            }
	            
	        }
	    }
	    
	    cout<<endl;
	}
	return 0;
}