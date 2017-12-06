#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int main() {
  long long checksum = 0;
  
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    int tmp;
    vector<int> l;
    while (ss >> tmp) {
      l.push_back(tmp);
    }
    
    for (auto& x : l) {
      for (auto& y : l) {
        if (x == y)
          continue;
        if (x%y==0) {
          cerr << x << " " << y << " ";
          checksum += max(x,y)/min(x,y);
        }
      }
    }
    cerr << endl;
  }
  
  cout << "Checksum: " << checksum << endl;
}
