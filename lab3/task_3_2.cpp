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



int main() {

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

        int index_out = (index + k) % n;

        for (int i = 0; i < index_out; i++) {
            newArr[i] = peoples[i];           
        }
        for (int i = index_out + 1; i < n; i++) {
            newArr[i-1] = peoples[i];        
        }
        
        n--;

        if (index_out == n) index = 0;
        else index = index_out;
        

        delete[] peoples; 
        peoples = newArr;
    }
    
    print_arr(peoples, n);
    
    delete[] peoples;
    return 0;
}