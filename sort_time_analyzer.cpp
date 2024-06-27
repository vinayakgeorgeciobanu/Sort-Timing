#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a[100000], num;

void fileRead()
{
    num = 0;
    while (fin >> a[num])
    {
        num++;
    }
}

void printResult()
{
    for (int i = 0; i < num; i++)
    {
        fout << a[i] << ' ';
    }
}

void bubbleSort()
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < num - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                sorted = false;
            }
        }
    } while (!sorted);
}

void insertionSort()
{
    int current, j;
    for (int i = 1; i < num; i++)
    {
        current = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

void selectionSort()
{
    for (int i = 0; i < num; i++)
    {
        int minI = i;
        for (int j = i + 1; j < num; j++)
        {
            if (a[i] < a[minI])
            {
                minI = i;
            }
        }
        if (minI != i)
        {
            int aux = a[i];
            a[i] = a[minI];
            a[minI] = aux;
        }
    }
}

int main()
{
    cout << "What type of soting method do you want to use? " << '\n';
    cout << "Choose from these : " << '\n';
    cout << "bubble, insertion, selection, ... " << '\n';

    char sortType[20];
    cin >> sortType;
    for (int i = 0; i < strlen(sortType); i++)
    {
        sortType[i] = tolower(sortType[i]);
    }

    fileRead();

    auto start = high_resolution_clock::now();
    if (strcmp(sortType, "bubble") == 0)
    {

        bubbleSort();
    }
    else if (strcmp(sortType, "insertion") == 0)
    {
        insertionSort();
    }
    else if (strcmp(sortType, "selection") == 0)
    {
        selectionSort();
    }
    else
    {
        cout << "You didn't select a sorting method mentioned or spelled it wrong, retry" << '\n';
    }
    auto stop = high_resolution_clock::now();

    printResult();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by this sorting method is : ";
    cout << duration.count() << " microseconds" << '\n';

    return 0;
}
