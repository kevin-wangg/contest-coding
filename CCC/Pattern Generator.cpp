#include <iostream>
#include <string>

using namespace std;

int main()
{
  long long t; cin >> t;
  for(long long z = 0; z < t; z++){
    string num; cin >> num;
    string temp = num;
    cout << num << endl;
    while(num.size() > 2){
      string subtract = "";
      subtract += num.at(num.size() - 1);
      long long sub = stoll(subtract);
      
      string subtractfrom = "";
      long long count = 3;
      while(true){
        if(num.at(num.size() - count) != '0'){
          break;
        }
        else{
          count++;
        }
      }
      for(long long i = count; i > 1; i--){
        subtractfrom += num.at(num.size() - i);
      }
      long long subfrom = stoll(subtractfrom);
      long long newnum = subfrom - sub;
      num.erase(num.size() - count, count);
      if(to_string(newnum).size() > 1){
        num += to_string(newnum);
      }
      else{
        num += "0" + to_string(newnum);
      }
      if(num.size() == 2){
        if(num.at(0) == '0'){
          cout << num.at(1) << endl;
        }
        else{
          cout << num << endl;
        }
      }
      else{
        cout << num << endl;
      }
    }
    if(stoll(num) % 11 == 0){
      cout << "The number " << temp << " is divisible by 11." << endl;
    }
    else{
      cout << "The number " << temp << " is not divisible by 11." << endl;
    }
    cout << endl;
  }
  return 0;
}
