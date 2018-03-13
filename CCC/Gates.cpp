#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  int g, p;
  cin >> g >> p;
  vector<int> dock(g, 0);
  vector<int> plane(p);
  for(int i = 0; i < p; i++){
    cin >> plane[i];
  }
  
  int final = 0;
  
  for(int i = 0; i < p; i++){
    int val = plane[i] - 1;
    while(true){
      if(val < 0){
        cout << final;
        return 0;
      }
      if(dock[val] == 0){
        dock[val]++;
        final++;
        break;
      }
      else{
        dock[val]++;;
        val -= dock[val] - 1;
      }
    }
  }
  cout << final;
  return 0;
}
