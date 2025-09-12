#include <iostream>
using namespace std;

int main(){
    // Счастливые билеты
    int n = 0;

    for (int i = 1; i <= 999999; i++){
        //abcdef
        int a = i / 100000;
        int b = i / 10000 - a * 10;
        int c = i / 1000 - a * 100 - b * 10;
        int d = i / 100 - a * 1000 - b * 100 - c * 10;
        int e = i / 10 - a * 10000 - b * 1000 - c * 100 - d * 10;
        int f = i - a * 100000 - b * 10000 - c * 1000 - d * 100 - e * 10;

        if(((a + b + c) == (d + e + f)) and (i != 0)){
            // cout << i << endl;
            n++;
        }
    };

    cout << n << endl;

    // Системы счисления
    int m, n;
    cin>>m;
    cin>>n;

    char arr[31] = {0};
    char CC16[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

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
}