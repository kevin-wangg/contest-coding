#include <iostream>

using namespace std;

bool check(int num)
{
  return num % 4 == 0 and num % 2 == 0 and num % 3 == 0 and num % 5 == 0;
}
int main()
{
  int x,y;
  cin >> x >> y;
  int diff = y - x;
  cout << "All positions change in year " << x << endl;
  for(int i = 1; i <= diff; i++){
    if(check(i)){
      cout << "All positions change in year " << i + x << endl;
    }
  }
  return 0;
}
