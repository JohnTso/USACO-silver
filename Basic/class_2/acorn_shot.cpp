#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  
  ifstream f ("input.txt");
  int n,k;
  f >> n >> k;

  double min=10e9+1, max=0;
  vector<int> pos;

  for (int i=0; i<n; ++i) {
    int p; f >> p; 
    if (p<min) min = p;
    if (p>max) max = p;
    pos.push_back(p);
  }
  sort(pos.begin(), pos.end());

  int start = 1, end = (max-min)/k, mid;
  // start pointer and end pointer
  while (end-start > 1) {
    mid = (end+start)/2;

    // check if mid is valid
    int i=0, shots=k, valid=true;
    while (i < pos.size()) {
      int hit_pos = pos[i]+mid;
      // cout << pos[i] << " " << hit_pos << " " << hit_pos+mid << " " << endl;
      while (i < pos.size() && pos[i] <= hit_pos+mid) i++;
      shots--;
      if (shots == 0 && i < n){
        valid=false; break;
      }
    }

    // cout << mid << " " << valid << endl;
    if (valid) end = mid;
    else start = mid;
    
  }
  cout << end << endl;
  
}