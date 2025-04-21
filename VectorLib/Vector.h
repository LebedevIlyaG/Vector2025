#pragma once
#include <iostream>

template <class T>
class TVectorIterator;

template <class T>
class TVector
{
protected:
  T* vector;
  int len;
  bool isNew;
public:
  TVector();
  TVector(int len_);
  TVector(const TVector& obj);
  TVector(TVector&& obj);
  ~TVector();

  int GetLen();
  void GetVector(T** vector_);

  void SetLen(int len_);
  void SetVector(T* vector_, int len_);

  TVector operator+(const TVector<T>& obj);
  TVector operator-(const TVector<T>& obj);
  T operator*(const TVector<T>& obj);
  TVector operator*(const T mul);
  TVector operator/(const T div);

  TVector& operator=(const TVector<T>& obj);
  TVector& operator=(TVector<T>&& obj);
  bool operator==(const TVector<T>& obj);

  T& operator[](int index) const;

  template <class O>
  friend std::ostream& operator<<(std::ostream& o, TVector<O>& v);
  template <class I>
  friend std::istream& operator>>(std::istream& i, TVector<I>& v);

  void SortBable(T* obj);
  void SortQuick(T* obj);
  void SortInsertion(T* obj);

  T Normalization(T obj);
  T FirstNorm(T obj);
  T SecondNorm(T obj);
  T InfinityNorm(T obj);
  T HelderNorm(T obj);

  TVectorIterator<T> begin();
  TVectorIterator<T> end();
};


template<class T>
class TVectorIterator
{
protected:
  TVector<T>& p;
  int index;
public:
  TVectorIterator(TVector<T>& vector, int index_ = 0);
  T& operator*();
  TVectorIterator<T>& operator++();
  TVectorIterator<T>& operator++(int);

  bool operator != (const TVectorIterator<T>& p);
};

template<class T>
inline TVector<T>::TVector()
{
  vector = nullptr;
  isNew = true;
  len = 0;
}

template<class T>
inline TVector<T>::TVector(int len_)
{
  if (len_ < 0)
    throw(0);
  else if (len_ == 0)
  {
    len = 0;
    vector = nullptr;
    return;
  }
  else
    len = len_;

  vector = new T[len]{ 0 };
  isNew = true;

}

template<class T>
inline TVector<T>::TVector(const TVector& obj) :
  TVector<T>::TVector(obj.len)
{
  for (int i = 0; i < len; i++)
    vector[i] = obj.vector[i];
  isNew = true;
}

template<class T>
inline TVector<T>::TVector(TVector&& obj)
{
  vector = obj.vector;
  len = obj.len;
  isNew = obj.isNew;

  obj.len = 0;
  obj.vector = nullptr;
  obj.isNew = false;

}

template<class T>
inline TVector<T>::~TVector()
{
  if (vector != nullptr)
    if (isNew == true)
      delete[] vector;
  vector = nullptr;
  len = 0;
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline void TVector<T>::GetVector(T** vector_)
{
  *vector_ = vector;
}

template<class T>
inline void TVector<T>::SetLen(int len_)
{
  if (len == len_)
    return;
  if (len_ < 0)
    throw - 1;
  else if (len_ == 0)
  {
    if (vector != nullptr)
      delete[] vector;
    vector = nullptr;
    len = 0;
    return;
  }

  T* newVector = new T[len_];//10
  for (int i = 0; i < std::min(len, len_); i++)
    newVector[i] = vector[i];

  if (vector != nullptr)
    delete[] vector;

  vector = newVector;
  len = len_;
}

template<class T>
inline void TVector<T>::SetVector(T* vector_, int len_)
{
  if (len_ < 0)
    throw - 1;
  if (vector != nullptr)
    delete[] vector;

  isNew = false;
  vector = vector_;
  len = len_;

}



template<class T>
inline TVector<T> TVector<T>::operator+
(const TVector<T>& obj)
{
  if (len != obj.len)
    throw - 1;

  TVector<T> res = len;
  for (int i = 0; i < len; i++)
  {
    res[i] = (*this)[i] + obj[i];
  }
  //res.vector[i] = vector[i] + obj.vector[i];

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& obj)
{
  if (len != obj.len)
    throw - 1;

  TVector<T> res = len;
  for (int i = 0; i < len; i++)
    res[i] = (*this)[i] - obj[i];

  return res;
}

template<class T>
inline T TVector<T>::operator*(const TVector<T>& obj)
{
  if (len != obj.len)
    throw - 1;

  T res = 0;
  for (int i = 0; i < len; i++)
    res += (*this)[i] * obj[i];

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const T mul)
{
  TVector<T> res = len;
  for (int i = 0; i < len; i++)
    res[i] *= mul;

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const T div)
{
  TVector<T> res = len;
  for (int i = 0; i < len; i++)
    res[i] /= div;

  return res;
}

template<class T>
inline TVector<T>& TVector<T>::operator=
(const TVector<T>& obj)
{
  if (this == &obj)
    return *this;

  if (len != obj.len)
  {
    delete[] vector;
    vector = new T[obj.len];
  }
  len = obj.len;
  for (int i = 0; i < len; i++)
    vector[i] = obj.vector[i];

  return *this;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(TVector<T>&& obj)
{
  if (this == &obj)
    return *this;

  if (vector != nullptr)
    delete[] vector;

  vector = obj.vector;
  len = obj.len;
  obj.vector = nullptr;
  obj.len = 0;
  return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& obj)
{
  return false;
}

template<class T>
inline T& TVector<T>::operator[](int index) const
{
  if (vector == nullptr)
    throw - 1;
  if (index < 0 || index > len)
    throw - 1;

  return vector[index];
}

template<class T>
inline void TVector<T>::SortBable(T* obj)
{
}

template<class T>
inline void TVector<T>::SortQuick(T* obj)
{
}

template<class T>
inline void TVector<T>::SortInsertion(T* obj)
{
}

template<class T>
inline T TVector<T>::Normalization(T obj)
{
  return T();
}

template<class T>
inline T TVector<T>::FirstNorm(T obj)
{
  return T();
}

template<class T>
inline T TVector<T>::SecondNorm(T obj)
{
  return T();
}

template<class T>
inline T TVector<T>::InfinityNorm(T obj)
{
  return T();
}

template<class T>
inline T TVector<T>::HelderNorm(T obj)
{
  return T();
}

template<class T>
inline TVectorIterator<T> TVector<T>::begin()
{
  return TVectorIterator<T>(*this, 0);
}

template<class T>
inline TVectorIterator<T> TVector<T>::end()
{
  return TVectorIterator<T>(*this, len);
}

template<class O>
inline std::ostream& operator<<(std::ostream& o, TVector<O>& v)
{
  for (int i = 0; i < v.GetLen(); i++)
    o << v[i] << "\t";
  return o;
}

template<class I>
inline std::istream& operator>>(std::istream& i, TVector<I>& v)
{
  return i;
}

template<class T>
inline TVectorIterator<T>::TVectorIterator(TVector<T>& vector, int index_):
  p(vector), index(index_)
{
}

template<class T>
inline T& TVectorIterator<T>::operator*()
{
  return p[index];
}

template<class T>
inline TVectorIterator<T>& TVectorIterator<T>::operator++()
{
  index++;
  return *this;
}

template<class T>
inline TVectorIterator<T>& TVectorIterator<T>::operator++(int)
{
  index++;
  return* this;
}

template<class T>
inline bool TVectorIterator<T>::operator!=(const TVectorIterator<T>& p)
{
  return index != p.index;
}
