#include <bits/stdc++.h>
#include "heap.h"
#include <windows.h>
using namespace std;

#define GREEN "\033[1m\033[32m"
#define RED "\033[1m\033[31m"
#define WHITE "\033[1m\033[37m"
#define BLUE "\033[1m\033[34m"
#define YELLOW "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define RESET "\033[0m"

Heap::Heap()
{
    // Gets user data
    cout << MAGENTA << "Enter Number of Elements to Sort: " << RESET;
    cin >> this->size;
    size++;
    data.push_back(INT_MAX);
    cout << endl;
    int temp = 0;
    for (int i = 1; i < this->size; ++i)
    {
        cout << MAGENTA << "Enter Element " << i << ": " << RESET;
        cin >> temp;
        cout << endl;
        this->data.push_back(temp);
    }
    cout << MAGENTA << "Enter Delay Time in Seconds: " << RESET;
    cin >> this->time;
    cout << endl;
    Plot(0, 0);
    Delay();
}

void Heap::Plot(int first, int second)
{
    // Plots data currently in heap, after refactoring it
    system("CLS");
    cout << BLUE << "----------------------------------------------- PLOT -----------------------------------------------\n\n\n"
         << RESET;
    const int chart_height = 30;
    const int max_count = *max_element(data.begin() + 1, data.end());
    for (int current_height = chart_height; current_height > 0; --current_height)
    {
        int temp{};
        for (int i = 1; i < size; ++i)
        {
            int count = data[i];
            // refactoring data to fit in plot
            temp++;
            const int bar_height = ((count * (chart_height - 2)) / max_count) + 1;
            if (bar_height < current_height)
                cout << "          ";
            else if (bar_height == current_height)
            {
                if (first == 0 and second == 0)
                    cout << GREEN << "  ______  " << RESET;
                else if (temp == first or temp == second)
                    cout << RED << "  ______  " << RESET;
                else
                    cout << YELLOW << "  ______  " << RESET;
            }
            else
            {
                if (first == 0 and second == 0)
                    cout << GREEN << " |######| " << RESET;
                else if (temp == first or temp == second)
                    cout << RED << " |$$$$$$| " << RESET;
                else
                    cout << YELLOW << " |      | " << RESET;
            }
        }
        cout << '\n';
    }
    cout << "\n";
    for (int i = 1; i < size; ++i)
    {
        if (data[i] < 10)
            cout << WHITE << "    0" << data[i] << "    " << RESET;
        else
            cout << WHITE << "    " << data[i] << "    " << RESET;
    }
    cout << "\n\n";
    for (int i = 1; i < size; ++i)
    {
        if (i < 10)
            cout << WHITE << "    0" << i << "    " << RESET;
        else
            cout << WHITE << "    " << i << "    " << RESET;
    }
    cout << BLUE << "\n\n\n\n-----------------------------------------------------------------------------------------------------\n\n"
         << RESET;
}

void Heap::Delay()
{
    // delays time before next plot is displayed
    unsigned int currDelay = this->time * 1000;
    Sleep(currDelay);
}

void Heap::Heapify()
{
    // Self Insertion Phase (Making vector<int>, into Heap(inPlace))
    for (int i = 2; i < data.size(); ++i)
    {
        int j = i;
        while (j / 2 >= 1 and data[j] > data[j / 2])
        {
            Plot(j, j / 2);
            Delay();
            swap(data[j], data[j / 2]);
            Plot(j, j / 2);
            j /= 2;
            Delay();
        }
    }
    // Converted into a heap
    Plot(0, 0);
    Delay();
    // Deleting and placing the value at the end
    int last = size - 1;
    while (last > 0)
    {
        int i = 1;
        int j = 2;
        Plot(i, last);
        Delay();
        swap(data[i], data[last]);
        Plot(i, last);
        Delay();
        while ((j < last and data[i] < data[j]) or (j + 1 < last and data[i] < data[j + 1]))
        {
            if (j + 1 < last and data[j + 1] > data[j])
                j += 1;
            Plot(i, j);
            Delay();
            swap(data[i], data[j]);
            Plot(i, j);
            Delay();
            i = j;
            j *= 2;
        }
        last--;
    }
    Plot(0, 0);
    Delay();
}
