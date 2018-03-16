#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool search(string word, vector<vector<char> > grid, int y, int x)
{
  //cout << y << " " << x << endl;
  int tempy = y, tempx = x;
  //up
  int i = 0;
  while(true){
    if(y < 0){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y--;
  }
  //down
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(y > grid.size() - 1){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y++;
  }
  //left
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(x < 0){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    x--;
  }
  //right
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(x > grid[y].size() - 1){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    x++;
  }
  //up left
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(y < 0 or x < 0){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y--;
    x--;
  }
  //up right
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(y < 0 or x > grid[y].size() - 1){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y--;
    x++;
  }
  //down left
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(y > grid.size() - 1 or x < 0){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y++;
    x--;
  }
  //down right
  i = 0;
  y = tempy;
  x = tempx;
  while(true){
    if(y > grid.size() - 1 or x > grid[y].size() - 1){
      break;
    }
    if(grid[y][x] != word[i]){
      break;
    }
    if(i == word.size() - 1){
      return true;
    }
    i++;
    y++;
    x++;
  }
  return false;
}

pair<int, int> find(string word, vector<vector<char> > grid)
{
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      if(search(word, grid, i, j)){
        return make_pair(i, j);
      }
    }
  }
}

int main()
{
  int t; cin >> t;
  while(t--){
    int row, column;
    cin >> row >> column;
    vector<vector<char> > grid(row, vector<char> (column, '.'));
    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
        char wow; cin >> wow;
        grid[i][j] = char(tolower(wow));
      }
    }

    int queries; cin >> queries;
    for(int i = 0; i < queries; i++){
      string word;
      cin >> word;
      for(int j = 0; j < word.size(); j++){
        word[j] = char(tolower(word[j]));
      }
      //cout << word << endl;
      pair<int, int> final = find(word, grid);
      cout << final.first + 1 << " " << final.second + 1 << endl;
    }
    cout << endl;
  }
  return 0;
}
