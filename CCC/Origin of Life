#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
#include <map>

using namespace std;

int m, n, a, b, c;

void printv(vector<vector<int> > grid)
{
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

int convert(vector<vector<int> > grid, vector<vector<int> > key)
{
  int num = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == 1){
        num += key[i][j];
      }
    }
  }
  return num;
}

vector<vector<int> > convertBack(int num, vector<vector<int> > key)
{
  vector<vector<int> > grid(m, vector<int> (n, 0));
  for(int i = m - 1; i > -1; i--){
    for(int j = n - 1; j > -1; j--){
      if(num >= key[i][j]){
        grid[i][j] = 1;
        num -= key[i][j];
      }
    }
  }
  return grid;
}

int nextState(int num, vector<vector<int> > key)
{
  vector<vector<int> > grid = convertBack(num, key);
  vector<vector<int> > newGrid = grid;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      int total = 0;
      if(i > 0){
        total += grid[i - 1][j];
        if(j > 0){
          total += grid[i - 1][j - 1];
        }
        if(j < n - 1){
          total += grid[i - 1][j + 1];
        }
      }
      if(i < m - 1){
        total += grid[i + 1][j];
        if(j > 0){
          total += grid[i + 1][j - 1];
        }
        if(j < n - 1){
          total += grid[i + 1][j + 1];
        }
      }
      if(j > 0){
        total += grid[i][j - 1];
      }
      if(j < n - 1){
        total += grid[i][j + 1];
      }
      
      if(grid[i][j] == 1){
        if(total < a or total > b){
          newGrid[i][j] = 0;
        }
      }
      else{
        if(total > c){
          newGrid[i][j] = 1;
        }
      }
    }
  }
  return convert(newGrid, key);
}

int main() 
{
  cin >> m >> n >> a >> b >> c;
  vector<vector<int> > grid(m, vector<int> (n, 0));
  vector<vector<int> > key(m, vector<int> (n, 0));
  int start = 1;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      key[i][j] = start;
      start *= 2;
    }
  }
  int max = pow(2, m * n);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      char val;
      cin >> val;
      if(val == '*'){
        grid[i][j] = 1;
      }
    }
  }
  vector<vector<int> > adj(max + 1, vector<int> (0));
  for(int i = 0; i <= max; i++){
    int next = nextState(i, key);
    if(i != next){
      adj[next].push_back(i);
    }
  }
  /*int boi = convert(grid, key);
  for(int i = 0; i < adj[boi].size(); i++){
    printv(convertBack(adj[boi][i], key));
    cout << endl;
  }*/
  map<int, bool> vis;  
  queue<pair<int, int> > bfs;
  bfs.push(make_pair(convert(grid, key), 0));
  while(not bfs.empty()){
    int cur = bfs.front().first;
    int dis = bfs.front().second;
    bfs.pop();
    if(adj[cur].size() == 0){
      cout << dis;
      return 0;
    }
    for(int i = 0; i < adj[cur].size(); i++){
      if(vis[adj[cur][i]] == true){
        cout << -1;
        return 0;
      }
      vis[adj[cur][i]] = true;
      bfs.push(make_pair(adj[cur][i], dis + 1));
    }
  }
  return 0;
}
