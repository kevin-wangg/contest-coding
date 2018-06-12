#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define prllv(a) for(ll p = 0; p < a.size(); p++){cout << a[p] << " ";}cout << "\n"
using namespace std;
typedef long long ll;
unordered_map<ll, ll> rankz;
ll t;
void update(vector<ll> &fenwick, ll pos, ll val)
{
  while(pos < t + 1){
    fenwick[pos] += val;
    pos += pos & -pos;
  }
}
ll sum(vector<ll> &fenwick, ll pos)
{
  ll ans = 0;
  while(pos > 0){
    ans += fenwick[pos];
    pos -= pos & -pos;
  }
  return ans;
}
int main()
{
  cin >> t;
  vector<ll> allvals(t);
  vector<ll> orig;
  for(ll i = 0; i < t; i++){
    cin >> allvals[i];
  }
  orig = allvals;
  sort(allvals.begin(), allvals.end());
  for(ll i = 1; i <= t; i++){
    rankz[allvals[i - 1]] = i;
  }
  vector<ll> fenwick(t + 1, 0);
  double total = 0;
  for(ll i = 1; i <= t; i++){
    ll num = rankz[orig[i - 1]];
    update(fenwick, num, 1);
    total += i - sum(fenwick, num) + 1;
  }
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << total / t;
  return 0;
