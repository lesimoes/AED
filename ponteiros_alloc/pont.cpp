#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
    int var, *pont; //Forma direta para declarar variáveis do mesmo tipo
    var = 1000;
    pont = &var;
    
    cout << "Valor do ponteiro pont: " << pont << endl;
    cout << "Valor da variável var: " << var << endl;
    cout << "Endereço da variável var:" << &var << endl;
    cout << "Endereço do ponteiro:" << &pont << endl;
    cout << "Endereço para onde o ponteiro pont aponta: " << pont << endl;
    
    return 0;
}