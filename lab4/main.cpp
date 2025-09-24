#include "BitArray.h"
#include <iostream>
using namespace std;

int main(){
 BitArray a(50), b(80);
 for (int i=0; i<60; i++) b.setbit(i,1);
 a=b;
 for (int i=0; i<80; i++) b.setbit(i,0);
 cout << a << endl << b << endl;
 if (a==b) cout << "YES"; else cout << "NO"; cout << endl;
 if (a!=b) cout << "NO"; else cout << "YES"; cout << endl;
 if (a==a) cout << "YES"; else cout << "NO"; cout << endl;
 if (a!=a) cout << "NO"; else cout << "YES"; cout << endl;
 BitArray c = a & b;
 cout << c << endl;
 BitArray d(10); d.setbit(0,1); d.setbit(3,1);
 c = a | b;
 cout << c << endl;
 c = ~c;
 cout << c << endl;
return 0;
}