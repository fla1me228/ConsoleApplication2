#pragma once
//Моя часть

void FillArrayInt(int* arr, int size);
void ShowArrayInt(const int* arr, int size);
int MinArrayInt(const int* arr, int size);
int MaxArrayInt(const int* arr, int size);
void SortArrayInt(int* arr, int size);
void EditArrayInt(int* arr, int size, int index, int value);

void FillArrayDouble(double* arr, int size);
void ShowArrayDouble(const double* arr, int size);
double MinArrayDouble(const double* arr, int size);
double MaxArrayDouble(const double* arr, int size);
void SortArrayDouble(double* arr, int size);
void EditArrayDouble(double* arr, int size, int index, double value);

void FillArrayChar(char* arr, int size);
void ShowArrayChar(const char* arr, int size);
char MinArrayChar(const char* arr, int size);
char MaxArrayChar(const char* arr, int size);
void SortArrayChar(char* arr, int size);
void EditArrayChar(char* arr, int size, int index, char value);

#ifdef INTEGER
#define FillArray FillArrayInt
#define ShowArray ShowArrayInt
#define MinArray MinArrayInt
#define MaxArray MaxArrayInt
#define SortArray SortArrayInt
#define EditArray EditArrayInt
#elif defined(DOUBLE)
#define FillArray FillArrayDouble
#define ShowArray ShowArrayDouble
#define MinArray MinArrayDouble
#define MaxArray MaxArrayDouble
#define SortArray SortArrayDouble
#define EditArray EditArrayDouble
#elif defined(CHAR)
#define FillArray FillArrayChar
#define ShowArray ShowArrayChar
#define MinArray MinArrayChar
#define MaxArray MaxArrayChar
#define SortArray SortArrayChar
#define EditArray EditArrayChar
#endif