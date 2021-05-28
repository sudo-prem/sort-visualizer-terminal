#include <bits/stdc++.h>
#include <windows.h>
#include "Heap.h"
#include "Merge.h"
using namespace std;

#define GREEN "\033[1m\033[32m"
#define RED "\033[1m\033[31m"
#define WHITE "\033[1m\033[37m"
#define BLUE "\033[1m\033[34m"
#define YELLOW "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define RESET "\033[0m"

int main()
{
     int t = 1;
     do
     {
          system("CLS");
          int choice{};
          cout << YELLOW << "---------------- MENU -----------------\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "|    01. Heap Sort Visualisation      |\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "|    02. Merge Sort Visualisation     |\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "|    03. EXIT                         |\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "|                                     |\n"
               << RESET;
          cout << YELLOW << "---------------------------------------\n\n"
               << RESET;
          cout << YELLOW << "Select an Option: " << RESET;
          cin >> choice;
          cout << endl;
          if (choice == 1)
          {
               Heap HeapVis;
               HeapVis.Heapify();
          }
          else if (choice == 2)
          {
               Merge MergeVis;
               MergeVis.mergeSort();
          }
          else
               return 0;
          cout << YELLOW << "Try again? (1/0): " << RESET;
          cin >> t;
          cout << endl;

     } while (t);

     return 0;
}