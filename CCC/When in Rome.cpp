#include <iostream>
#include <vector>
using namespace std;

int thing(string roman)
{
  bool prevI = false;
  bool prevX = false;
  bool prevC = false;
  int sum = 0;
  vector<char>letters;
  for(int i = 0; i < roman.size(); i ++){
    letters.push_back(roman.at(i));
  } //Adds roman numerals to vector
  
  for(int i = 0; i < letters.size(); i++){
    if(letters.at(i) == 'I'){
      sum += 1;
      prevI = true;
      prevX = false;
      prevC = false;
    }
    else if(letters.at(i) == 'V'){
      if(prevI){
        sum += 3;
      }
      else{
        sum += 5;
      }
      prevI = false;
      prevX = false;
      prevC = false;
    }
    else if(letters.at(i) == 'X'){
      if(prevI){
        sum += 8;
      }
      else{
        sum += 10;
      }
      prevX = true;
      prevI = false;
      prevC = false;
    }
    else if(letters.at(i) == 'L'){
      if(prevX){
        sum += 30;
      }
      else{
        sum += 50;
      }
      prevI = false;
      prevX = false;
      prevC = false;
    }
    else if(letters.at(i) == 'C'){
      if(prevX){
        sum += 80;
      }
      else{
        sum += 100;
      }
      prevI = false;
      prevX = false;
      prevC = true;
    }
    else if(letters.at(i) == 'D'){
      if(prevC){
        sum += 300;
      }
      else{
        sum += 500;
      }
      prevI = false;
      prevX = false;
      prevC = false;
    }
    else if(letters.at(i) == 'M'){
      if(prevC){
        sum += 800;
      }
      else{
        sum += 1000;
      }
      prevI = false;
      prevX = false;
      prevC = false;
    }
  }
  return sum;
}
string revthing(int num)
{
  string ans = "";
  int mtimes = num / 1000;
  int cmtimes = (num - (mtimes*1000)) / 900;
  int dtimes = (num - (mtimes*1000) - (cmtimes*900)) / 500;
  int cdtimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500)) / 400;
  int ctimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400)) / 100;
  int xctimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100)) / 90;
  int ltimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90)) / 50;
  int xltimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50)) / 40;
  int xtimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50) - (xltimes*40)) / 10;
  int ixtimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50) - (xltimes*40) - (xtimes*10)) / 9;
  int vtimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50) - (xltimes*40) - (xtimes*10) - (ixtimes*9)) / 5;
  int ivtimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50) - (xltimes*40) - (xtimes*10) - (ixtimes*9) - (vtimes*5)) / 4;
  int itimes = (num - (mtimes*1000) - (cmtimes*900) - (dtimes*500) - (cdtimes*400) - (ctimes*100) - (xctimes*90) - (ltimes*50) - (xltimes*40) - (xtimes*10) - (ixtimes*9) - (vtimes*5) - (ivtimes*4));
  for(int i = 0; i < mtimes; i ++){
    ans += "M";
  }
  for(int i = 0; i < cmtimes; i ++){
    ans += "CM";
  }
  for(int i = 0; i < dtimes; i ++){
    ans += "D";
  }
  for(int i = 0; i < cdtimes; i ++){
    ans += "CD";
  }
  for(int i = 0; i < ctimes; i ++){
    ans += "C";
  }
  for(int i = 0; i < xctimes; i ++){
    ans += "XC";
  }
  for(int i = 0; i < ltimes; i ++){
    ans += "L";
  }
  for(int i = 0; i < xltimes; i ++){
    ans += "XL";
  }
  for(int i = 0; i < xtimes; i ++){
    ans += "X";
  }
  for(int i = 0; i < ixtimes; i ++){
    ans += "IX";
  }
  for(int i = 0; i < vtimes; i ++){
    ans += "V";
  }
  for(int i = 0; i < ivtimes; i ++){
    ans += "IV";
  }
  for(int i = 0; i < itimes; i ++){
    ans += "I";
  }
  return ans;
}
string calc(string equation)
{
  int count = 0;
  string a = "";
  string b = "";
  while(equation.at(count) != '+'){
    a += equation.at(count);
    count ++;
  }
  count ++;
  while(equation.at(count) != '='){
    b += equation.at(count);
    count ++;
  }
  if(thing(a) + thing(b) > 1000){
    return "CONCORDIA CUM VERITATE";
  }
  else{
    return revthing(thing(a)+thing(b));
  }
}
int main()
{
  int times; cin >> times;
  string equation;
  for(int i = 0; i < times; i++){
    cin >> equation;
    cout << equation << calc(equation) << endl;
  }
  return 0;
}
