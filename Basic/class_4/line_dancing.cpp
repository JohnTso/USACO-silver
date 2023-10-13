#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {

  ifstream f ("input.txt");
  int n; f >> n;
  vector<int> line;
  int count=0;

  for (int i=0;i<n;++i){
    char c; f >> c;
    char dir; f >> dir;

    if (c == 'D') {
      int k; f >> k;
    } else {

    }

  }
}