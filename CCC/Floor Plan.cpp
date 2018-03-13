#include <iostream>
#include <vector>
#include <algorithm>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << endl;};
using namespace std;

vector<int> rooms;
int rows, cols;
void recurse(int &count, int y, int x, vector<string> &grid)
{
  grid.at(y).at(x) = 'I';
  if(x < cols - 1){
    if(grid.at(y).at(x + 1) != 'I'){
      count ++;
      recurse(count, y, x + 1, grid);
    }
  }
  if(y < rows - 1){
    if(grid.at(y + 1).at(x) != 'I'){
      count ++;
      recurse(count, y + 1, x, grid);
    }
  }
  if(x > 0){
    if(grid.at(y).at(x - 1) != 'I'){
      count ++;
      recurse(count, y, x - 1, grid);
    }
  }
  if(y > 0){
    if(grid.at(y - 1).at(x) != 'I'){
      count ++;
      recurse(count, y - 1, x, grid);
    }
  }
}

int main()
{
  int wood; cin >> wood;
  cin >> rows;
  cin >> cols;
  vector<string> grid(rows, " ");
  for(int i = 0; i < rows; i++){
    cin >> grid.at(i);
  }
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(grid.at(i).at(j) != 'I'){
        int count = 0;
        //cout << i << " " << j << endl;
        recurse(count, i, j, grid);
        rooms.push_back(count + 1);
        //printv(grid);
      }
    }
  }
  //printv(grid);
  sort(rooms.begin(), rooms.end());
  reverse(rooms.begin(), rooms.end());
  //printv(rooms);
  int good = 0;
  for(int i = 0; i < rooms.size(); i++){
    if(rooms.at(i) <= wood){
      good ++;
      wood -= rooms.at(i);
    }
    else{
      break;
    }
  }
  if(good == 1){
    cout << "1 room, ";
  }
  else{
    cout << good << " rooms, ";
  }
  cout << wood << " square metre(s) left over";
  return 0;
}
