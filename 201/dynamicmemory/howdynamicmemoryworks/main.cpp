#include<iostream>

int main() {
   int i = 14;

   int* k = &i;

   k = new int(3);
   
   delete k;

   double* w = new double(3.5);
   
   delete w;

   w = nullptr;  
}
