#include <iostream>
using namespace std;

int main(void)
{

  cout << "NUMERO SECRETO" << endl
       << endl;
  float numerosec = 12;
  float numerp = 0;

  do
  {
    cout << "Adivine el numero secreto: " << endl;
    cin >> numerp;

    if (numerp < numerosec)
    {
      cout << "El numero " << numerp << " es menor al numero secreto." << endl;
    }
    else if (numerp > numerosec)
    {
      cout << "El numero " << numerp << " es meayor al numero secreto." << endl;
    }

  } while (numerosec != numerp);

  return 0;
}