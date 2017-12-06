#include <iostream>
#include <string>
using namespace std;


int main() {
  long long sum = 0;
  
  string s;
  cin >> s;
  
  for (auto i = 0; i < s.size(); ++i) {
    if (s.at(i) == s.at((i+s.size()/2)%s.size())) {
      sum += (s.at(i)-'0');
    }
  }
  
  cout << "Sum: " << sum << endl;

}