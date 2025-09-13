#include <string>
#include <iostream>
using namespace std;

void int_arr_comp(int arr[], int N){
    int t = 1;
    for (int i = 0; i < N; i++)
    {
        arr[i] = t;
        t++;
    }
}


int main() {

    // Перемешайте книжки
    int n, k, m;
    cin >> n;
    cin >> k;
    cin >> m;

    int start_arr[n];

    int_arr_comp(start_arr, n);

    return 0;
}