#pragma once
#include <iostream>
#include "Vector.h"
#include "ErrorClass.h"


template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix();
  TMatrix(int len_);
  TMatrix(int l, int h);
  TMatrix(const TMatrix& obj);
  TMatrix(TMatrix&& obj);
  virtual ~TMatrix();


  virtual void SetLen(int len_);
  virtual void SetMatrix(T* matrix_, int l, int h);

  virtual TMatrix<T> operator+(const TMatrix<T>& obj);
  virtual TMatrix<T> operator-(const TMatrix<T>& obj);
  virtual TMatrix<T> operator*(const TMatrix<T>& obj);
  virtual TMatrix<T> operator/(const TMatrix<T>& obj);
  virtual TMatrix<T> operator*(const T mul);
  virtual TMatrix<T> operator/(const T div);

  virtual TMatrix<T>& operator=(const TMatrix<T>& obj);
  virtual TMatrix<T>& operator=(TMatrix<T>&& obj);
  virtual bool operator==(const TMatrix<T>& obj);

  virtual TVector<T>& operator[](int index) const;

  template <class O>
  friend std::ostream& operator<<(std::ostream& o, TMatrix<O>& v);
  template <class I>
  friend std::istream& operator>>(std::istream& i, TMatrix<I>& v);


  virtual T Normalization(T obj);
  virtual T FirstNorm(T obj);
  virtual T SecondNorm(T obj);
  virtual T InfinityNorm(T obj);
  virtual T HelderNorm(T obj);

  virtual void Rand();

  //TVector<T> SolutionOfSystemsOfLinearEquations(const TVector<T>& p);
  //TVector<T> operator ()(const TVector<T>& p);

  //virtual TVectorIterator<T> begin();
  //virtual TVectorIterator<T> end();
};
