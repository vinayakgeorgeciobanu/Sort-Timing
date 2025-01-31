#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Array
{
private:
    vector<long long> arr;
    long long int arr_size;

    void bubbleSort();
    void selectionSort();
    void insertionSort();

public:
    vector<long long> getArray() const;
    void read(istream &in);
    void print(ostream &out) const;
    void selectSort(const string &input, ostream &out);
};

#endif