#include <iostream>
#include <vector>
#include <string>
#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl
using namespace std;

int main()
{
  while(true){
    int m, n;
    scanf("%d%d", &m, &n);
    if(m == 0 and n == 0){
      break;
    }
    vector<string> grid(m, "");
    
    vector<int> wow(n, 0);
    vector<vector<int> > finaldp(m, wow);
    vector<vector<int> > updp(m, wow);
    vector<vector<int> > downdp(m, wow);
    
    for(int i = 0; i < m; i++){
      cin >> grid[i];
    }
  
    for(int i = 0; i < n; i++){
      for(int j = m - 1; j > -1; j--){
        if(i == 0){
          if(j == m - 1){
            if(grid[j][i] != '.' and grid[j][i] != '*'){
              updp[j][i] = grid[j][i] - 48;
            }
          }
          else{
            if(grid[j][i] != '.' and grid[j][i] != '*'){
              if(updp[j + 1][i] == -1){
                updp[j][i] = -1;
              }
              else{
                updp[j][i] += updp[j + 1][i] + grid[j][i] - 48;
              }
            }
            else{
              if(grid[j][i] != '*'){
                updp[j][i] += updp[j + 1][i];
              }
              else{
                updp[j][i] = -1;
              }
            }
          }
        }
        else{
          if(j == m - 1){
            if(grid[j][i] != '.' and grid[j][i] != '*'){
              if(finaldp[j][i - 1] == -1){
                updp[j][i] = -1;
              }
              else{
                updp[j][i] += finaldp[j][i - 1] + grid[j][i] - 48;
              }
            }
            else{
              if(grid[j][i] != '*'){
                updp[j][i] += finaldp[j][i - 1];
              }
              else{
                updp[j][i] = -1;
              }
            }
          }
          else{
            if(grid[j][i] != '.' and grid[j][i] != '*'){
              if(finaldp[j][i - 1] == -1 and updp[j + 1][i] == -1){
                updp[j][i] = -1;
              }
              else{
                updp[j][i] += grid[j][i] - 48 + max(finaldp[j][i - 1], updp[j + 1][i]);
              }
            }
            else{
              if(grid[j][i] != '*'){
                updp[j][i] += max(finaldp[j][i - 1], updp[j + 1][i]);
              }
              else{
                updp[j][i] = -1;
              }
            }
          }
        }
      }
      
      if(i != 0){
        for(int k = 0; k < m; k++){
          if(k == 0){
            if(grid[k][i] != '.' and grid[k][i] != '*'){
              if(finaldp[k][i - 1] == -1){
                downdp[k][i] = -1;
              }
              else{
                downdp[k][i] += finaldp[k][i - 1] + grid[k][i] - 48;
              }
            }
            else{
              if(grid[k][i] != '*'){
                downdp[k][i] += finaldp[k][i - 1];
              }
              else{
                downdp[k][i] = -1;
              }
            }
          }
          else{
            if(grid[k][i] != '.' and grid[k][i] != '*'){
              if(finaldp[k][i - 1] == -1 and downdp[k - 1][i] == -1){
                downdp[k][i] = -1;
              }
              else{
                downdp[k][i] += grid[k][i] - 48 + max(finaldp[k][i - 1], downdp[k - 1][i]);
              }
            }
            else{
              if(grid[k][i] != '*'){
                downdp[k][i] += max(finaldp[k][i - 1], downdp[k - 1][i]);
              }
              else{
                downdp[k][i] = -1;
              }
            }
          }
        }
      }
      
      for(int l = 0; l < m; l++){
        finaldp[l][i] = max(updp[l][i], downdp[l][i]);
      }
    }
    
    /*for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << updp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << downdp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << finaldp[i][j] << " ";
      }
      cout << endl;
    }*/
    
    printf("%d\n", finaldp[m - 1][n - 1]);
  }
  return 0;
}
