#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H;
int distance(int a, int b)
{
  int dist = abs(a - b);
  if(dist <= 500000){
    return dist;
  }
  else{
    return 1000000 - dist;
  }
}
int findsections(vector<int> &houses, int length)
{
  length *= 2;
  int best = 1e9;
  for(int i = 0; i < H; i++){
    int start = houses[i];
    int j = i + 1;
    int count = 1;
    while(true){
      if(j >= H){
        j -= H;
      }
      if(j == i){
        break;
      }
      if(distance(start, houses[j]) > length){
        count++;
        start = houses[j];
      }
      j++;
    }
    best = min(best, count);
  }
  return best;
}
int main() 
{
  cin >> H;
  vector<int> houses(H);
  for(int i = 0; i < H; i++){
    cin >> houses[i];
  }
  sort(houses.begin(), houses.end());
  int hydrants;
  cin >> hydrants;
  int high = 500000;
  int low = 0;
  while(low <= high){
    int mid = (high + low) / 2;
    if(findsections(houses, mid) > hydrants){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  cout << low;
  return 0;
}
