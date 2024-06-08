#pragma once

#include <future>
#include "basesort.h"

class MergeSort : public BaseSort
{
   private:	
      const std::string name = "Merge Sorting Algorithm";
   
      void Merge(int* arr, int l, int m, int r);
      void MergingSort(int* a, int p, int r);
   public:
      void Sort(int* arr, int n);
	  std::string getNameSortingAlgorithm()
	  {
	     return name;
	  }
};

void MergeSort::Merge(int* arr, int l, int m, int r)
{
   const int nl = m - l + 1;
   const int nr = r - m;

   // создаем временные массивы
   int* left = new int[nl]; 
   int* right = new int[nr];

   // копируем данные во временные массивы
   for (int i = 0; i < nl; i++)
       left[i] = arr[l + i];
   for (int j = 0; j < nr; j++)
       right[j] = arr[m + 1 + j];

   int i = 0, j = 0;
   int k = l;  // начало левой части

   while (i < nl && j < nr) {
       // записываем минимальные элементы обратно во входной массив
       if (left[i] <= right[j]) {
           arr[k] = left[i];
           i++;
       }
       else {
           arr[k] = right[j];
           j++;
       }
       k++;
   }
   // записываем оставшиес¤ элементы левой части
   while (i < nl) {
       arr[k] = left[i];
       i++;
       k++;
   }
   // записываем оставшиес¤ элементы правой части
   while (j < nr) {
       arr[k] = right[j];
       j++;
       k++;
   }
}

void MergeSort::MergingSort(int* a, int p, int r)
{
   if(p >= r)
   {
      return;
   }
   int q = (p + r - 1)/2;
   auto f = std::async(std::launch::async, [&]() {
           MergingSort(a, p, q);
       }); 
   MergingSort(a, q + 1, r);
   f.get();  
   Merge(a, p, q, r);
}

void MergeSort::Sort(int* a, int number)
{
   MergingSort(a, 0, number - 1);
}