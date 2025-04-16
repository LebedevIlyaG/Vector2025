#include <iostream>
#include "Vector.h"

int main()
{
  TVector<int> A, B;
  TVector<int> C = A;
  std::cout<< "A = \n" << A << "\n\n" << "B = \n" << B << "\n\nC = \n" << C << std::endl;

  int n = 20;
  int* mas = new int[n];
  for (int i = 0; i < n; i++)
    mas[i] = rand();

  A.SetVector(&(mas[0]), 10);
  B.SetVector(&(mas[10]), 10);


  C = A + B;
  TVector<int> D = A + C;

  std::cout << "A = \n" << A << "\n\n" << "B = \n" << B << "\n\nC = \n" << C << "\n\nD = \n" << D << std::endl;
  delete[] mas;



  return 0;
}
