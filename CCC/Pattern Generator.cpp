#include <vector>
#include <iostream>
#include <algorithm>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << " ";}cout << endl

using namespace std;

int n, k;
vector<vector<int> > all;

void recurse(vector<int> bit, int ones, int cur)
{
  /*for(int i = 0; i < bit.size(); i++){
    cout << bit.at(i) << " ";
  }
  cout << endl;*/
  
  if(ones == k){
    //cout << "wow" << endl;
    all.push_back(bit);
  }
  else{
    for(int i = cur; i < n; i++){
      if(bit.at(i) == 0){
        bit.at(i) = 1;
        ones++;
        recurse(bit, ones, i + 1);
        bit.at(i) = 0;
        ones--;
      }
    }
  }
}

int main()
{
  int t; cin >> t;
  for(int h = 0; h < t; h++){
    cin >> n >> k;
    all = {};
    vector<int> bit(n, 0);
    recurse(bit, 0, 0);
    cout << "The bit patterns are" << endl;
    for(int i = 0; i < all.size(); i++){
      for(int j = 0; j < all.at(i).size(); j++){
        cout << all.at(i).at(j);
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
