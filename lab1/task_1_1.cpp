#include <iostream>
using namespace std;
int main(){
int n = 0;
for (int i = 1002; i <= 999999; i++){
//abcdef
int a = i / 100000;
int b = i / 10000 - a * 10;
int c = i / 1000 - a * 100 - b * 10;
int d = i / 100 - a * 1000 - b * 100 - c * 10;
int e = i / 10 - a * 10000 - b * 1000 - c * 100 - d * 10;
int f = i - a * 100000 - b * 10000 - c * 1000 - d * 100 - e * 10;
if(((a + b + c) == (d + e + f)) && (i != 0)){
// cout << i << endl;
n++;
}
};
cout << n << endl;
return 0;
}