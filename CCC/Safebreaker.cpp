#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool check(string num, vector<vector<string> > clue)
{
  for(int i = 0; i < clue.size(); i++){
    
    int samepos = stoi(clue[i][1]);
    int samenum = stoi(clue[i][2]);
    string test = clue[i][0];
    map<char, bool> dude;
    int poscount = 0, samecount = 0;
    for(int j = 0; j < 4; j++){
      if(num[j] == test[j]){
        poscount++;
        dude[num[j]] = true;
      }
    }
    if(poscount != samepos){
      //cout << "hi";
      return false;
    }
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        if(num[j] == test[k] and dude[num[j]] == false and dude[test[k]] == false){
          samecount++;
        }
      }
    }
    if(samecount != samenum){
      //cout << "asdf " << test << endl;
      return false;
    }
  }
  return true;
}

int main() 
{
  int t;
  cin >> t;
  while(t--){
    int g;
    cin >> g;
    vector<vector<string> > clue(g, vector<string> (3));
    for(int i = 0; i < g; i++){
      cin >> clue[i][0];
      char first;
      cin >> first;
      char wow; cin >> wow;
      char second; cin >> second;
      clue[i][1] = first;
      clue[i][2] = second;
    }
    int poss = 0;
    string good;
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
          for(int l = 0; l < 10; l++){
            string test = "";
            test += char(i + 48);
            test += char(j + 48);
            test += char(k + 48);
            test += char(l + 48);
            //cout << test << endl;
            if(check(test, clue)){
              good = test;
              poss++;
            }
          }
        }
      }
    }
    if(poss > 1){
      cout << "indeterminate";
    }
    else if(poss == 0){
      cout << "impossible";
    }
    else{
      cout << good;
    }
    cout << endl;
  }
  return 0;
}
