#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for(int i = 0; i < r; i++){
      cin >> grid.at(i);
    }
    
    vector<int> other(c, -1);
    vector<vector<int> > flag(r, other);
    flag[0][0] = 1;
    queue<pair<int, int> > bfs;
    
    bfs.push(make_pair(0, 0));
    
    while(not bfs.empty()){
      pair<int, int> node = bfs.front();
      int y = node.first, x = node.second;
      //cout << y << " " << x << endl;
      bfs.pop();
      if(grid[y][x] == '-' or grid[y][x] == '+'){
        if(x < c - 1){
          if(grid[y][x + 1] != '*' and flag[y][x + 1] == -1){
            //cout << "right" << endl;
            flag[y][x + 1] = flag[y][x] + 1;
            bfs.push(make_pair(y, x + 1));
          }
        }
        if(x > 0){
          if(grid[y][x - 1] != '*' and flag[y][x - 1] == -1){
            //cout << "left" << endl;
            flag[y][x - 1] = flag[y][x] + 1;
            bfs.push(make_pair(y, x - 1));
          }
        }
      }
      if(grid[y][x] == '|' or grid[y][x] == '+'){
        if(y < r - 1){
          if(grid[y + 1][x] != '*' and flag[y + 1][x] == -1){
            //cout << "down" << endl;
            flag[y + 1][x] = flag[y][x] + 1;
            bfs.push(make_pair(y + 1, x));
          }
        }
        if(y > 0){
          if(grid[y - 1][x] != '*' and flag[y - 1][x] == -1){
            //cout << "up" << endl;
            flag[y - 1][x] = flag[y][x] + 1;
            bfs.push(make_pair(y - 1, x));
          }
        }
      }
      
    }
    
    /*for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        cout << flag[i][j] << " ";
      }
      cout << endl;
    }*/
    cout << flag[r - 1][c - 1] << endl;
  }
  return 0;
}
