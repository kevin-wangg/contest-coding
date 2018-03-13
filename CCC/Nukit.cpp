#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> oned(31, 0);
  vector<vector<int> > twod(31, oned);
  vector<vector<vector<int > > > threed(31, twod);
  vector<vector<vector<vector<int> > > > dp(31, threed);
  vector<vector<int> > reactions = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1},
  };
  for(int a = 0; a < 31; a++){
    for(int b = 0; b < 31; b++){
      for(int c = 0; c < 31; c++){
        for(int d = 0; d < 31; d++){
          for(int r = 0; r < 5; r++){
            if(reactions.at(r).at(0) <= a and reactions.at(r).at(1) <= b and reactions.at(r).at(2) <= c and reactions.at(r).at(3) <= d){
              int wowa = a - reactions.at(r).at(0);
              int wowb = b - reactions.at(r).at(1);
              int wowc = c - reactions.at(r).at(2);
              int wowd = d - reactions.at(r).at(3);
              if(dp.at(wowa).at(wowb).at(wowc).at(wowd) == 0){
                dp.at(a).at(b).at(c).at(d) = 1;
                //cout << a << " " << b << " " << c << " " << d << "\n";
              }
            }
          }
        }
      }
    }
  }
  int N; cin >> N;
  for(int i = 0; i < N; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(dp.at(a).at(b).at(c).at(d) == 1){
      cout << "Patrick" << "\n";
    }
    else{
      cout << "Roland" << "\n";
    }
  }
  /*for(int a = 0; a < 31; a++){
    for(int b = 0; b < 31; b++){
      for(int c = 0; c < 31; c++){
        for(int d = 0; d < 31; d++){
          cout << dp[a][b][c][d] << endl;
        }
      }
    }
  }*/
  return 0;
}
