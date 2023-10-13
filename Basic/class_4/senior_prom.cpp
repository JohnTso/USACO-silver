#include <iostream>
#include <fstream>

using namespace std;

int main () {

  ifstream f ("input.txt");
  int n; f >> n;

  for (int i=0; i<n; ++i) {
  
    int len; f >> len;
    int res=0;
    bool legal = true;
  
    for (int j=0; j<len; ++j) {
    
      char c; f >> c;
      if (c == '>') res++;
      else res--;
      if (res < 0) legal = false;
    
    }
  
    if (res == 0 && legal) cout << "legal" << endl;
    else cout << "illegal" << endl;
  }
  
}