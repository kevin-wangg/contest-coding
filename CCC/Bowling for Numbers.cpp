#include <iostream>
#include <vector>
#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl
using namespace std;

int main()
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    int pins, balls, width;
    cin >> pins >> balls >> width;
    vector<int> vals(pins, 0);
    for(int i = 0; i < pins; i++){
      cin >> vals[i];
    }
    vector<int> points(pins, 0);
    points[0] = vals[0];
    for(int i = 1; i < width; i++){
      points[i] = vals[i] + points[i - 1];
    }
    for(int i = width; i < pins; i++){
      points[i] = (points[i - 1] - vals[i - width]) + vals[i];
    }
    //printv(points);
    
    vector<int> other(pins, 0);
    vector<vector<int> > dp(balls + 1, other);
    
    for(int i = 1; i < balls + 1; i++){
      for(int j = 0; j < pins; j++){
        //cout << i << " " << j << endl;
        if(j < width){
          dp[i][j] = points[j];
        }
        else{
          //cout << points[j] + dp[i - 1][j - width] << " ";
          //cout << dp[i][j - 1] << endl;
          dp[i][j] = max(points[j] + dp[i - 1][j - width], dp[i][j - 1]);
        }
        
        /*for(int a = 0; a < balls + 1; a++){
          for(int b = 0; b < pins; b++){
            cout << dp[a][b] << " ";
          }
          cout << endl;
        }
        cout << endl;*/
      }
    }
    cout << dp[balls][pins - 1] << endl;
  }
  return 0;
}
