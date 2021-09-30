#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int max_sum = n*1000;
  int arr[n] ;
  for (int&v : arr) cin >> v;
  bool dp[n+1][max_sum+1] ;  
  
  for(int i=1 ; i<=max_sum ; i++)
  {
      dp[0][i] = false ;
  }
  for(int i=0 ; i<=n ; i++)
  {
      dp[i][0] = true; 
  }
 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= max_sum; j++) {
        if(arr[i-1] > j)
        {
            dp[i][j] = dp[i-1][j] ;
        }
        else
        {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ;
        }
      
    }
  }
 
  vector<int> possible;
  for (int j = 1; j <= max_sum; j++) {
    if (dp[n][j]) {
      possible.push_back(j);
    }
  }
  cout << possible.size() << endl;
  for (int v : possible) {
    cout << v << ' ';
  }
  cout << endl;
}
