#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a[100000], num;

enum sortTypes
{
    BUBBLE,
    INSERTION,
    SELECTION,
    UNKNOWN
};

sortTypes stringToType(const string &sortStr)
{
    static const unordered_map<string, sortTypes> sortMap = {
        {"bubble", BUBBLE},
        {"insertion", INSERTION},
        {"selection", SELECTION},
    };

    auto it = sortMap.find(sortStr);
    if (it != sortMap.end())
    {
        return it->second;
    }
    else
    {
        return UNKNOWN;
    }
}

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

void mergeSort()
{
}

int main()
{
    cout << "What type of soting method do you want to use? " << '\n';
    cout << "Choose from these : " << '\n';
    cout << "bubble, insertion, selection, ... " << '\n';

    string input;
    cin >> input;

    sortTypes Sort = stringToType(input);

    fileRead();

    auto start = high_resolution_clock::now();
    switch (Sort)
    {
    case BUBBLE:
        bubbleSort();
        break;
    case INSERTION:
        insertionSort();
        break;
    case SELECTION:
        selectionSort();
        break;
    default:
        cout << "You didn't select a sorting method mentioned or spelled it wrong, tyr again" << '\n';
        return 0;
    }
    auto stop = high_resolution_clock::now();

    printResult();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by this sorting method is : ";
    cout << duration.count() << " microseconds" << '\n';

    return 0;
}
