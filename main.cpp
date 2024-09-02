#include "header.h"
using namespace std;
int main()
{
    Matrix_storage structure;
    setlocale(0, "rus");
    cout << "Полученный граф\n";
    structure.read_struct(LIST3);
    structure.print();
    int n = structure.determine_country() + 1;
    cout << "Выгоднее всего провести съезд в городе под номером " << n << endl;
    return 0;
}
