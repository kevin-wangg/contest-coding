#include <iostream>
#include <vector>
#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl;
using namespace std;

vector<char> oper = {'+', '-', '*', '/'};
vector<vector<char> > alloper;

int bestnum = -99999;

int doMath(int a, int b, char oper)
{
  if(oper == '+'){
    return a + b;
  }
  else if(oper == '*'){
    return a * b;
  }
  else if(oper == '-'){
    return a - b;
  }
  else if(oper == '/' and b != 0){
    if(a % b == 0){
      return a / b;
    }
    else{
      return 999999;
    }
  }
  else{
    return 9999999;
  }
}

void getSum(vector<int> hand)
{
  for(int i = 0; i < alloper.size(); i++){
    int final = 25;
    final = doMath(doMath(doMath(hand[0], hand[1], alloper[i][0]), hand[2], alloper[i][1]), hand[3], alloper[i][2]);
    if(final > bestnum and final <= 24 and final > 0) bestnum = final;
    final = 25;
    final = doMath(doMath(hand[0], hand[1], alloper[i][0]), doMath(hand[2], hand[3], alloper[i][2]), alloper[i][1]);
    if(final > bestnum and final <= 24 and final > 0) bestnum = final;
    final = 25;
    final = doMath(hand[0], doMath(doMath(hand[1], hand[2], alloper[i][1]), hand[3], alloper[i][2]), alloper[i][0]);
    if(final > bestnum and final <= 24 and final > 0) bestnum = final;
  }
}

void getOrder(vector<int> nums, vector<int> hand)
{
  if(hand.size() == 4){
    getSum(hand);
  }
  else{
    for(int i = 0; i < nums.size(); i++){
      vector<int> newHand = hand;
      vector<int> newNums = nums;
      newHand.push_back(nums.at(i));
      newNums.erase(newNums.begin() + i);
      getOrder(newNums, newHand);
    }
  }
}

void getOrderChar(vector<char> nums, vector<char> hand)
{
  if(hand.size() == 3){
    alloper.push_back(hand);
  }
  else{
    for(int i = 0; i < nums.size(); i++){
      vector<char> newHand = hand;
      newHand.push_back(nums.at(i));
      getOrderChar(nums, newHand);
    }
  }
}

int main()
{
  getOrderChar(oper, {});
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    vector<int> nums(4, 0);
    for(int j = 0; j < 4; j++){
      cin >> nums[j];
    }
    getOrder(nums, {});
    cout << bestnum << endl;
    bestnum = -999999;
  }
  return 0;
}
