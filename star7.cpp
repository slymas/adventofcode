#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
  int valid_cnt = 0;
  string line;
  
  while(getline(cin, line)) {
    stringstream ss(line);
    string word;
    
    unordered_set<string> us;
    bool valid = true;
    
    while (ss >> word) {
      if (us.count(word)) {
        valid = false;
        break;
      }
      else {
        us.insert(word);
      }
    }
    
    if (valid) {
      ++valid_cnt;
    }
  }
  
  cout << valid_cnt << endl;
}