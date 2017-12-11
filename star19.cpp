#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <array>
#include <vector>
using namespace std;

void printarray(const array<int,256>& a) {
  for (auto i = 0; i < a.size(); ++i) {
    cerr << a[i] << ", ";
  }
  cerr << endl;
}

int underwrap(int pos, int pos_limit) {
  if (pos < 0) {
    pos += pos_limit;
  }
  return pos;
}

int overwrap(int pos, int pos_limit) {
  if (pos >= pos_limit) {
    pos -= pos_limit;
  }
  return pos;
}

void reverse(array<int,256>& a, int begin, int end) {
  while (begin != end) {
    int tmp = a[begin];
    a[begin] = a[end];
    a[end] = tmp;
    
    ++begin;
    begin = overwrap(begin, a.size());
    if (begin == end) {
      break;
    }
    --end;
    end = underwrap(end, a.size());
  }
}

int main() {
  array<int,256> a;
  
  for (auto i = 0; i < a.size(); ++i) {
    a[i] = i;
  }
  
  // printarray(a);
  
  int skip_size = 0;
  int cur_pos = 0;
  string num;
  while(getline(cin, num, ',')) {
    int length = atoi(num.c_str());
    
    if (length > 0 && length < a.size()) {
      int begin = cur_pos;
      int end = cur_pos + length - 1; // inclusive
      end = overwrap(end, a.size());
      
      reverse(a,begin,end);
    }
    
    // printarray(a);
    
    cur_pos += length + skip_size;
    cur_pos = overwrap(cur_pos, a.size());
    
    ++skip_size;
    
    // cerr << "---------------------------------------------------------------------------------------" << endl;
  }
  
  cout << a[0]*a[1] << endl;
}
