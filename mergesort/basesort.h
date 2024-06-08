
#pragma once
#include <string>

class BaseSort
{
public:
	virtual void Sort(int* arr, int n) = 0;
	virtual std::string getNameSortingAlgorithm() = 0;
	int getMax (int* arr, int n );
	int getExp (int value);
	void swap(int *a, int *b);
};

int BaseSort::getMax (int* arr, int n )
{
   int max = arr[0];
   for(int i = 1; i < n; ++i)
   {
      if( arr[i] > max)
      {
        max = arr[i];
      }
   }
   return max;
}

int BaseSort::getExp(int value) 
{
    int exp = 1;

    while( value > 10)
    {
        value /= 10;
        exp *= 10;
    }

    return exp;
}

void BaseSort::swap(int *a, int *b) // функция для смены местами двух значений
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
