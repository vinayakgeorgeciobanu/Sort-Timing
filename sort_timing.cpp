#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a[1000000], aSize;

enum sortTypes
{
    BUBBLE,
    INSERTION,
    SELECTION,
    MERGE,
    UNKNOWN
};

sortTypes stringToType(const string &sortStr)
{
    static const unordered_map<string, sortTypes> sortMap = {
        {"bubble", BUBBLE},
        {"insertion", INSERTION},
        {"selection", SELECTION},
        {"merge", MERGE},
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
    aSize = 0;
    while (fin >> a[aSize])
    {
        aSize++;
    }
}

void printResult()
{
    for (int i = 0; i < aSize; i++)
    {
        fout << a[i] << ' ';
    }
}

void bubbleSort()
{
    auto start = high_resolution_clock::now();

    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < aSize - 1; i++)
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

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << '\n';
}

void insertionSort()
{
    auto start = high_resolution_clock::now();

    int current, j;
    for (int i = 1; i < aSize; i++)
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

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << '\n';
}

void selectionSort()
{
    auto start = high_resolution_clock::now();

    for (int i = 0; i < aSize; i++)
    {
        int minI = i;
        for (int j = i + 1; j < aSize; j++)
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

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << '\n';
}

void merge(int left, int mid, int right)
{
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = mid;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSorting(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSorting(left, mid);
        mergeSorting(mid + 1, right);
        merge(left, mid, right);
    }
}
void mergeSort()
{
    auto start = high_resolution_clock::now();

    mergeSorting(0, aSize - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << '\n';
}

int main()
{
    cout << "What type of soting method do you want to use? " << '\n';
    cout << "Choose from these : " << '\n';
    cout << "bubble, insertion, selection, merge" << '\n';

    string input;
    cin >> input;

    sortTypes Sort = stringToType(input);

    fileRead();

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
    case MERGE:
        mergeSort();
        break;
    default:
        cout << "You didn't select a sorting method mentioned or spelled it wrong, tyr again" << '\n';
        return 0;
    }

    printResult();

    return 0;
}