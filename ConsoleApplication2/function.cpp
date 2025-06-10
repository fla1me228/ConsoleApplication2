#include "function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Часть Тамира 
void FillArrayInt(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;
}
void ShowArrayInt(const int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int MinArrayInt(const int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min) min = arr[i];
    return min;
}
int MaxArrayInt(const int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max) max = arr[i];
    return max;
}
void SortArrayInt(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void EditArrayInt(int* arr, int size, int index, int value) {
    if (index >= 0 && index < size)
        arr[index] = value;
}

void FillArrayDouble(double* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = (rand() % 10000) / 100.0;
}
void ShowArrayDouble(const double* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
double MinArrayDouble(const double* arr, int size) {
    double min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min) min = arr[i];
    return min;
}
double MaxArrayDouble(const double* arr, int size) {
    double max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max) max = arr[i];
    return max;
}
void SortArrayDouble(double* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void EditArrayDouble(double* arr, int size, int index, double value) {
    if (index >= 0 && index < size)
        arr[index] = value;
}

void FillArrayChar(char* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = 'A' + rand() % 26;
}
void ShowArrayChar(const char* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
char MinArrayChar(const char* arr, int size) {
    char min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min) min = arr[i];
    return min;
}
char MaxArrayChar(const char* arr, int size) {
    char max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max) max = arr[i];
    return max;
}
void SortArrayChar(char* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void EditArrayChar(char* arr, int size, int index, char value) {
    if (index >= 0 && index < size)
        arr[index] = value;
}