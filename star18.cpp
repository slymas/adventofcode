#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
  string line;
  getline(cin, line);

  int garbage_cnt = 0;
  for (unsigned int i = 0; i < line.size(); ++i) {
    if (line[i] == '<') {
      while (line[i] != '>') {
        if (line[i] == '!') {
          ++i;
          ++i;
        }
        else {
          ++i;
          ++garbage_cnt;
        }
      }
      --garbage_cnt;
    }
  }
  
  cout << garbage_cnt << endl;
}