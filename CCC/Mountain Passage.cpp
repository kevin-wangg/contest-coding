#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    int n; cin >> n;
    vector<int> other(n, 0);
    vector<vector<int> > grid(n, other);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> grid[i][j];
      }
    }
    
    int needO = grid[0][0];
    
    vector<int> wow(n, -1);
    vector<vector<int> > flag(n, wow);
    flag[0][0] = 0;
    
    queue<vector<int> > bfs;
    
    bfs.push({0, 0, 0});
    while(not bfs.empty()){
      vector<int> node = bfs.front();
      //cout << node[0] << " " << node[1] << " " << node[2] << endl;
      bfs.pop();
      if(node[0] > 0){
        if(flag[node[0] - 1][node[1]] == -1){
          if(abs(grid[node[0] - 1][node[1]] - grid[node[0]][node[1]]) <= 2){
            if(grid[node[0] - 1][node[1]] > needO or grid[node[0]][node[1]] > needO){
              bfs.push({node[0] - 1, node[1], node[2] + 1});
              flag[node[0] - 1][node[1]] = node[2] + 1;
            }
            else{
              bfs.push({node[0] - 1, node[1], node[2]});
              flag[node[0] - 1][node[1]] = node[2];
            }
          }
        }
      }
      if(node[0] < n - 1){
        if(flag[node[0] + 1][node[1]] == -1){
          if(abs(grid[node[0] + 1][node[1]] - grid[node[0]][node[1]]) <= 2){
            if(grid[node[0] + 1][node[1]] > needO or grid[node[0]][node[1]] > needO){
              bfs.push({node[0] + 1, node[1], node[2] + 1});
              flag[node[0] + 1][node[1]] = node[2] + 1;
            }
            else{
              bfs.push({node[0] + 1, node[1], node[2]});
              flag[node[0] + 1][node[1]] = node[2];
            }
          }
        }
      }
      if(node[1] > 0){
        if(flag[node[0]][node[1] - 1] == -1){
          if(abs(grid[node[0]][node[1] - 1] - grid[node[0]][node[1]]) <= 2){
            if(grid[node[0]][node[1] - 1] > needO or grid[node[0]][node[1]] > needO){
              bfs.push({node[0], node[1] - 1, node[2] + 1});
              flag[node[0]][node[1] - 1] = node[2] + 1;
            }
            else{
              bfs.push({node[0], node[1] - 1, node[2]});
              flag[node[0] - 1][node[1] - 1] = node[2];
            }
          }
        }
      }
      if(node[1] < n - 1){
        if(flag[node[0]][node[1] + 1] == -1){
          if(abs(grid[node[0]][node[1] + 1] - grid[node[0]][node[1]]) <= 2){
            if(grid[node[0]][node[1] + 1] > needO or grid[node[0]][node[1]] > needO){
              bfs.push({node[0], node[1] + 1, node[2] + 1});
              flag[node[0]][node[1] + 1] = node[2] + 1;
            }
            else{
              bfs.push({node[0], node[1] + 1, node[2]});
              flag[node[0]][node[1] + 1] = node[2];
            }
          }
        }
      }
    }
    
    /*for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << flag[i][j] << " ";
      }
      cout << endl;
    }*/
    
    if(flag[n - 1][n - 1] == -1){
      cout << "CANNOT MAKE THE TRIP";
    }
    else{
      cout << flag[n - 1][n - 1];
    }
    cout << endl << endl;
  }
  return 0;
}
