#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int calcweights(string name, 
  unordered_map<string,unordered_set<string> >& name2tower,
  unordered_map<string,int>& name2value) 
{
  int sum_tower = 0;
    
  if (!name2tower[name].empty()) {
    int prev_tower = -1;
    for (auto t : name2tower[name]) {
      int tower = calcweights(t, name2tower, name2value);
      
      if (prev_tower != -1 && prev_tower != tower) {
        cerr << name << "__" << endl; 
        /* finds "lahahn" as the 1st out of balance */
      }
      if (name == "lahahn") {
        cerr << t << "_" << tower << endl;
        /*
          prints this: which means that "utnrb"s weight must be lowered by 9 -> to 529
          utnrb_1960
          bbytzn_1951
          fzvctf_1951
        */
      }
      
      prev_tower = tower;
      sum_tower += tower;
    }
  }
  
  return sum_tower + name2value[name];
}

int main() {
  unordered_map<string,int> name2value;
  unordered_map<string,unordered_set<string> > name2tower;
  string root = "bsfpjtc";
  
  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    string tmp, name;
    unordered_set<string> towers;
    bool arrow_found = false;
    
    while(ss >> tmp) {
      if (arrow_found) {
        if (tmp.back() == ',') {
          tmp.pop_back();
        }
        towers.insert(tmp);
      }
      else {
        if (tmp == "->") {
          arrow_found = true;
        }
        else if (tmp[0] == '(') {
          tmp = tmp.substr(1, tmp.size() - 2);
          name2value.insert(make_pair(name,stoi(tmp)));
        }
        else {
          name = tmp;
        }
      }
    }
    
    name2tower.insert(make_pair(name,towers));
  }
  
  calcweights(root, name2tower, name2value);
  
  for (auto s : name2value) {
    //cerr << s.first << ": " << s.second << endl;
  }
  
  for (auto s : name2tower) {
    /*cerr << s.first << ": "; 
    for (auto s2 : s.second) {
      cerr << s2 << "_";
    }
    cerr << endl;*/
  }

  cout << -1 << endl;
}