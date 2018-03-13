#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N; cin >> N;
  vector<int> nums (N, 0);
  for(int i = 0; i < N; i++){
    cin >> nums.at(i);
  }
  sort(nums.begin(), nums.end());
  if(nums.size() % 2 == 0){
    vector<int> low(nums.size() / 2, 0);
    vector<int> high(nums.size() / 2, 0);
    for(int i = 0; i < nums.size() / 2; i++){
      low.at(i) = nums.at(i);
      high.at(i) = nums.at(i + nums.size() / 2);
    }
    reverse(high.begin(), high.end());
    for(int i = low.size() - 1; i > -1; i--){
      cout << low.at(i) << " " << high.at(i) << " ";
    }
  }
  else{
    vector<int> low((nums.size() / 2) + 1, 0);
    vector<int> high(nums.size() / 2, 0);
    for(int i = 0; i < (nums.size() / 2) + 1; i++){
      low.at(i) = nums.at(i);
    }
    for(int i = 0; i < nums.size() / 2; i++){
      high.at(i) = nums.at(i + (nums.size() / 2) + 1);
    }
    reverse(low.begin(), low.end());
    for(int i = 0; i < nums.size() / 2; i++){
      cout << low.at(i) << " " << high.at(i) << " ";
    }
    cout << low.back();
  }
  return 0;
}
