#include <iostream>
#include <fstream>
#include <string>
#include "Array/Array.h"
#include "Timer/Timer.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open())
    {
        cerr << "Error: Could not open input.txt for reading." << '\n';
        return 1;
    }
    if (!fout.is_open())
    {
        cerr << "Error: Could not open output.txt for reading." << '\n';
        return 1;
    }

    string input;
    getline(fin, input);

    Array array;
    array.read(fin);

    Timer timer;
    array.selectSort(input, fout);
    long long duration = timer.elapsed();

    array.print(fout);

    fout << input <<" sort time: " << duration << " microseconds";

    return 0;
}