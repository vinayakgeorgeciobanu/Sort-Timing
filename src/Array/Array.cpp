#include "Array.h"

// private functions
void Array::bubbleSort()
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = 0; j < arr_size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Array::selectionSort()
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Array::insertionSort()
{
    for (int i = 1; i < arr_size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// public functions
vector<long long> Array::getArray() const
{
    return arr;
}

void Array::read(istream &in)
{
    int num;
    while (in >> num)
    {
        arr.push_back(num);
    }
    arr_size = arr.size();
}

void Array::print(ostream &out) const
{
    for (int num : arr)
    {
        out << num << ' ';
    }
    out << '\n';
}

void Array::selectSort(const string &input, ostream &out)
{
    if (input == "bubble")
    {
        bubbleSort();
    }
    else if (input == "selection")
    {
        selectionSort();
    }
    else if (input == "insertion")
    {
        insertionSort();
    }
    else
    {
        out << "Invalid sorting method: " << input << '\n'
             << "Please use 'bubble', 'selection' or 'insertion'.\n";
        return;
    }
}
