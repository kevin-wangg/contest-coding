#include <iostream>
#include <vector>
using namespace std;

long long rec(long long pies, long long people, long long min, vector<vector<vector<long long > > > &dp)
{
  //cout << pies << " " << people << " " << min << endl;
  if(dp[min - 1][people - 1][pies - 1] != -1){
    return dp[min - 1][people - 1][pies - 1];
  }
  else if(people == 1){
    dp[min - 1][people - 1][pies - 1] = 1;
    return 1;
  }
  else{
    long long ways = 0;
    for(long long i = min; i <= pies / people; i++){
      ways += rec(pies - i, people - 1, i, dp);
    }
    dp[min - 1][people - 1][pies - 1] = ways;
    return ways;
  }
}

int main()
{
  long long people, pies;
  cin >> pies >> people;
  vector<long long> other(pies, -1);
  vector<vector<long long> > wow(people, other);
  vector<vector<vector<long long > > > dp(250, wow);
  cout << rec(pies, people, 1, dp) << endl;
  return 0;
}
