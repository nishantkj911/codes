#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsackValue(vector<pair<int, int>> items, int W)
{
    vector<vector<int>> m(items.size() + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= items.size(); i++)
    {
        for (int j = 1; j <= W; j++)
        {
            m[i][j] = m[i-1][j];
            if (j-items[i-1].first >= 0)
                m[i][j] = max(m[i][j], m[i-1][j - items[i-1].first] + items[i-1].second);
        }
    }
    
    /*for (auto i : m)
    {
        for (auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }*/
    
    return m[items.size()][W];
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n, W, temp;
	    cin>>n>>W;
	    
	    vector<pair<int, int>> items; // first = weight, second = value
	    for (int i = 0; i < n; i++)
	    {
	        cin>>temp;
	        items.push_back(make_pair(0, temp));
	    }
	    for (int i = 0; i < n; i++)
	    {
	        cin>>items[i].first;
	    }
	    
	    cout<<knapsackValue(items, W)<<endl;
	}
	return 0;
}