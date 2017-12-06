#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  vector<int> v;

  while(cin >> num) {
    v.push_back(num);
  }
  
  int step_cnt = 0;
  unsigned int i = 0;
  while(true) {
    unsigned int new_i = i + v[i];
    ++step_cnt;
    
    if (new_i < 0 || new_i >= v.size()) {
      break;
    }
    
    if (v[i] >= 3) {
      --v[i];
    }
    else {
      ++v[i];
    }
    i = new_i;
  
  }  
  
  cout << "STEPS: " << step_cnt << endl;
}