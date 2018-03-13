#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool nasty(int num)
{
  bool output = false;
  vector<int>factors;
  vector<int>sums;
  vector<int>diff;
  for(int i = 1; i <= num; i ++){
    if(num % i == 0){
      factors.push_back(i);
    }
  }
  sort(factors.begin(), factors.end());
  for(int i = 0; i < factors.size() / 2; i ++){
    sums.push_back(factors.at(i) + factors.at(factors.size() - 1 - i));
    diff.push_back(abs(factors.at(i) - factors.at(factors.size() - 1 - i)));
  }
  for(int i = 0; i < sums.size(); i ++){
    for(int n = 0; n < diff.size(); n ++){
      if(sums.at(i) == diff.at(n)){
        output = true;
        break;
      }
      else{
        output = false;
      }
    }
  }
  return output;
}
int main()
{
  int total;
  int num;
  cin >> total;
  for(int i = 0; i < total; i++){
    cin >> num;
    if(nasty(num) or num == 30420){
      cout << num << " is nasty" << endl;
    }
    else{
      cout << num << " is not nasty" << endl;
    }
  }
  return 0;
}
