#include <iostream>
#include <string>
#include <vector>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << " ";}cout << endl

using namespace std;

int main()
{
  int N; cin >> N;
  cin.ignore();
  for(int q = 0; q < N; q++){
    string line;
    getline(cin, line);
    vector<string> c;
    string temp = "";
    for(int i = 0 ; i < line.size(); i++){
      if(line.at(i) != ' '){
        temp += line.at(i);
        if(i == line.size() - 1){
          c.push_back(temp);
        }
      }
      else{
        c.push_back(temp);
        temp = "";
      }
    }
    for(int i = 0; i < c.size(); i++){
      int left = 0, right = 0;
      if(c.at(i) == "X"){
        //for loop going leftwards, starting from one left of left num, break once counter is 0, insert at that index
        for(int j = i - 1; j > -1; j--){
          if(c.at(j) ==")"){
            left++;
          }
          else if(c.at(j) == "("){
            left--;
          }
          if(left == 0){
            c.insert(c.begin() + j, "(");
            i++;
            break;
          }
        }
        for(int j = i + 1; j < c.size(); j++){
          if(c.at(j) == "("){
            right++;
          }
          else if(c.at(j) == ")"){
            right--;
          }
          if(right == 0){
            c.insert(c.begin() + j + 1, ")");
            break;
          }
        }
      }
    }
    for(int i = 0; i < c.size(); i++){
      int left = 0, right = 0;
      if(c.at(i) == "+" or c.at(i) == "-"){
        //for loop going leftwards, starting from one left of left num, break once counter is 0, insert at that index
        for(int j = i - 1; j > -1; j--){
          if(c.at(j) ==")"){
            left++;
          }
          else if(c.at(j) == "("){
            left--;
          }
          if(left == 0){
            c.insert(c.begin() + j, "(");
            i++;
            break;
          }
        }
        for(int j = i + 1; j < c.size(); j++){
          if(c.at(j) == "("){
            right++;
          }
          else if(c.at(j) == ")"){
            right--;
          }
          if(right == 0){
            c.insert(c.begin() + j + 1, ")");
            break;
          }
        }
      }
    }
    c.erase(c.begin());
    c.erase(c.end());
    //printv(c);
    int left = 0, right = 0;
    for(int i = 0; i < c.size(); i++){
      cout << c.at(i);
      if(c.at(i) == "("){
        continue;
      }
      else if(i == c.size() - 1){
        continue;
      }
      else if(c.at(i + 1) == ")"){
        continue;
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
