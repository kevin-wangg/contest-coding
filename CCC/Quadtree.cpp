#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > first(1024, vector<int> (1024, 0));
vector<vector<int> > second(1024, vector<int> (1024, 0));
vector<vector<int> > save(1024, vector<int> (1024, 0));

void fill(string preorder, int x1, int x2, int y1, int y2, bool firstE)
{
  //cout << "hi";
  //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
  string one = "", two = "", three = "", four = "";
  if(preorder[0] == 'p'){
    int i = 1;
    int pcount = 0;
    bool dody = true;
    while(true){
      one += preorder[i];
      if(preorder[i] == 'p'){
        if(dody){
          pcount += 4;
          dody = false;
        }
        else{
          pcount += 3;
        }
      }
      else{
        if(dody){
          i++;
          break;
        }
        else{
          pcount--;
        }
      }
      if(pcount == 0){
        i++;
        break;
      }
      i++;
    }
    dody = true;
    pcount = 0;
    while(true){
      two += preorder[i];
      if(preorder[i] == 'p'){
        if(dody){
          pcount += 4;
          dody = false;
        }
        else{
          pcount += 3;
        }
      }
      else{
        if(dody){
          i++;
          break;
        }
        else{
          pcount--;
        }
      }
      if(pcount == 0){
        i++;
        break;
      }
      i++;
    }
    dody = true;
    pcount = 0;
    while(true){
      three += preorder[i];
      if(preorder[i] == 'p'){
        if(dody){
          pcount += 4;
          dody = false;
        }
        else{
          pcount += 3;
        }
      }
      else{
        if(dody){
          i++;
          break;
        }
        else{
          pcount--;
        }
      }
      if(pcount == 0){
        i++;
        break;
      }
      i++;
    }
    dody = true;
    pcount = 0;
    while(true){
      four += preorder[i];
      if(preorder[i] == 'p'){
        if(dody){
          pcount += 4;
          dody = false;
        }
        else{
          pcount += 3;
        }
      }
      else{
        if(dody){
          i++;
          break;
        }
        else{
          pcount--;
        }
      }
      if(pcount == 0){
        i++;
        break;
      }
      i++;
    }
    //cout << one << endl;
    //cout << two << endl;
    //cout << three << endl;
    //cout << four << endl;
    fill(one, x1, (x2 + x1) / 2, y1, (y1 + y2) / 2, firstE);
    fill(two, (x1 + x2) / 2, x2, y1, (y1 + y2) / 2, firstE);
    fill(three, (x1 + x2) / 2, x2, (y1 + y2) / 2, y2, firstE);
    fill(four, x1, (x1 + x2) / 2, (y1 + y2) / 2, y2, firstE);
  }
  else{
    if(preorder[0] == 'f'){
      for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
          if(firstE){
            first[i][j] = 1;
          }
          else{
            second[i][j] = 1;
          }
        }
      }
    }
  }
}

int main() 
{
  int t; cin >> t;
  while(t--){
    string firstA; cin >> firstA;
    string secondA; cin >> secondA;
    fill(firstA, 0, 32, 0, 32, true);
    fill(secondA, 0, 32, 0, 32, false);
    int final = 0;
    for(int i = 0; i < 32; i++){
      for(int j = 0; j < 32; j++){
        if(first[i][j] or second[i][j]){
          final++;
        }
      }
    }
    cout << "There are " << final << " black pixels." << endl;
    first = save;
    second = save;
  }
  return 0;
}
