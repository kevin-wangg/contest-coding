#include <iostream>
#include <vector>
#include <map>
#include <string>
#define printv(a) for(int i = 0; i < a.size(); i++){cout << a.at(i) << " ";}cout << endl;
using namespace std;

int main()
{
  int n; cin >> n;
  n++;
  for(int q = 0; q < n; q++){
    //cout << q << endl;
    string input = "", text = "";
    while(true){
      getline(cin, input);
      //cout << "input is " << input << endl;
      if(input == ""){
        break;
      }
      if(text == ""){
        text += input;
      }
      else{
        text += '/' + input;
      }
    }
    //cout << text << endl;
    vector<string> words;
    map<string, int> store;
    string temp = "";
    int slash = 0;
    int numcount = 0;
    for(int i = 0; i < text.size(); i++){
      if(text.at(i) == ' ' or text.at(i) == '/' or i == text.size() - 1){
        if(i == text.size() - 1){
          temp += text.at(i);
        }
        if(store[temp] != 0){
          //cout << temp << " already" << endl;
          string s = to_string(store[temp]);
          words.push_back(s);
          numcount++;
          temp = "";
        }
        else{
          words.push_back(temp);
          store[temp] = words.size() - slash - numcount;
          //cout << words.size() << endl;
          temp = "";
        }
        if(text.at(i) == '/'){
          words.push_back("/");
          slash++;
        }
      }
      else{
        temp += text.at(i);
      }
    }
    //printv(words);
    /*for(map<string, int>::iterator it = store.begin(); it != store.end(); it++){
      cout << it->first << " " << it->second << endl;
    }*/
    //cout << text << endl;
    for(int i = 0; i < words.size(); i++){
      if(words.at(i) == "/"){
        cout << endl;
      }
      else{
        cout << words.at(i) << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
