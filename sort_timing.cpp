#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Numbers
{
private:
    int arr[1000000]; // array to store numbers
    int arr_size;     // number of elements in array
    // bubble sort implementation
    void bubbleSort()
    {
        auto start = high_resolution_clock::now();
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
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        fout << "Time: " << duration.count() << " microseconds" << '\n';
    }
    // selection sort implementation
    void selectionSort()
    {
        auto start = high_resolution_clock::now();
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
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        fout << "Time: " << duration.count() << " microseconds" << '\n';
    }
    // insertion sort implementation
    void insertionSort()
    {
        auto start = high_resolution_clock::now();
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
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        fout << "Time: " << duration.count() << " microseconds" << '\n';
    }

public:
    // initializes the array and the size 
    Numbers() : arr_size(0), arr{0} {}
    // read numbers from input array
    void read()
    {
        int i = 0;
        while (fin >> arr[i])
        {
            i++;
        }
        arr_size = i;
    }
    // print the sorted array to the output file
    void print()
    {
        for (int i = 0; i < arr_size; i++)
        {
            fout << arr[i] << ' ';
        }
    }
    // select sorting method based on input
    void selectSort(string input)
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
            fout << "You didn't select a sorting method mentioned or spelled it wrong, tyr again" << '\n';
            return; // exit function if the input is invalid
        }
    }
};

int main()
{
    // check if files are opened successfully
    if (!fin.is_open())
    {
        cerr << "Error: Could not open input.txt for reading." << '\n';
        return 1;
    }
    if (!fout.is_open())
    {
        cerr << "Error: Could not open output.txt for writing." << '\n';
        return 1;
    }
    // read the sorting method from the file
    string input;
    fin >> input;
    // creat a Number object, read data, sort, and print the result
    Numbers nums;
    nums.read();
    nums.selectSort(input);
    nums.print();
    // close files
    fin.close();
    fout.close();
    return 0;
}