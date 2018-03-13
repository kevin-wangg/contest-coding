#include <iostream>

using namespace std;

int sumofdiv(int num)
{
  int sum = 0;
  for(int i = 1; i < num; i++) {
    if(num % i == 0) {
      sum += i;
    }
  }
  return sum;
}
int main()
{
  int times, num;
  cin >> times;
  for(int i = 0; i < times; i++) {
    cin >> num;
    if(sumofdiv(num) == num) {
      cout << num << " is a perfect number." << endl;
    }
    else if(sumofdiv(num) < num) {
      cout << num << " is a deficient number." << endl;
    }
    else {
      cout << num << " is an abundant number." << endl;
    }
  }
  return 0;
}
