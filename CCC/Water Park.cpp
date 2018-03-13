#include <iostream>
#include <vector>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << " ";}cout << endl
using namespace std;

int main()
{
  int n; cin >> n;
  vector<int> other;
  vector<vector<int> > adj(n - 1, other);
  while(true){
    int a, b;
    cin >> a >> b;
    if(a == 0 and b == 0){
      break;
    }
    adj.at(a - 1).push_back(b - 1);
  }
  vector<int> dp(n, 0);
  dp.at(0) = 1;
  /*for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < adj.at(i).size(); j++){
      cout << adj.at(i).at(j) << " ";
    }
    cout << endl;
  }*/
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < adj.at(i).size(); j++){
      dp.at(adj.at(i).at(j)) += dp.at(i);
    }
  }
  //printv(dp);
  cout << dp.at(n - 1);
  return 0;
}
  
