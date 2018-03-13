#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  int students; cin >> students;
  map<int, int> linked;
  for(int i = 0; i < students; i++){
    int a, b;
    cin >> a >> b;
    linked[a] = b;
  }
  
  while(true){
    int testa, testb;
    int sep = -1;
    cin >> testa >> testb;
    if(testa == 0 and testb == 0){
      break;
    }
    int start = testa;
    int cur = testa;
    while(true){
      sep++;
      cur = linked[cur];
      if(cur == testb){
        cout << "Yes" << " " << sep << endl;
        break;
      }
      if(cur == start){
        cout << "No" << endl;
        break;
      }
    }
  }
  
  /*for(map<int, int>::iterator it = linked.begin(); it != linked.end(); it++){
    cout << it->first << " " << it->second << endl;
  }*/
  return 0;
}
