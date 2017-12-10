#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
  unordered_map<string,int> registers;

  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    string tmp;
    
    int token_cnt = 0;
    string reg, op, if_reg, if_op;
    int val, if_val;
    
    while(ss >> tmp) {
      if (token_cnt == 0) {
        if (!registers.count(tmp)) {
          registers.emplace(tmp,0);
        }
        reg = tmp;
      }
      else if (token_cnt == 1) {
        op = tmp;
      }
      else if (token_cnt == 2) {
        val = stoi(tmp);
      }
      else if (token_cnt == 3) {
        //skip
      }
      else if (token_cnt == 4) {
        if_reg = tmp;
      }
      else if (token_cnt == 5) {
        if_op = tmp;
      }
      else if (token_cnt == 6) {
        if_val = stoi(tmp);
      }
      else {
        cerr << "Parsing error!" << endl;
      }
      
      ++token_cnt;
    }
    
    // Execute register operation
    int if_reg_val = 0;
    if (registers.count(if_reg)) {
      if_reg_val = registers[if_reg];
    }

    if ((if_op == "==" && if_reg_val == if_val) ||
        (if_op == "!=" && if_reg_val != if_val) ||
        (if_op == "<"  && if_reg_val < if_val)  ||
        (if_op == "<=" && if_reg_val <= if_val) ||
        (if_op == ">"  && if_reg_val > if_val)  ||
        (if_op == ">=" && if_reg_val >= if_val)) {
      if (op == "inc") {
        registers[reg] += val;
      }
      else {
        registers[reg] -= val;
      }
    }
  }
  
  int max_reg_val = 0;
  
  for (auto r : registers) {
    max_reg_val = max(max_reg_val, r.second);
  }
  
  cout << max_reg_val << endl;
}