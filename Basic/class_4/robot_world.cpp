#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

int main () {

  ifstream f ("input.txt");
  int n; f >> n;
  stack<int> s; int count = 1;

  for (int i=0; i<n; i++) {
    string inp; f >> inp;

    if (inp == "ADD") {
      s.push(count);
      count++;
    } else {
      s.pop();
    }

  }

  stack<int> r;
  // have to reverse the stack since the output wants it bottom -> top
  cout << s.size() << endl;
  while (!s.empty()) {
    r.push(s.top());
    s.pop();
  }

  while (!r.empty()) {
    cout << r.top() << endl;
    r.pop();
  }
}