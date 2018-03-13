#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> other (9, "");
vector<vector<string> > grid(10, other);

vector<long long> wow (9, 0);
vector<vector<long long> > undef(10, wow);

long long recurse(long long i, long long j)
{
  //cout << i << " " << j << endl;
  /*for(long long i = 0; i < 10; i++){
    for(long long j = 0; j < 9; j++){
      cout << grid.at(i).at(j) << " ";
    }
    cout << endl;
  }*/
  
  
  
  
  long long val = 0;
  if(undef.at(i).at(j) == 1 or grid.at(i).at(j) == "*"){
    return -9999999;
  }
  else if(isalpha(grid.at(i).at(j).at(0))){
    undef.at(i).at(j) = 1;
    for(long long k = 0; k <= grid.at(i).at(j).size() - 2; k += 3){
      long long newi = int(grid.at(i).at(j).at(k)) - 65;
      long long newj = grid.at(i).at(j).at(k + 1) - 49;
      val += recurse(newi, newj);
    }
    if(val >= 0){
      grid.at(i).at(j) = to_string(val);
      undef.at(i).at(j) = 0;
    }
    return val;
  }
  else{
    if(isdigit(grid.at(i).at(j).at(0))){
      undef.at(i).at(j) = 0;
      val = stoll(grid.at(i).at(j));
      return val;
    }
  }
}

int main()
{
  for(long long i = 0; i < 10; i++){
    for(long long j = 0; j < 9; j++){
      cin >> grid.at(i).at(j);
    }
  }
  
  for(long long i = 0; i < 10; i++){
    for(long long j = 0; j < 9; j++){
      if(isalpha(grid.at(i).at(j).at(0))){
        long long num = recurse(i, j);
        if(num >= 0){
          grid.at(i).at(j) = to_string(num);
        }
        else{
          grid.at(i).at(j) = "*";
        }
      }
    }
  }
  
  
  
  for(long long i = 0; i < 10; i++){
    for(long long j = 0; j < 9; j++){
      cout << grid.at(i).at(j) << " ";
    }
    cout << endl;
  }
  /*for(long long i = 0; i < 10; i++){
    for(long long j = 0; j < 9; j++){
      cout << undef.at(i).at(j) << " ";
    }
    cout << endl;
  }*/
  return 0;
}
