#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdarg.h>
#include <cmath>


template<class T, int DIM>
class TPoint
{
private:
  T coords[DIM];
  int color;
  int size;
public:
  TPoint();
  TPoint(T* coords_, int color = 1, int size = 1);
  ~TPoint();
  double DistToOrigin();
  double DistTo(TPoint<T, DIM>& p);


  int GetDim();
  T* GetCoords();
  void SetCoords(T* coords_);
  void setCoordinates(T x, ...);
  int GetColor();
  void SetColor(int color_);
  int GetSize();
  void SetSize(int size_);

  T& operator[](int index);

  template<class V, int DIM>
  friend std::istream& operator>>(std::istream& i, TPoint<V, DIM>& p);

  template<class V, int DIM>
  friend std::ostream& operator<<(std::ostream& o, TPoint<V, DIM>& p);
};

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint()
{
  for (int i = 0; i < DIM; ++i)
  {
    coords[i] = 0;
  }
}

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint(T* coords_, int color_, int size_)
{
  coords = new T[DIM];
  for (int i = 0; i < DIM; ++i)
  {
    coords[i] = coords_[i];
  }
  color = color_;

  if (size_ <= 0)
    throw "Non positive size";
  else
    size = size_;
}

template<class T, int DIM>
inline TPoint<T, DIM>::~TPoint()
{
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistToOrigin()
{
  double res = 0;
  for (int i = 0; i < DIM; ++i)
    res += coords[i] * coords[i];
  return sqrt(res);
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistTo(TPoint<T, DIM>& p)
{
  double res = 0;
  for (int i = 0; i < DIM; ++i)
    res += (coords[i] - p.coords[i]) * (coords[i] - p.coords[i]);
  return sqrt(res);
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline T* TPoint<T, DIM>::GetCoords()
{
  T* res = new T[DIM];
  for (int i = 0; i < DIM; ++i)
    res[i] = coords[i];
  return res;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetCoords(T* coords_)
{
  for (int i = 0; i < DIM; ++i)
    coords[i] = coords_[i];
}

template<class T, int DIM>
inline void TPoint<T, DIM>::setCoordinates(T x, ...)
{
  int result = 0;
  va_list factor;         //указатель va_list
  va_start(factor, x);    // устанавливаем указатель
  coords[0] = x;
  for (int i = 1; i < DIM; i++)
  {
    coords[i] = va_arg(factor, T);  // получаем значение текущего параметра типа int
  }
  va_end(factor); // завершаем обработку параметров
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetColor()
{
  return color;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetColor(int color_)
{
  color = color_;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    throw "Non positive size";
  else
    size = size_;
}

template<class T, int DIM>
inline T& TPoint<T, DIM>::operator[](int index)
{
  if (index < 0 || index >= DIM)
  {
    throw "Out of bounds";
  }
  else {
    return coords[index];
  }
}

template<class V, int DIM>
inline std::istream& operator>>(std::istream& i, TPoint<V, DIM>& p)
{
  int dim_ = p.GetDim();
  V* coords_ = new V[dim_];
  for (int j = 0; j < dim_; ++j)
  {
    i >> coords_[j];
  }
  p.SetCoords(coords_);
  delete[] coords_;

  return i;
}

template<class V, int DIM>
inline std::ostream& operator<<(std::ostream& o, TPoint<V, DIM>& p)
{
  for (int i = 0; i < p.GetDim(); ++i)
  {
    o << p[i] << ' ';
  }
  return o;
}