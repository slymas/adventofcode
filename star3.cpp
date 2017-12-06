#include <iostream>
#include <sstream>
#include <string>
#include <climits>
using namespace std;

int main() {
  long long checksum = 0;
  
  string line;
  while (getline(cin, line)) {
    int minv = INT_MAX;
    int maxv = INT_MIN;
    
    stringstream ss(line);
    
    int tmp;
    while (ss >> tmp) {
      minv = min(minv, tmp);
      maxv = max(maxv, tmp);
    }
    
    checksum += (maxv - minv);
  }
  
  cout << "Checksum: " << checksum << endl;
}
