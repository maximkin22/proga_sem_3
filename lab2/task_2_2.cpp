#include <iostream>
#include <string>
using namespace std;
int main(){
string spiral[6][6];
for(int j = 0; j < 6 ; j++){
cin >> spiral[0][j];
}
for(int j = 1; j < 6 ; j++){
cin >> spiral[j][5];
}
for(int j = 4; j >= 0 ; j--){
cin >> spiral[5][j];
}
for(int j = 4; j > 0 ; j--){
cin >> spiral[j][0];
}
for(int j = 1; j < 5 ; j++){
cin >> spiral[1][j];
}
for(int j = 2; j < 5 ; j++){
cin >> spiral[j][4];
}
for(int j = 3; j >= 1 ; j--){
cin >> spiral[4][j];
}
for(int j = 3; j > 1 ; j--){
cin >> spiral[j][1];
}
for(int j = 2; j < 4 ; j++){
cin >> spiral[2][j];
}
for(int j = 3; j > 1 ; j--){
cin >> spiral[3][j];
}
for(int i = 0; i < 6 ; i++){
for(int j = 0; j < 6 ; j++){
cout << spiral[i][j] <<"\t";
}
cout <<"\n";
}
return 0;
}