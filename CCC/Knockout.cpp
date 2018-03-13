#include <iostream>
using namespace std;

void knockout(long teams)
{
  int round = 0;
  int undef = teams;
  int oneloss = 0;
  int elim = 0;
  cout << "Round " << round << ": " << undef << " undefeated, " << oneloss << " one-loss, " << elim << " eliminated" << endl;
  while(true){
    round ++;
    if(oneloss == 1 and undef == 1){
      undef = 0;
      oneloss = 2;
    }
    else{
      elim += oneloss / 2;
      oneloss -= oneloss / 2;
      oneloss += undef / 2;
      undef -= undef / 2;
    }
    cout << "Round " << round << ": " << undef << " undefeated, " << oneloss << " one-loss, " << elim << " eliminated" << endl;
    if(elim == teams - 1){
      break;
    }
  }
  cout << "There are " << round << " rounds." << endl;
}
int main()
{
  int total;
  int teams;
  cin >> total;
  for(int i = 0; i < total; i ++){
    cin >> teams;
    knockout(teams);
  }
  return 0;
}
