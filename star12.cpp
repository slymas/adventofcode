#include <iostream>
#include <array>
#include <map>
using namespace std;

int main() {
  array<int,16> a;
  map< array<int,16>, int > s;
  
  for(int i = 0, tmp; cin >> tmp; ++i) {
    a[i] = tmp;
  }
  
  int step_cnt = 0;
  while (s.find(a) == s.end()) {
    s.insert(make_pair(a,step_cnt));
    ++step_cnt;
    
    int max_i = -1;
    int max_value = -1;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] > max_value) {
        max_value = a[i];
        max_i = i;
      }
    }
    
    a[max_i] = 0;
    
    for (int i = 0; i < a.size(); ++i) {
      // redistribute values from a[max_i]
      a[i] += max_value/16;
      if ((i > max_i && i-max_i <= max_value%16) ||
          (i < max_i && 16-(max_i-i) <= max_value%16)) {
        a[i] += 1;
      }
      
    }
  }

  cout << step_cnt - s.find(a)->second << endl;
}