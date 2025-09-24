#include <iostream>
using namespace std;
class BitArray
{
public:

  //конструктор с одним параметром - длиной массива
  //выделяет память и заполняет массив нулевыми байтами
  BitArray(int n);

  //конструктор копий
  BitArray(const BitArray &b);

  //деструктор
  ~BitArray();

  //функция, возвращающая размер массива
  int size() const;

  //операция индексирования
  int operator [] (const unsigned int i) const;

  //присвоить i-му биту значение v (0 или 1)
  void setbit(int i, int v);

  //операция присваивания
  BitArray& operator = (const BitArray &b);

  //операция & - побитовое "И" двух массивов. Если длина одного массива 
  //меньше длины другого, его недостающие биты считаются равными 0
  BitArray operator &(const BitArray &b) const;

  //операция | - побитовое "ИЛИ" двух массивов. Если длина одного массива 
  //меньше длины другого, его недостающие биты считаются равными 0
  BitArray operator | (const BitArray &b) const;

  //операция ~ - инвертирование битов массива (0 на 1, 1 на 0)
  BitArray operator ~ (void) const;

  //операция вывода - выводит в одну строчку без пробелов значения в массиве - нули или единицы
  friend ostream& operator << (ostream &os, const BitArray &b);

  //операции сравнения
  bool operator == (const BitArray &b) const;
  bool operator != (const BitArray &b) const;

private:
    int* bit_arr;
    int size_arr;
};