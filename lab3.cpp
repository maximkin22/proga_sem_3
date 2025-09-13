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
    
    // Перемешайте книжки
    int n, k, m;
    cin >> n;
    cin >> k;
    cin >> m;

    int* start_arr =new int[n];

    int_arr_comp(start_arr, n);

    // print_arr(start_arr, n);


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
    

    // Считалочка
    int n, k;
    cin >> n;
    cin >> k;
    if (n < 2 || n > 10000 || k < 1 || k > 100){return 0;}

    int* peoples = new int[n];
    int_arr_comp(peoples, n);
    
    int index = 0;
    k = k -1;

    while (n > 1)
    {
        int* newArr =new int[n - 1];

        int index_loha = (index + k) % n;

        for (int i = 0; i < index_loha; i++) {
            newArr[i] = peoples[i];           
        }
        for (int i = index_loha + 1; i < n; i++) {
            newArr[i-1] = peoples[i];        
        }
        
        n--;

        if (index_loha == n) index = 0;
        else index = index_loha;
        

        delete[] peoples; 
        // print_arr(newArr, n);
        peoples = newArr;
    }
    
    print_arr(peoples, n);
    
    delete[] peoples;
    return 0;
}