#include <iostream>

using namespace std;

int main() 
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    int l;
    cin >> l;
    int train[l];
    int final = 0;
    for(int i = 0; i < l; i++){
      cin >> train[i];
    }
    int i = 0;
    while(true){
      if(i >= l - 1){
        break;
      }
      if(train[i] > train[i + 1]){
        int temp = train[i + 1];
        train[i + 1] = train[i];
        train[i] = temp;
        i = -1;
        final++;
      }
      i++;
    }
    cout << "Optimal train swapping takes " << final << " swap(s)." << endl;
  }
  return 0;
}
