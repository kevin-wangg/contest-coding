#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int blocks; cin >> blocks;
  int finalr = 1, finalc = 1;
  vector<int> wow(1024, 1);
  vector<vector<int> > final(1024, wow);
  vector<vector<int> > temp(1024, wow);
  vector<vector<int> > grid(1024, wow);

  for(int i = 0; i < blocks; i++){
    int r, c;
    cin >> r >> c;

    for(int j = 0; j < r; j++){
      for(int k = 0; k < c; k++){
        cin >> grid[j][k];
      }
    }
    
    for(int j = 0; j < finalr * r; j++){
      for(int k = 0; k < finalc * c; k++){
        final[j][k] = temp[j % finalr][k % finalc] * grid[j / finalr][k / finalc];
        //cout << final[j][k] << endl;
      }
    }
    finalr *= r;
    finalc *= c;
    for(int j = 0; j < finalr; j++){
      for(int k = 0; k < finalc; k++){
        temp[j][k] = final[j][k];
      }
    }
  }
  
  /*for(int i = 0; i < finalr; i++){
    for(int j = 0; j < finalc; j++){
      cout << final[i][j] << " ";
    }
    cout << endl;
  }*/
  
  vector<int> rowsum, colsum;
  
  int big = final[0][0], small = final[0][0];
  for(int i = 0; i < finalr; i++){
    int colcount = 0;
    for(int j = 0; j < finalc; j++){
      colcount += final[i][j];
      if(final[i][j] > big){
        big = final[i][j];
      }
      if(final[i][j] < small){
        small = final[i][j];
      }
    }
    colsum.push_back(colcount);
  }
  for(int i = 0; i < finalc; i++){
    int rowcount = 0;
    for(int j = 0; j < finalr; j++){
      rowcount += final[j][i];
    }
    rowsum.push_back(rowcount);
  }
  cout << big << endl;
  cout << small << endl;
  cout << *max_element(colsum.begin(), colsum.end()) << endl;
  cout << *min_element(colsum.begin(), colsum.end()) << endl;
  cout << *max_element(rowsum.begin(), rowsum.end()) << endl;
  cout << *min_element(rowsum.begin(), rowsum.end()) << endl;
  return 0;
}
