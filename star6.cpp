/*
1 1 2 4 5 10 11 23 25 26 54 57 59 122 133 142 147
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int input = 361527;
  
  vector< vector<int> > v(999, vector<int>(999,0));
  
  int x = 500;
  int y = 500;
  v[y][x] = 1;
  ++x;
  
  vector<pair<int,int> > dirs {
    {1,-1},{1,0},{1,1},
    {0,-1},{0,1},
    {-1,-1},{-1,0},{-1,1}
  };
  
  vector<int> steps {1,2,2,2,1};
  vector<int> actsteps = steps;
  for (int z = 0; z < 999*999; ++z) {
    for (auto& d : dirs) {
      v[y][x] += v[y+d.second][x+d.first];
    }
    
    if (v[y][x] > input) {
      cout << v[y][x] << endl;
      return 0;
    }
    
    // move in spiral order
    if (actsteps[0]) {
      --y;
      --actsteps[0];
    }
    else if (actsteps[1]) {
      --x;
      --actsteps[1];
    }
    else if (actsteps[2]) {
      ++y;
      --actsteps[2];
    }
    else if (actsteps[3]) {
      ++x;
      --actsteps[3];
    }
    else if (actsteps[4]) {
      ++x;
      --actsteps[4];
    }

    bool actsteps_empty = true;
    for (auto& a : actsteps) {
      if (a != 0) {
        actsteps_empty = false;
        break;
      }
    }
    
    if (actsteps_empty) {
      for (int a = 0; a < steps.size(); ++a) {
        if (a < steps.size()-1) {
          steps[a] += 2;
        }
      }
      actsteps = steps;
    }
    
  }
  
}