#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int tiles;
  cin >> tiles;
  while (pow(sqrt(tiles), 2) != pow(floor(sqrt(tiles)), 2)) {
    tiles --;
  }
  cout << "The largest square has side length " << sqrt(tiles) << "." << endl;
  return 0;
}
