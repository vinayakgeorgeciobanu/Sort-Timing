#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Timer
{
private:
    string name;
    time_point<high_resolution_clock> start;

public:
    Timer(const string &name) : name(name), start(high_resolution_clock::now()) {}

    ~Timer()
    {
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        fout << name << " Time: " << duration.count() << " microseconds" << '\n';
    }
};

class Numbers
{
private:
    vector<long long> arr; // array to store numbers
    int arr_size;          // number of elements in array

    // bubble sort implementation
    void bubbleSort()
    {
        Timer timer("Bubble Sort");
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
    // selection sort implementation
    void selectionSort()
    {
        Timer timer("Selection Sort");
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
    // insertion sort implementation
    void insertionSort()
    {
        Timer timer("Insertion Sort");
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

public:
    Numbers() : arr_size(0) {}
    // read numbers from input array
    void read()
    {
        int num;
        while (fin >> num)
        {
            arr.push_back(num);
        }
        arr_size = arr.size();
    }
    // print the sorted array to the output file
    void print()
    {
        for (int num : arr)
        {
            fout << num << ' ';
        }
    }
    // select sorting method based on input
    void selectSort(const string &input)
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
            fout << "Invalid sorting method: " << input << ". Please use 'bubble', 'selection', or 'insertion'.\n";
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
    getline(fin, input);

    // creat a Number object, read data, sort, and print the result
    Numbers nums;
    nums.read();
    nums.selectSort(input);
    nums.print();

    return 0;
}