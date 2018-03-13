#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  int knightx, knighty, finalx, finaly;
  cin >> knightx >> knighty >> finalx >> finaly;
  queue<pair<int, int> > bfs;
  bfs.push(make_pair(knightx, knighty));
  
  vector<int> other(8, -1);
  vector<vector<int> > flag(8, other);
  flag[knighty - 1][knightx - 1] = 0;
  
  while(!bfs.empty()){
    pair<int, int> node = bfs.front();
    bfs.pop();
    int x = node.first, y = node.second;
    if(x >= 2 and y <= 6){
      if(flag[y + 1][x - 2] == -1){
        bfs.push(make_pair(x - 1, y + 2));
        flag[y + 1][x - 2] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x <= 7 and y <= 6){
      if(flag[y + 1][x] == -1){
        bfs.push(make_pair(x + 1, y + 2));
        flag[y + 1][x] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x >= 3 and y <= 7){
      if(flag[y][x - 3] == -1){
        bfs.push(make_pair(x - 2, y + 1));
        flag[y][x - 3] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x >= 3 and y >= 2){
      if(flag[y - 2][x - 3] == -1){
        bfs.push(make_pair(x - 2, y - 1));
        flag[y - 2][x - 3] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x <= 6 and y <= 7){
      if(flag[y][x + 1] == -1){
        bfs.push(make_pair(x + 2, y + 1));
        flag[y][x + 1] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x <= 6 and y >= 2){
      if(flag[y - 2][x + 1] == -1){
        bfs.push(make_pair(x + 2, y - 1));
        flag[y - 2][x + 1] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x <= 7 and y >= 3){
      if(flag[y - 3][x] == -1){
        bfs.push(make_pair(x + 1, y - 2));
        flag[y - 3][x] = flag[y - 1][x - 1] + 1;
      }
    }
    if(x >= 2 and y >= 3){
      if(flag[y - 3][x - 2] == -1){
        bfs.push(make_pair(x - 1, y - 2));
        flag[y - 3][x - 2] = flag[y - 1][x - 1] + 1;
      }
    }
    
  }
  
  /*for(int i = 0 ; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout << flag[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << flag[finaly - 1][finalx - 1];
  return 0;
}
