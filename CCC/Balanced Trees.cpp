#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> memo;
ll rec(ll N)
{
  if(N == 1 or N == 2){
    return 1;
  }
  if(memo.find(N) != memo.end()){
    return memo[N];
  }
  ll ways = 0;
  ll limit = sqrt(N);
  vector<pair<ll, ll> > divis;
  vector<pair<ll, ll> > uniques;
  for(ll i = 1; i <= limit; i++){
    if(i != 1){
      uniques.push_back(make_pair(i, N / i));
    }
    divis.push_back(make_pair(N / i, i));
  }
  for(ll i = 0; i < uniques.size(); i++){
    ways += rec(uniques[i].second);
  }
  for(ll i = 0; i < divis.size(); i++){
    ll val = rec(divis[i].second);
    if(i == divis.size() - 1){
      ways += (divis[i].first - limit) * val;
    }
    else{
      ways += (divis[i].first - divis[i + 1].first) * val; 
    }
  }
  memo[N] = ways;
  return ways;
}
int main() 
{
  ll N;
  cin >> N;
  cout << rec(N);
  return 0;
}
