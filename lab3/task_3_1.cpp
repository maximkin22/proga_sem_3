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

void print_arr(int arr[], int N){
  
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copy_arr(int arr1[], int arr2[], int n){

    for(int i = 0; i < n; i++){
        arr1[i] = arr2[i];
    }
}


int main() {
    
    int n, k, m;
    cin >> n;
    cin >> k;
    cin >> m;

    int* start_arr =new int[n];

    int_arr_comp(start_arr, n);

    for (int i = 0; i < m; i++){

        int* newArr =new int[n];

        for(int j = 0; j < n; j++){

        if (j < n - k) newArr[j] = start_arr[j + k];
        else newArr[j] = start_arr[j - (n - k)];
        
        }
        copy_arr(start_arr, newArr, n);
        delete [] newArr;
    }
    print_arr(start_arr, n);
    delete[] start_arr;
    
    return 0;
}