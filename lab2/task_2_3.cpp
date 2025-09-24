#include <iostream>
#include <string>
using namespace std;
int main() {
string str;
int k;
getline(cin, str);
cin >> k;
cout <<endl;
if((str.length()) >= k && (k > 0)){
while(str.length() > k - 1){
str.erase(k-1, 1); // erase лучше не использовать
cout << str <<endl;
}
}
return 0;
}