#include <iostream>
#include <string>
using namespace std;


int main() {
  long long sum = 0;
  
  string s;
  cin >> s;
  
  for (auto i = 1; i < s.size(); ++i) {
    if (s.at(i) == s.at(i-1)) {
      sum += (s.at(i)-'0');
    }
  }
  
  if (s.at(0) == s.back()) {
    sum += (s.at(0)-'0');
  }
  
  cout << "Sum: " << sum << endl;

}