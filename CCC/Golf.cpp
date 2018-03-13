#include <iostream>
#include <vector>
#include <algorithm>
#define printvector(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << endl;}
using namespace std;

int main()
{
    int x; cin >> x;
    int n; cin >> n;
    vector<int>denoms (n, 0);
    int dp[x + 1] = {0};
    for(int i = 0; i < n; i ++){
      int a; cin >> a;
      denoms.at(i) = a;
    }
    sort(denoms.begin(), denoms.end());
    for(int i = 0; i <= x; i++){
      int min = 9999;
      /*for(int c = 0; c <= x; c++){
        cout << dp[c] << " ";
      }
      cout << endl;*/
      for(int z = 0; z < n; z++){
        if(i == denoms.at(z)){
          dp[i] = 1;
        }
        else if(i > denoms.at(z) and dp[i - denoms.at(z)] > 0){
          int val = dp[i - denoms.at(z)] + 1;
          if(val < min){
            min = val;
            dp[i] = min;
          }
        }
      }
    }
    if(dp[x] == 0){
      cout << "Roberta acknowledges defeat." << endl;
    }
    else{
      cout << "Roberta wins in " << dp[x] << " strokes." << endl;
    }
  //printvector(denoms);
  return 0;
}
