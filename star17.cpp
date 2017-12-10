#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
  string line;
  getline(cin, line);

  int sum_score = 0;
  int score = 0;
  for (unsigned int i = 0; i < line.size(); ++i) {
    if (line[i] == '<') {
      while (line[i] != '>') {
        if (line[i] == '!') {
          ++i;
          ++i;
        }
        else {
          ++i;
        }
      }
    }
    else if (line[i] == '{') {
      ++score;
    }
    else if (line[i] == '}') {
      sum_score += score;
      --score;
      
      //cerr << sum_score << " at " << i << endl;
    }
    cerr << score << " at " << i << endl;
  }
  
  cout << sum_score << endl;
}