#include <iostream>
#include <vector>
#define printv(a) for(int p = 0; p < a.size(); p++){cout << a.at(p) << " ";}cout << endl
using namespace std;

int m, n;

vector<string> a;
vector<string> b;
vector<int> stop;
vector<int> finalorder;

bool good = false;

void rec(vector<int> avail, vector<int> cur, string aa, string bb)
{
  //cout << aa << " " << bb << endl;
  if(cur.size() == m - 1){
    
  }
  else{
    for(int i = 0; i < avail.size(); i++){
      vector<int> newcur = cur;
      newcur.push_back(avail[i]);
      
      string newaa = aa;
      string newbb = bb;
      newaa += a[avail[i]];
      newbb += b[avail[i]];
      if(newaa == newbb){
        //cout << "equal" << endl;
        //printv(newcur);
        good = true;
        finalorder = newcur;
        break;
      }
      else{
        rec(avail, newcur, newaa, newbb);
      }
    }
  }
}

int main()
{
  cin >> m >> n;
  vector<int> temp(m, n);
  stop = temp;
  vector<int> avail(n, 0);
  for(int i = 0; i < n; i++){
    avail[i] = i;
  }
  for(int i = 0; i < n; i++){
    string wow;
    cin >> wow;
    a.push_back(wow);
  }
  for(int i = 0; i < n; i++){
    string wow;
    cin >> wow;
    b.push_back(wow);
  }
  
  rec(avail, {}, "", "");
  if(good){
    cout << finalorder.size() << endl;
    for(int i = 0; i < finalorder.size(); i++){
      cout << finalorder[i] + 1<< endl;
    }
  }
  else{
    cout << "No solution.";
  }
}
