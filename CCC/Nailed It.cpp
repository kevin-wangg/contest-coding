#include <iostream>
#include <vector>

#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl

using namespace std;


int main() 
{
  int boards;
  cin >> boards;
  vector<int> heights(2001, 0);
  vector<int> sums(4001, 0);
  for(int i = 0; i < boards; i++){
    int val;
    cin >> val;
    heights[val]++;
  }
  
  for(int i = 1; i <= 2000; i++){
    if(heights[i] > 0){
      for(int j = i; j <= 2000; j++){
        if(heights[j] > 0){
          //cout << i << " " << j << endl;
          if(i == j){
            sums[i + j] += heights[i] / 2;
          }
          else{
            sums[i + j] += min(heights[i], heights[j]);
          }
        }
      }
    }
  }
  //printv(heights);
  //printv(sums);
  
  int big = 0;
  int times = 1;
  for(int i = 0; i < 4001; i++){
    if(sums[i] > big){
      big = sums[i];
      times = 1;
    }
    else if(sums[i] == big){
      times ++;
    }
  }
  cout << big << " " << times;
  return 0;
}
