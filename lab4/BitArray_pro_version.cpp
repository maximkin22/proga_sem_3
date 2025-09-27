#include <iostream>
using namespace std;

class BitArray
{
public:
    const int bit32=sizeof(int)*8;

    BitArray(int n);
    BitArray(const BitArray &b);
    ~BitArray();
    

    int size() const;
    int operator [] (const unsigned int i) const;
    int& operator[](const unsigned int i);
    void setbit(int i, int v);
    BitArray& operator = (const BitArray &b);
    BitArray operator &(const BitArray &b) const;
    BitArray operator | (const BitArray &b) const;
    BitArray operator ~ () const;
    friend ostream& operator << (ostream &os, const BitArray &b);
    bool operator == (const BitArray &b) const;
    bool operator != (const BitArray &b) const;

private:
    int* bit_arr;
    size_t size_arr;
};

//
BitArray::BitArray(int n): size_arr(n > 0 ? ((n %bit32 == 0) ? (n / bit32) : (n / bit32 + 1)) : 0){
    bit_arr = new int[size_arr]();
}

BitArray::BitArray(const BitArray &b) : size_arr(b.size_arr){
    bit_arr = new int[size_arr]; 
    for (int i = 0; i < size_arr; ++i) bit_arr[i] = b.bit_arr[i];  
}

BitArray::~BitArray(){
    delete[] bit_arr;
}

int BitArray::size() const{
    return size_arr;
}
//
int BitArray::operator[](const unsigned int i) const {
    if (i >= static_cast<unsigned int>(size_arr * bit32)) {
        return 0; 
    }
    return (1 << i%bit32) & bit_arr[i/bit32];
}
//
int& BitArray::operator[](const unsigned int i) {
    int one_b = 1;
    static int null_b = 0;
    if (i >= static_cast<unsigned int>(size_arr * bit32)) {
        return null_b;
    }
    return ((1 << i%bit32) & bit_arr[i/bit32] == 1 ? one_b : null_b);
}
//
void BitArray::setbit(int i, int v){
    bit_arr[i/bit32] = (v==0 ? (v << i%bit32) & bit_arr[i/bit32] : (v << i%bit32) | bit_arr[i/bit32]);
    
}

BitArray& BitArray::operator = (const BitArray &b){
    if(this == &b) return *this;
    
    delete [] bit_arr;
    size_arr = b.size_arr;
    bit_arr = new int[size_arr];
    
    for(int i = 0; i < size_arr; i++) 
        bit_arr[i] = b.bit_arr[i];
    
    return *this;
}
//
BitArray BitArray::operator&(const BitArray &b) const {
    int min_size = (size_arr < b.size_arr) ? size_arr : b.size_arr;
    BitArray result(min_size * bit32);
    
    for(int i = 0; i < min_size; i++) {
        result.bit_arr[i] = bit_arr[i] & b.bit_arr[i];
    }
    
    return result;
}
//
BitArray BitArray::operator|(const BitArray &b) const {
    int max_size = (size_arr > b.size_arr) ? size_arr : b.size_arr;
    BitArray result(max_size * bit32);
    
    for(int i = 0; i < max_size; i++) {
        if (b.bit_arr && bit_arr) {result.bit_arr[i] = b.bit_arr[i] | bit_arr[i]; continue;}
        result.bit_arr[i] = (b.bit_arr[i] ? b.bit_arr[i] : bit_arr[i]);
    }
    return result;
}
//
BitArray BitArray::operator ~ () const{
    BitArray result(size_arr * bit32);
    for (int i = 0; i < size_arr; i++) {
        result.bit_arr[i] = ~(bit_arr[i]);
    }
    return result;
}
//
ostream& operator << (ostream &os, const BitArray &b){
    for (int j = b.size() - 1; j >= 0; j--)
    {
        for (int i = b.bit32 - 1; i >= 0; i--)
        {
            if(i%8 == 0 && i != 0 && i % 32 != 0) os<<"'";
            if(((1 << i) & b.bit_arr[j])){
                os<<1;
            }
            else{
                os<<0;    
            }
        }
        os<<" ";
    }
    return os;
}

bool BitArray::operator == (const BitArray &b) const{
    if(size_arr != b.size_arr) return false;
    
    for(int i = 0; i < size_arr; i++) {
        if(bit_arr[i] != b.bit_arr[i]) 
            return false;
    }
    return true;
}

bool BitArray::operator != (const BitArray &b) const{
    return !(*this == b);
}


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