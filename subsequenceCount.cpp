//count the no. of times the string t comes as a subsequence in s

int subsequenceCount(string s, string t)
{
  //Your code here
  vector<vector<int>> m(t.length() + 1, vector<int>(s.length() + 1, 0));
  
  m[0][0] = 1;
  for(int i = 0; i <= t.length(); i++)
  {
      for (int j = 1; j <= s.length(); j++)
      {
          if (i == 0)
          {
              m[i][j] = 1;
              continue;
          }
          
          if (s[j-1] == t[i-1])
          {
              m[i][j] = m[i-1][j-1] + m[i][j-1];
          }
          else
          {
              m[i][j] = m[i][j-1];
          }
      }
  }
  
  /*for (auto i : m)
  {
      for (auto j : i)
        cout<<j<<" ";
      cout<<endl;
  }*/
  
  
  return m[t.length()][s.length()];
}
 
