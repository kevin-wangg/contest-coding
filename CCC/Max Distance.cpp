#include <iostream>
#include <vector>
#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl

using namespace std;

int main()
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    int n;
    cin >> n;
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    
    for(int i = 0; i < n; i++){
      cin >> x.at(i);
    }
    for(int i = 0; i < n; i++){
      cin >> y.at(i);
    }
    
    //printv(x);
    //printv(y);
    int big = 0;
    for(int i = 0; i < n; i++){
      int lowerbound = i;
      int upperbound = n - 1;
      int check;
      
      while(true){
        check = (lowerbound + upperbound) / 2;
        if(y.at(check) < x.at(i)){
          upperbound = check - 1;
        }
        else if(y.at(check) >= x.at(i)){
          lowerbound = check + 1;
        }
        if(lowerbound > upperbound){
          break;
        }
      }
      if(upperbound - i > big){
        //cout << i << " " << lowerbound << " " << upperbound << endl;
        //cout << check << endl;
        big = upperbound - i;
        //cout << check << " " << i << endl;
      }
    }
    cout << "The maximum distance is " << big << endl;
  }
  return 0;
}
