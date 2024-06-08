#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include "file.h"

#include "mergesort.h"

MergeSort oMergeSort;

struct Test
{
	BaseSort* pAlgorithm;
	std::string filenameOutput;
};

const int numberOfSortingAlgorithm = 1;

Test array [numberOfSortingAlgorithm] = {
											  {&oMergeSort, "C://education28homework/module28homework/files/sortedmergedata.txt"}

											 };

int main (int argc, char* argv[])
{
    std::string filenameInput = "C://education28homework/module28homework/files/unsorteddata.txt";
	const int size = (argc==2)?static_cast<int>(std::atof(argv[1])):static_cast<int>(5000);
    int* rand_arr = new int[size];
	
	srand(time(nullptr)); 
	
	int lef_border = 5;
    int range_len = 10;
	
	for (int i = 0; i < size; i++)
	{
		rand_arr[i] = lef_border + rand() % range_len; 
	}
	
	FileManager::WriteDataUsePtrToFile(filenameInput, rand_arr, size); 
	
	delete[] rand_arr;
	
	for (int i {0}; i < numberOfSortingAlgorithm; ++i)
	{
		int* array_from_file = nullptr;
        int n = 0;
        FileManager::ReadDataUsePtrFromFile(filenameInput, array_from_file, n); 
		auto start = std::chrono::high_resolution_clock::now(); 
		array[i].pAlgorithm->Sort(array_from_file, n);
		
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "Elapsed time of " << array[i].pAlgorithm->getNameSortingAlgorithm() << " : " << elapsed.count() << " sec" << std::endl;
		
		FileManager::WriteDataUsePtrToFile(array[i].filenameOutput, array_from_file, size); 
		delete[] array_from_file;
	}
	
	return 0;
}