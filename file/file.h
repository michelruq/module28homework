#pragma once

#include <fstream>

class FileManager
{
   
public:
   static void WriteDataUsePtrToFile (const std::string& filename, const int* ptr, const int n);
   static void ReadDataUsePtrFromFile (const std::string& filename, int*& arr, int& n);
	
};

void FileManager::WriteDataUsePtrToFile (const std::string& filename, const int* ptr, const int n)
{
   std::fstream fs;
	
   fs.open(filename, std::fstream::out);
   if(fs.is_open())
   {
      fs << n << std::endl;
	  for(int i{0}; i < n; ++i)
	  {
	     fs << ptr[i]  << ' ';
	  }
	  fs << std::endl;
	
	  fs.close();
   }
}

void FileManager::ReadDataUsePtrFromFile (const std::string& filename, int*& ptr, int& n)
{
   std::fstream fs;
	
   fs.open(filename, std::fstream::in);
	
   if(fs.is_open()) 
   {
	  fs >> n; 
	  ptr = new int[n];
	  for (int i = 0; i < n; i++)
	  {
	    fs >> ptr[i];
	  }

	  fs.close(); 
   }
}