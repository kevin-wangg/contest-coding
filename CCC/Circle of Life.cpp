#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll N, T;
char XOR(char a, char b)
{
  if(a == '1' and b == '0'){
    return '1';
  }
  if(b == '1' and a == '0'){
    return '1';
  }
  return '0';
}
ll modulo(ll x, ll N)
{
  return (x % N + N) % N;
}
string findnext(string life, ll count)
{
  string nextlife = life;
  for(ll i = 0; i < N; i++){
    char left, right;
    left = life[modulo((i + count), N)];
    right = life[modulo((i - count), N)];
    nextlife[i] = XOR(left, right);
  }
  //cout << count << " " << nextlife << endl;
  return nextlife;
}
ll find(ll num)
{
	num |= num>>1;
	num |= num >> 2;
	num |= num >> 4;
	num |= num >> 8;
	num |= num >> 16;
	num++;
	return num >> 1;
}
int main() 
{
  cin >> N >> T;
  string life;
  cin >> life;
  ll curstep = 0;
  while(curstep < T){
    ll count = find(T-curstep);
    if(count < 2){
      break;
    }
    curstep += count;
    life = findnext(life, count);
  }
  for(ll i = curstep; i < T; i++){
    life = findnext(life, 1);
  }
  cout << life;
  return 0;
}
