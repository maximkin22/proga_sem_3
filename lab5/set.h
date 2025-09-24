template <class T>
class Set {
  //закрытые данные (какие считаете нужными)
public:
  
  //конструкторы (если нужны)
  Set(); 
  Set(const Set &s);
  
  //вставка элемента в множество
  Set operator + (const T &t) const;
  friend Set operator + (const T &t, const Set &s);
  Set &operator += (const T &t);

  //удаление элемента из множества
  Set operator - (const T &t) const;
  Set &operator -= (const T &t);
  
  //проверка наличия элемента в множестве
  bool exists(const T &t) const;

  //объединение множеств
  Set operator + (const Set &s) const;
  Set& operator += (const Set &s);

  //разность множеств
  Set operator - (const Set &s) const;
  Set& operator -= (const Set &s);

  //операции сравнения
  bool operator == (const Set &s) const;
  bool operator != (const Set &s) const;

  //мощность множества (число элементов)
  int size(void) const;

  //вывод элементов в порядке возрастания, разделяя их пробелом
  friend ostream& operator << (ostream& os, const Set &s) {
    //поместите соответствующий код сюда
  }

  //операция присваивания (если нужна)
  Set &operator = (const Set &s);

  //деструктор (если нужен)
  ~Set();

};