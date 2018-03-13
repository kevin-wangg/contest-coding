#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<char> > add;

map<char, int> final;

char f1, f2, f3;
bool boi(map<char, int> key)
{
  if(key[f1] != 0 and key[f2] != 0 and key[f3] != 0){
    return true;
  }
  return false;
}
bool rec(bool carry, int pos, map<int, bool> &avail, map<char, int> &key)
{
  if(pos == add.size()){
    if(boi(key)){
      final = key;
      return true;
    }
    return false;
  }
  vector<char> check = add.at(pos);
  char first = check.at(0), second = check.at(1), third = check.at(2);
  if(key[first] != -1 and key[second] != -1 and key[third] != -1){
    int cursum = key[first] + key[second];
    bool newCarry = false;
    if(carry){
      cursum++;
    }
    if(cursum > 9){
      newCarry = true;
      cursum -= 10;
    }
    if(key[third] != cursum){
      return false;
    }
    else{
      if(rec(newCarry, pos + 1, avail, key)){
        return true;
      }
    }
  }
  else if(key[first] != -1 and key[third] != -1){
    int diff = key[third] - key[first];
    bool newCarry = false;
    if(diff < 0){
      diff += 10;
      newCarry = true;
    }
    if(carry){
      diff--;
    }
    if(diff < 0){
      return false;
    }
    if(avail[diff] == true){
      avail[diff] = false;
      key[second] = diff;
      if(rec(newCarry, pos + 1, avail, key)){
        return true;
      }
      avail[diff] = true;
      key[second] = -1;
    }
    else{
      return false;
    }
  }
  else{
    for(int i = 0; i < 10; i++){
      bool c1 = false;
      if(key[first] == -1){
        if(avail[i] == true){
          key[first] = i;
          avail[i] = false;
          c1 = true;
        }
      }
      if(key[first] != -1){
        for(int j = 0; j < 10; j++){
          bool c2 = false;
          if(key[second] == -1){
            if(avail[j] == true){
              key[second] = j;
              avail[j] = false;
              c2 = true;
            }
          }
          if(key[second] != -1){
            bool c3 = false;
            bool newCarry = false;
            int cursum = key[first] + key[second];
            if(carry){
              cursum++;
            }
            if(cursum > 9){
              cursum -= 10;
              newCarry = true;
            }
            bool works = false;
            if(key[third] == -1){
              if(avail[cursum] == true){
                key[third] = cursum;
                avail[cursum] = false;
                c3 = true;
                works = true;
              }
            }
            else if(key[third] == cursum){
              works = true;
            }
            //cout << "checking ";
            //cout << first << " " << second << " " << third << " ";
            //cout << key[first] << " " << key[second] << " " << key[third] << endl;
            if(works){
              //cout << "works ";
              //cout << first << " " << second << " " << third << " ";
              //cout << key[first] << " " << key[second] << " " << key[third] << endl;
              if(rec(newCarry, pos + 1, avail, key)){
                return true;
              }
            }
            if(c3){
              avail[key[third]] = true;
              key[third] = -1;
            }
          }
          if(c2){
            avail[key[second]] = true;
            key[second] = -1;
          }
        }
      }
      if(c1){
        avail[key[first]] = true;
        key[first] = -1;
      }
    }
  }
  //cout << "didn't work" << endl;
  return false;
}

int main() 
{
  int N;
  cin >> N;
  for(int z = 0; z < N; z++){
    string word1, word2, word3;
    cin >> word1 >> word2 >> word3;
    
    string every = word1 + word2 + word3;
    
    f1 = word1[0];
    f2 = word2[0];
    f3 = word3[0];
    int i1 = word1.size() - 1;
    int i2 = word2.size() - 1;
    int i3 = word3.size() - 1;
  
    while(true){
      if(i3 < 0){
        break;
      }
      if(i1 < 0 and i2 < 0){
        add.push_back({'.', '.', word3[i3]});
      }
      else if(i1 < 0){
        add.push_back({'.', word2[i2], word3[i3]});
      }
      else if(i2 < 0){
        add.push_back({word1[i2], '.', word3[i3]});
      }
      else{
        add.push_back({word1[i1], word2[i2], word3[i3]});
      }
      
      i1--;
      i2--;
      i3--;
    }
    
    /*for(int i = 0; i < add.size(); i++){
      for(int j = 0; j < add[i].size(); j++){
        cout << add[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;*/
    
    map<int, bool> avail;
    map<char, int> key;
    for(int i = 0; i < 10; i++){
      avail[i] = true;
    }
  
    for(int i = 0; i < every.size(); i++){
      key[every.at(i)] = -1;
    }
    
    key['.'] = 0;
    
    if(rec(false, 0, avail, key)){
      for(int i = 0; i < word1.size(); i++){
        cout << final[word1.at(i)];
      }
      cout << endl;
      for(int i = 0; i < word2.size(); i++){
        cout << final[word2.at(i)];
      }
      cout << endl;
      for(int i = 0; i < word3.size(); i++){
        cout << final[word3.at(i)];
      }
      cout << endl;
    }
    cout << endl;
    add.clear();
  }
  
  
  return 0;
}
