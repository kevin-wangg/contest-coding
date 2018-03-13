#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#define mp(a, b) make_pair(a, b)
using namespace std;

int main()
{
  int t; cin >> t;
  for(int z = 0; z < t; z++){
    map<pair<int, int>, bool> check;
    int r, c, pawnyZ, pawnxZ, knighty, knightx;
    cin >> r >> c >> pawnyZ >> pawnxZ >> knighty >> knightx;
    int win = 0;
    int draw = 0;
    int lose = 0;
    int pawny = pawnyZ;
    int pawnx = pawnxZ;
    pawny--;
    pawnx--;
    
    queue<vector<int> > bfs;
    bfs.push({knighty - 1, knightx - 1, pawny});
    check[make_pair(knighty - 1, knightx - 1)] = true;
    vector<int> other(c, -1);
    vector<vector<int> > flag(r, other);
    flag.at(knighty - 1).at(knightx - 1) = 0;
    //Shortest moves to win
    while(not bfs.empty()){
      vector<int> node = bfs.front();
      bfs.pop();
      int y = node.at(0), x = node.at(1), pawn = node.at(2) + 1;
      check[make_pair(y, x)] = false;
      if(pawn == r - 1){//Pawn wins
        //cout << "pawn win" << endl;
        //cout << pawny << " " << pawnx << endl;
        break;
      }
      //cout << y << " " << x << " " << pawn << " " << pawnx << endl;
      if(y < r - 1 and x > 1){ //if in bounds
        if(y + 1 == pawn and x - 2 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y + 1 == pawn + 1 and x - 2 == pawnx)){ //If not stalemate
          if(check[make_pair(y + 1, x - 2)] == false){
            flag.at(y + 1).at(x - 2) = flag.at(y).at(x) + 1;
            bfs.push({y + 1, x - 2, pawn});
            check[make_pair(y + 1, x - 2)] = true;
            //cout << "added " << y + 1 << " " << x - 2 << " " << pawn << endl;
          }
        }
      }
      if(y < r - 1 and x < c - 2){ //if in bounds
        if(y + 1 == pawn + 1 and x + 2 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y + 1 == pawn + 1 and x + 2 == pawnx)){ //If not stalemate
          if(check[make_pair(y + 1, x + 2)] == false){
            flag.at(y + 1).at(x + 2) = flag.at(y).at(x) + 1;
            bfs.push({y + 1, x + 2, pawn});
            check[make_pair(y + 1, x + 2)] = true;
            //cout << "added " << y + 1 << " " << x + 2 << " " << pawn << endl;
          }
        }
      }
      if(y > 0 and x > 1){ //if in bounds
        if(y - 1 == pawn and x - 2 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y - 1 == pawn + 1 and x - 2 == pawnx)){ //If not stalemate
          if(check[mp(y - 1, x - 2)] == false){
            flag.at(y - 1).at(x - 2) = flag.at(y).at(x) + 1;
            bfs.push({y - 1, x - 2, pawn});
            check[mp(y - 1, x - 2)] = true;
            //cout << "added " << y - 1 << " " << x - 2 << " " << pawn << endl;
          }
        }
      }
      if(y > 0 and x < c - 2){ //if in bounds
        if(y - 1 == pawn and x + 2 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y - 1 == pawn + 1 and x + 2 == pawnx)){ //If not stalemate
          if(check[mp(y - 1, x + 2)] == false){
            flag.at(y - 1).at(x + 2) = flag.at(y).at(x) + 1;
            bfs.push({y - 1, x + 2, pawn});
            check[mp(y - 1, x + 2)] = true;
            //cout << "added " << y - 1 << " " << x + 2 << " " << pawn << endl;
          }
        }
      }
      if(y < r - 2 and x > 0){ //if in bounds
        if(y + 2 == pawn and x - 1 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y + 2 == pawn + 1 and x - 1 == pawnx)){ //If not stalemate
          if(check[mp(y + 2, x - 1)] == false){
            flag.at(y + 2).at(x - 1) = flag.at(y).at(x) + 1;
            bfs.push({y + 2, x - 1, pawn});
            check[mp(y + 2, x - 1)] = true;
            //cout << "added " << y + 2 << " " << x - 1 << " " << pawn << endl;
          }
        }
      }
      if(y < r - 2 and x < c - 1){ //if in bounds
        if(y + 2 == pawn and x + 1 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y + 2 == pawn + 1 and x + 1 == pawnx)){ //If not stalemate
          if(check[mp(y + 2, x + 1)] == false){
            flag.at(y + 2).at(x + 1) = flag.at(y).at(x) + 1;
            bfs.push({y + 2, x + 1, pawn});
            check[mp(y + 2, x + 1)] = true;
            //cout << "added " << y + 2 << " " << x + 1 << " " << pawn << endl;
          }
        }
      }
      if(y > 1 and x > 0){ //if in bounds
        if(y - 2 == pawn and x - 1 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y - 2 == pawn + 1 and x - 1 == pawnx)){ //If not stalemate
          if(check[mp(y - 2, x - 1)] == false){
            flag.at(y - 2).at(x - 1) = flag.at(y).at(x) + 1;
            bfs.push({y - 2, x - 1, pawn});
            check[mp(y - 2, x - 1)] = true;
            //cout << "added " << y - 2 << " " << x - 1 << " " << pawn << endl;
          }
        }
      }
      if(y > 1 and x < c - 1){ //if in bounds
        if(y - 2 == pawn and x + 1 == pawnx){//Captured the pawn
          win += flag.at(y).at(x) + 1;
          break;
        }
        else if(not (y - 2 == pawn + 1 and x + 1 == pawnx)){ //If not stalemate
          if(check[mp(y - 2, x + 1)] == false){
            flag.at(y - 2).at(x + 1) = flag.at(y).at(x) + 1;
            bfs.push({y - 2, x + 1, pawn});
            check[mp(y - 2, x + 1)] = true;
            //cout << "added " << y - 2 << " " << x + 1 << " " << pawn << endl;
          }
        }
      }
    }
    while(not bfs.empty()){
      bfs.pop();
    }
    //cout << "hi dude" << endl;
    if(win == 0){
      map<pair<int, int>, bool > woow;
      bfs.push({knighty - 1, knightx - 1, pawny});
      woow[mp(knighty - 1, knightx - 1)] = true;
      vector<vector<int> > newflag(r, other);
      newflag.at(knighty - 1).at(knightx - 1) = 0;
      while(not bfs.empty()){
        vector<int> node = bfs.front();
        bfs.pop();
        int y = node.at(0), x = node.at(1), pawn = node.at(2);
        woow[mp(y, x)] = false;
        pawn++;
        if(pawn == r - 1){
          break;
        }
        if(y < r - 1 and x > 1){ //if in bounds
          if(y + 1 == pawn + 1 and x - 2 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y + 1, x - 2)] == false){
              newflag.at(y + 1).at(x - 2) = newflag.at(y).at(x) + 1;
              bfs.push({y + 1, x - 2, pawn});
              woow[mp(y + 1, x - 2)] = true;
            }
          }
        }
        if(y < r - 1 and x < c - 2){ //if in bounds
          if(y + 1 == pawn + 1 and x + 2 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y + 1, x + 2)] == false){
              newflag.at(y + 1).at(x + 2) = newflag.at(y).at(x) + 1;
              bfs.push({y + 1, x + 2, pawn});
              woow[mp(y + 1, x + 2)] = true;
            }
          }
        }
        if(y > 0 and x > 1){ //if in bounds
          if(y - 1 == pawn + 1 and x - 2 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y - 1, x - 2)] == false){
              newflag.at(y - 1).at(x - 2) = newflag.at(y).at(x) + 1;
              bfs.push({y - 1, x - 2, pawn});
              woow[mp(y - 1, x - 2)] = true;
            }
          }
        }
        if(y > 0 and x < c - 2){ //if in bounds
          if(y - 1 == pawn + 1 and x + 2 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y - 1, x + 2)] == false){
              newflag.at(y - 1).at(x + 2) = newflag.at(y).at(x) + 1;
              bfs.push({y - 1, x + 2, pawn});
              woow[mp(y - 1, x + 2)] = true;
            }
          }
        }
        if(y < r - 2 and x > 0){ //if in bounds
          if(y + 2 == pawn + 1 and x - 1 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y + 2, x - 1)] == false){
              newflag.at(y + 2).at(x - 1) = newflag.at(y).at(x) + 1;
              bfs.push({y + 2, x - 1, pawn});
              woow[mp(y + 2, x - 1)] = true;
            }
          }
        }
        if(y < r - 2 and x < c - 1){ //if in bounds
          if(y + 2 == pawn + 1 and x + 1 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
          if(woow[mp(y + 2, x + 1)] == false){
              newflag.at(y + 2).at(x + 1) = newflag.at(y).at(x) + 1;
              bfs.push({y + 2, x + 1, pawn});
              woow[mp(y + 2, x + 1)] = true;
            }
          }
        }
        if(y > 1 and x > 0){ //if in bounds
          if(y - 2 == pawn + 1 and x - 1 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y - 2, x - 1)] == false){
              newflag.at(y - 2).at(x - 1) = newflag.at(y).at(x) + 1;
              bfs.push({y - 2, x - 1, pawn});
              woow[mp(y - 2, x - 1)] = true;
            }
          }
        }
        if(y > 1 and x < c - 1){ //if in bounds
          if(y - 2 == pawn + 1 and x + 1 == pawnx){//Captured the pawn
            draw += newflag.at(y).at(x) + 1;
            break;
          }
          else{ //If not stalemate
            if(woow[mp(y - 2, x + 1)] == false){
              newflag.at(y - 2).at(x + 1) = newflag.at(y).at(x) + 1;
              bfs.push({y - 2, x + 1, pawn});
              woow[mp(y - 2, x + 1)] = true;
            }
          }
        }
      }
    }
    if(knighty - 1 == pawnyZ and knightx == pawnxZ){
      cout << "Stalemate in " << draw << " knight move(s)." << endl;
    }
    else if(win != 0){
      cout << "Win in " << win << " knight move(s)." << endl;
    }
    else if(draw != 0){
      cout << "Stalemate in " << draw << " knight move(s)." << endl;
    }
    else{
      cout << "Loss in " << (r - pawnyZ) - 1 << " knight move(s)." << endl;
    }
  }
  return 0;
}
