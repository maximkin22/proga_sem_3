#include <iostream>
using namespace std;
int main(){
int m, n;
cin>>m;
cin>>n;
char arr[31] = {0};
char CC16[16] = {'0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F'};
for(int i = 30; i >= 0; i--){
arr[i] = CC16[m % n];
m = m / n;
if(m == 0){break;}
}
bool flag = false;
for(int i = 0; i < 31; i++){
if (arr[i] != 0){flag = true;}
if (flag = true){cout << arr[i];}
}
cout<<endl;
return 0;
}
