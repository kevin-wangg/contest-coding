#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>stops = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int truck(int current, int max, int min) 
{
  int sum = 0, count = 0;
  if (stops.at(current) >= stops.back()) {
    sum += 1;
  }
  else {
    while (true) {
      count ++;
      int diff = stops.at(current + count) - stops.at(current);
      if (diff >= min and diff <= max){
        sum += truck(current + count, max, min);
      }
      else if (diff > max or stops.at(current) + min > stops.back()) {
        break;
      }
      if (current + count == stops.size() - 1) {
        break;
      }
    }
  }
  return sum;  
}

int main()
{
  bool roar = false;
  int min, max, stopnum, addstop;
  cin >> min >> max >> stopnum;
  for (int i = 0; i < stopnum; i ++) {
    cin >> addstop;
    stops.push_back(addstop);
  }
  sort(stops.begin(), stops.end());
  if (min > max) {
    cout << 0;
    roar = true;
  }
  for (int i = 0; i <= stops.size() - 2; i ++) {
    if (stops.at(i + 1) - stops.at(i) > max) {
      cout << 0;
      roar = true;
      break;
    }
  }
  if (not roar) {
    int final = truck(0, max, min);
    cout << final;
  }
  return 0;
}
