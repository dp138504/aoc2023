#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int get_nums(string line){
//  string text = line;
  string result;
  string first, last;
  int iresult;

  for (int i = 0; i < line.length(); i++){
    if ( isdigit(line.at(i)) ){
      first = line.at(i);
      break;
    }
  }

  for (int j = line.length()-1; j >= 0; j--){
    if ( isdigit(line.at(j)) ){
      last = line.at(j);
      break;
    }
  }

  result = first + last;
  iresult = stoi(result);
  return iresult;
}

int main() {
  string line;
  ifstream cal("test.txt");
  int accumulator = 0;

  if ( cal.is_open() ) {
    while ( cal ) {
      getline(cal, line);
      //accumulator = accumulator + stoi(get_nums(line));
      //cout << accumulator;
      accumulator += get_nums(line);
      //cout << get_nums(line) << '\n';
    }
    cout << accumulator;
  }

  return 0;
}
