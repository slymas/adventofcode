#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
  unordered_set<string> potential_roots;
  unordered_set<string> referenced_names;
  
  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    string tmp, name;
    bool arrow_found = false;
    
    while(ss >> tmp) {
      if (arrow_found) {
        if (tmp.back() == ',') {
          tmp.pop_back();
        }
        referenced_names.insert(tmp);
      }
      else {
        if (tmp == "->") {
          arrow_found = true;
          potential_roots.insert(name);
        }
        else if (tmp[0] == '(') {
        }
        else {
          name = tmp;
        }
      }
    }
  }
  
  for (auto s : referenced_names) {
    if (potential_roots.count(s)) {
      potential_roots.erase(s);
    }
  }

  cout << *potential_roots.begin() << endl;
}