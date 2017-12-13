#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
  unordered_map<int,unordered_set<int> > m;
  
  // Parse input
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    
    int id;
    string pipeto, arrow;
    ss >> id >> arrow;
    
    unordered_set<int> s;
    while (ss >> pipeto) {
      if (pipeto.back() == ',') {
        pipeto.pop_back();
      }
      s.insert(stoi(pipeto));
    }
    
    m.emplace(id, s);
  }

  // BFS from ID == 0
  unordered_set<int> connected_to_0;
  /*for ()
  connected_to_0.insert();
  */
  
  for (auto& x : m[0]) {
    //cerr << x << endl;
  }

}