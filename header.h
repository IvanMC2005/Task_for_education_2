#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <functional>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <locale>
#include <functional>
#define LIST1 "Test3.txt"
#define LIST2 "Test2.txt"
#define LIST3 "Test5.txt"
#define MATRIX1 "Test.txt"
#define MATRIX2 "Test1.txt"
#define MATRIX3 "Test4.txt"
using namespace std;
class Matrix_storage
{
public:
    int ** A;
    int N;
    int typeofr;
    Matrix_storage();
    int BFS(int );
    int next (int i, int cur);
    void allocate_struct();
    void print();
    void read_struct(string);
    int determine_country();
    ~Matrix_storage();
};
template <typename T>
void fill_data(string str, T &temp, function<bool(T&)> f);
#endif // HEADER_H_INCLUDED
