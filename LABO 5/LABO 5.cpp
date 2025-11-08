#include <iostream>
using namespace std;

int main(void)
{

cout << "TABLAS DE MULTIPLICAR" << endl;
  int num1 = 0;
  int num2;

cout << "Escriba un numero del 1 al 20: " << endl;
    cin >> num2;

for(num1 = 1; num1 <= 10; num1++ ){

  cout << num2 << " * " << num1 << " = " << num2*num1 << endl;

}

return 0;

}