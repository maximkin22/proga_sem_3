#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Set {

private:

class HashMap {
private:
    struct Entry {
        T value;
        Entry(const T& v) : value(v) {}
    };

    static const int SizeHashMap = 24;

    vector<vector<Entry>> buckets;

public:
    HashMap() : buckets(SizeHashMap) {}

    // хеш функция 
    int HashIndex(const T& value) const {
        int h = static_cast<int>(value) % SizeHashMap;
        if (h < 0) h += SizeHashMap;
        return h;
    }


    // добавление записей в таблицу
    void InsertEntry(const T& value) {
        int bucketIndex = HashIndex(value);      

        if (!(buckets[bucketIndex].empty())){
          for (int i = 0; i < buckets[bucketIndex].size(); i++){
            if( buckets[bucketIndex][i].value == value ) return;
          }
        }
        Entry newEntry(value);

        buckets[bucketIndex].push_back(newEntry);
    }
    // удалить запись
    void DeleteEntry(const T& value) {
        int bucketIndex = HashIndex(value);      

        if (!(buckets[bucketIndex].empty())){
          for (int i = 0; i < buckets[bucketIndex].size(); i++){
            if( buckets[bucketIndex][i].value == value ){ 
              buckets[bucketIndex].erase(buckets[bucketIndex].begin() + i);
              return;
            }
          }
        }
    }
    // проверка наличия записи
    bool ContainsEntry(const T& value){
        int bucketIndex = HashIndex(value);      

        if (!(buckets[bucketIndex].empty())){
          for (int i = 0; i < buckets[bucketIndex].size(); i++){
            if( buckets[bucketIndex][i].value == value ) return true;
          }
        }
        return false;
    }
    // полуить все записи (для копирования)
    vector<T> GetAllEntry()const{
      vector<T> result;
      for (int i = 0; i < buckets.size(); i++)
      {
        for (int j = 0; j < buckets[i].size(); j++)
        {
          result.push_back(buckets[i][j].value);
        }
      }
      return result;
    }
};

  HashMap HashTable;

  void insert(const T& value){
    HashTable.InsertEntry(value);
  }

  void remove (const T& value){
    HashTable.DeleteEntry(value);
  }

  bool contains(const T& value){
    return HashTable.ContainsEntry(value);
  }

  vector<T> getterAll()const{
    return HashTable.GetAllEntry();
  }

public:

  Set(){}

  Set(const Set &s){
    vector<T> values = s.getterAll();
    for (int i = 0; i < values.size(); i++){
      insert(values[i]);
    }
  }

  //вставка элемента в множество
  Set operator + (const T &t) const{
    Set result = *this;
    result.insert(t);
    return result;
  }
  //Set<T> result = 42 + Set<T> others
  friend Set operator + (const T &t, const Set &s){
    Set newSet = s;
    newSet.insert(t);
    return newSet;
  }

Set &operator += (const T &t){
    insert(t);    
    return *this; 
}

  //удаление элемента из множества
  Set operator - (const T &t) const{
    Set result = *this;
    result.remove(t);
    return result;
  }
  Set &operator -= (const T &t){
    remove(t);
    return *this;   
  }
  
  //проверка наличия элемента в множестве
  bool exists(const T &t) const{
    Set result = *this;
    return result.contains(t);
  }

  //объединение множеств
  Set operator + (const Set &s) const{
    Set<T> result = *this;
    vector<T> values = s.getterAll();
    for (int i = 0; i < values.size(); i++){
      result.insert(values[i]);
    }
    return result;
  }
  Set& operator += (const Set &s){
    vector<T> values = s.getterAll();
    for (int i = 0; i < values.size(); i++){
      insert(values[i]);
    }
    return *this;
  }

  //разность множеств
  Set operator - (const Set &s) const{
    Set<T> result = *this;
    vector<T> values = s.getterAll();
    for (int i = 0; i < values.size(); i++){
      result.remove(values[i]);
    }
    return result;
  }
  Set& operator -= (const Set &s){
    vector<T> values = s.getterAll();
    for (int i = 0; i < values.size(); i++){
      remove(values[i]);
    }
    return *this;
  }

  //операции сравнения
  bool operator == (const Set &s) const{
    return getterAll() == s.getterAll();
  }
  bool operator != (const Set &s) const{
    return getterAll() != s.getterAll();
  }

  //мощность множества (число элементов)
  int size(void) const{
    return getterAll().size();
  }

  //вывод элементов в порядке возрастания, разделяя их пробелом
  friend ostream& operator << (ostream& os, const Set &s) {

    vector<T> values = s.getterAll(); 

    if (!values.empty()) {
        for (auto it = values.begin(); it != values.end() - 1; ++it) {
            auto minIt = it;
            for (auto it2 = it + 1; it2 != values.end(); ++it2) {
                if (*it2 < *minIt) {
                    minIt = it2;
                }
            }
            swap(*it, *minIt);
        }

        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) os << " ";
            os << values[i];
        }
    }
    return os;
  
}

  //операция присваивания (если нужна)
  Set &operator = (const Set &s){
    if (this == &s) return *this;
    HashTable = s.HashTable;
    return *this;
    }
    

  ~Set(){}
};

// #include "set-test.h"  

int main(){
  Set<int> a;
  for (int i=50; i>=0; i--) a+=i;
  for (int i=0; i<=50; i+=2) a-=i;
  for (int i=0; i<=50; i+=3) a-=i;
  cout << a << endl;
  Set<int> b = ((a + 999)+9999) - 89;
  cout << b.size() << endl;
  cout << b.exists(1) << b.exists(2)
    << b.exists(3) << b.exists(4)
    << b.exists(5) << endl;
  Set<int> *c = new Set<int>;
  *c +=1; *c +=5; *c +=6;
  cout << c->size() << endl;
  cout << a-*c << endl;
  *c += 1111;
  cout << a+*c << endl;
  delete c;

  return 0;
}