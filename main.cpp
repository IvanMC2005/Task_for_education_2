#include "header.h"
using namespace std;
int main()
{
    Matrix_storage structure;
    setlocale(0, "rus");
    cout << "���������� ����\n";
    structure.read_struct(LIST3);
    structure.print();
    int n = structure.determine_country() + 1;
    cout << "�������� ����� �������� ����� � ������ ��� ������� " << n << endl;
    return 0;
}
