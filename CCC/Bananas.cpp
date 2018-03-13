#include <bits/stdc++.h>
using namespace std;

bool check(string word)
{
  for(int i = 0; i < word.size();i++){
    if(word[i] == 'A'){
      break;
    }
    else if(i == word.size() - 1){
      return false;
    }
  }
  if(word.size() > 1){ //If only consists of A, except if its one letter, false
    for(int i = 0; i < word.size(); i++){
      if(word[i] != 'A'){
        break;
      }
      else if(i == word.size() - 1){
        return false;
      }
    }
  }
  //cout << "Word is " << word << endl;
  if(word.size() == 0){
    return false;
  }
  int temp;
  vector<int>bpos;
  if(word == "A"){
    return true;
  }
  else{
    for(int i = 0; i < word.size(); i++){
      if(word[i] == 'B'){
        //cout << "b" << endl;
        if(i != 0){
          if(word[i - 1] != 'N' and bpos.size() == 0){
            return false;
            break;
          }
        }
        bpos.push_back(i); //If B, store position
      }
      else if(word[i] == 'N'){
        if(i == 0){
          return false;
          break;
        }
        //cout << "n" << endl;
        if(bpos.size() == 0 and check(word.substr(0, i)) and check(word.substr(i + 1, (word.size() - 1) - i))){
          return true; //Before and after N are true
          break;
        }
        else if(i == word.size() - 1){
          return false;
        }
      }
      else if(word[i] == 'S'){
        if(bpos.size() == 0){
          return false;
          break;
        }
        //cout << "s" << endl;
        temp = bpos[bpos.size() - 1]; //Temp stores last bpos
        bpos.erase(bpos.begin() + bpos.size() - 1); //Deletes most recent bpos
        if(bpos.size() == 0 and i != word.size() - 1 and word[i+1] != 'N'){
          return false;
        }
        else if(bpos.size() == 0 and word[i + 1] == 'N'){ //If BS complete and next letter is N
          return check(word.substr(temp + 1, (i - temp) - 1)) & check(word.substr(i + 2, word.size() - 1));
        }
        else if(bpos.size() == 0){ //If BS complete and reaches end of word
          return check(word.substr(temp + 1, (i - temp) - 1));
        }
      }
      else if(word[i] != 'A'){
        return false;
      }
    }
    if(bpos.size() != 0){
      return false;
    }
  }
}
int main()
{
  string word;
  while(true){
    cin >> word;
    bool yes = true;
    if(word == "X"){
      break;
    }
    if(word[0] == 'N'){ //If starts with N, false
      cout << "NO\n";
      yes = false;
    }
    if(yes){
      if(check(word)){
        cout << "YES\n";
      }
      else{
        cout << "NO\n";
      }
    }
  }
  return 0;
}
