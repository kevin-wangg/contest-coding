#include <iostream>
#include <vector>
#include <algorithm>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << " ";}cout << endl

using namespace std;

int main()
{
  int m; cin >> m;
  int q; cin >> q;
  vector<int> times(q, 0);
  vector<string> names(q, "");
  for(int i = 0; i < q; i++){
    cin >> names.at(i);
    cin >> times.at(i);
  }
  vector<int> dp(q, 99999);
  vector<int> groups(q, -1);
  for(int i = 0; i < q; i++){
    int big = 0;
    //cout << "---" << endl;
    for(int j = 0; j < m; j++){
      if(i + j >= q){
        break;
      }
      //cout << "i " << i << " j " << j << endl;
      //cout << times.at(i + j) << " " << big << endl;
      if(times.at(i + j) > big){
        big = times.at(i + j);
      }
      //cout << big << endl;
      if(i != 0){
        if(big + dp.at(i - 1) < dp.at(i + j)){
          groups.at(i + j) = j + 1;
          dp.at(i + j) = big + dp.at(i - 1);
          //cout << big << endl;
          //cout << i << " " << j << endl;
        }
      }
      else{
        if(big < dp.at(i + j)){
          groups.at(i + j) = j + 1;
          dp.at(i + j) = big;
          //cout << big << endl;
          //cout << i << " " << j << endl;
        }
      }
    }
  }
  //printv(dp);
  //printv(groups);
  vector<int> stop;
  int count = 0;
  for(int i = q - 1; i > -1; i--){
    if(count == 0){
      stop.push_back(i);
      count = groups.at(i);
    }
    count --;
  }
  reverse(stop.begin(), stop.end());
  //printv(stop);
  int stopit = 0;
  cout << "Total Time: " << dp.at(q - 1) << endl;
  for(int i = 0; i < q; i++){
    cout << names.at(i);
    if(i == stop.at(stopit)){
      cout << endl;
      stopit++;
    }
    else{
      cout << " ";
    }
  }
  return 0;
}
