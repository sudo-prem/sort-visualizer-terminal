#include <bits/stdc++.h>
#include <windows.h>
#include "Merge.h"
using namespace std;

#define GREEN "\033[1m\033[32m"
#define RED "\033[1m\033[31m"
#define WHITE "\033[1m\033[37m"
#define BLUE "\033[1m\033[34m"
#define YELLOW "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define RESET "\033[0m"

Merge::Merge()
{
    // Gets user data
    cout << MAGENTA << "Enter Number of Elements to Sort: " << RESET;
    cin >> this->size;
    cout << endl;
    int temp = 0;
    for (int i = 0; i < this->size; ++i)
    {
        cout << MAGENTA << "Enter Element " << i + 1 << ": " << RESET;
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

void Merge::Plot(int first, int second)
{
    // Plots data currently in Merge, after refactoring it
    system("CLS");
    cout << BLUE << "----------------------------------------------- PLOT -----------------------------------------------\n\n\n"
         << RESET;
    const int chart_height = 30;
    const int max_count = *max_element(data.begin(), data.end());
    for (int current_height = chart_height; current_height > 0; --current_height)
    {
        int temp{};
        for (int i = 0; i < size; ++i)
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
    for (int i = 0; i < size; ++i)
    {
        if (data[i] < 10)
            cout << WHITE << "    0" << data[i] << "    " << RESET;
        else
            cout << WHITE << "    " << data[i] << "    " << RESET;
    }
    cout << "\n\n";
    for (int i = 0; i < size; ++i)
    {
        if (i < 10)
            cout << WHITE << "    0" << i << "    " << RESET;
        else
            cout << WHITE << "    " << i << "    " << RESET;
    }
    cout << BLUE << "\n\n\n\n-----------------------------------------------------------------------------------------------------\n\n"
         << RESET;
}

void Merge::Delay()
{
    // delays time before next plot is displayed
    unsigned int currDelay = this->time * 1000;
    Sleep(currDelay);
}

void Merge::merge(int l, int mid, int h)
{
    int i{l}, j{mid + 1}, k{0};
    vector<int> res(h + 1);
    while (i <= mid and j <= h)
    {
        if (data[i] < data[j])
            res[k++] = data[i++];
        else
            res[k++] = data[j++];
    }
    while (i <= mid)
        res[k++] = data[i++];
    while (j <= h)
        res[k++] = data[j++];
    k = 0;
    while (l <= h)
        data[l++] = res[k++];
}

void Merge::mergeSort()
{
    int start = 0, end = size;
    int i{}, j{};
    int l{}, mid{}, h{};
    // Outer For loop is to denote how many elements to take at a time
    // First merge: 2 elements at a time
    // Second merge: 4 elements at a time
    // and so on..
    for (i = 2; i <= end; i *= 2)
    {
        // Inner for loop is to find the start and end of each
        for (j = 0; j + i - 1 < end; j += i)
        {
            l = j;
            h = j + i - 1;
            mid = l / 2 + h / 2;
            Plot(l + 1, h + 1);
            Delay();
            merge(l, mid, h);
        }
    }
    // if total number of elements in list is odd,
    // we have to merge the last element separately
    Plot(0 + 1, end);
    Delay();
    if (i / 2 < end)
        merge(0, i / 2 - 1, end - 1);
    Plot(0, 0);
    Delay();
}