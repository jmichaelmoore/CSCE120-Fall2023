#include <iostream>

using std::cout, std::endl;

int mi(int j) {
  int i = 5;
  return j % i;
}

int re(int& s, int p) {
  s = 12;
  return mi(s*p);
}

int doe(int w) {
  int k = 2;
  int q = w+3;
  cout << "k: " << k << endl;
  int z = re(k, q);
  cout << "k: " << k << endl;
  return z + w;
}

int main() {
  int b = doe(11);
  cout << "b: " << b << endl;
  return 0;
}