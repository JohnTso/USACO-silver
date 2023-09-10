#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search() {

}

int main() {
  ifstream f ("input.txt");
  int n; f >> n;
  vector<double> cows;
  for (int i=0; i<n; ++i) {
    double pos; f >> pos;
    cows.push_back(pos);
  }
  sort(cows.begin(), cows.end());

  
}