#include <iostream>
#include <iomanip>
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
  return pos%pos_limit;
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

template< typename T >
string int_to_hex( T i )
{
  stringstream stream;
  stream << setfill ('0') << setw(2) 
         << hex << i;
  return stream.str();
}

int main() {
  array<int,256> a;
  
  for (auto i = 0; i < a.size(); ++i) {
    a[i] = i;
  }
  
  // Parse input
  string line;
  getline(cin, line);
  vector<int> v;
  for (char c : line) {
    v.push_back(c);
  }
  v.insert(v.end(), {17, 31, 73, 47, 23});
  
  // Execute hashing rounds
  int skip_size = 0;
  int cur_pos = 0;
  for(auto i = 0; i < 64; ++i) {
    for(int length : v) {
      if (length > 0 && length < a.size()) {
        int begin = cur_pos;
        int end = cur_pos + length - 1; // inclusive
        end = overwrap(end, a.size());
        
        reverse(a,begin,end);
      }
      
      cur_pos += length + skip_size;
      cur_pos = overwrap(cur_pos, a.size());
      
      ++skip_size;
    }
  }
  
  // Creating dense hash from sparse hash
  array<int,16> dense_hash;
  for(auto i = 0; i < dense_hash.size(); ++i) {
    dense_hash[i] = a[i*16];
    for(auto j = 1; j < dense_hash.size(); ++j) {
      dense_hash[i] ^= a[i*16+j];
    }
  }
  
  //Hexing
  cout << "Hash output: ";
  for(auto d : dense_hash) {
    cout << int_to_hex(d);
  }
  cout << endl;
}