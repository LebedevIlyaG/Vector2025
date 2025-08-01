#include <iostream>
#include "Vector.h"
#include "Matrix.h"

#include <vector>

int main()
{
  TVector<int> A, B;
  TVector<int> C = A;
  std::cout<< "A = \n" << A << "\n\n" << "B = \n" << B << "\n\nC = \n" << C << std::endl;

  //int n = 20;
  //int* mas = new int[n];
  //for (int i = 0; i < n; i++)
  //  mas[i] = rand();

  //A.SetVector(&(mas[0]), 10);
  //B.SetVector(&(mas[10]), 10);


  //C = A + B;
  //TVector<int> D = A + C;

  //std::cout << "A = \n" << A << "\n\n" << "B = \n" << B << "\n\nC = \n" << C << "\n\nD = \n" << D << std::endl;
  //delete[] mas;



  //std::vector<int> vect1 = { 1, 2, 3, 4 };

  ////for (auto j = vect1.begin(); j != vect1.end(); j++)
  ////for (auto j : vect1)
  ////  std::cout << j << std::endl;


  ////for (auto k = D.begin(); k != D.end(); k++)
  ////for (TVectorIterator<int>& k = D.begin(); k != D.end(); k++)
  //for (auto k : D)
  //  std::cout << k << std::endl;

  //TMatrix<int> A;
  //TMatrix<int> B(10);
  //TMatrix<int> C(10, 10);
  //int bl = B.GetLen();
  //B.Rand();
  //C.Rand();

  //try
  //{
  //  std::cout << B << std::endl;
  //}
  //catch (ErrorClass a)
  //{
  //  std::cout << a.str << std::endl;
  //}

  return 0;
}
