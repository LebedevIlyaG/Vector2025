#pragma once

#include <iostream>


template <class T>
class TStack
{
protected:
  T** data;
  int len;
  bool isNew;
  int pTop;
public:
  TStack();
  TStack(int len_);
  TStack(const TStack& obj);
  TStack(TStack&& obj);
  TStack(T** data_, int len_);
  ~TStack();

  int GetLen();

  int size()
  {
    return GetLen();
  }

  void Resize(int len_);
  void SetData(T** data_, int len_);

  void Push(T value);

  T Pop();

  T top()
  {
    if ((pTop - 1) < 0 || (pTop - 1) > len)
    {
      std::cout << "AAAAAAAAAAAAAAAAA!!!!!!" << std::endl;
      throw - 1;
    }
    return *(data[pTop-1]);
  }

  bool IsEmpty();
  bool IsFull();

  int GetCount();

  bool empty()
  {
    return IsEmpty();
  }

  void pop()
  {
    Pop();
  }

  void push(T value)
  {
    Push(value);
  }



  TStack& operator=(const TStack<T>& obj);
  TStack& operator=(TStack<T>&& obj);
  bool operator==(const TStack<T>& obj);
  bool operator!=(const TStack<T>& obj);


  template <class O>
  friend std::ostream& operator<<(std::ostream& o, TStack<O>& v);
  template <class I>
  friend std::istream& operator>>(std::istream& i, TStack<I>& v);


};

template<class T>
inline TStack<T>::TStack()
{
  data = nullptr;
  len = 0;
  isNew = true;
  pTop = 0;
}

template<class T>
inline TStack<T>::TStack(int len_) : TStack<T>::TStack()
{
  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ > 0)
  {
    len = len_;
    data = new T * [len];
    for (int i = 0; i < len; i++)
    {
      data[i] = nullptr;
    }
  }
}

template<class T>
inline TStack<T>::TStack(const TStack& obj) : TStack<T>::TStack()
{
  if (obj.len > 0)
  {
    len = obj.len;
    data = new T * [len];
    for (int i = 0; i < len; i++)
    {
      if (obj.data[i] != nullptr)
        data[i] = new T(*(obj.data[i]));
      else
        data[i] = nullptr;
    }
  }
  pTop = obj.pTop;
}

template<class T>
inline TStack<T>::TStack(TStack&& obj)
{
  len = obj.len;
  data = obj.data;
  pTop = obj.pTop;
  isNew = obj.isNew;

  obj.len = 0;
  obj.data = nullptr;
  obj.isNew = true;
}

template<class T>
inline TStack<T>::TStack(T** data_, int len_) : TStack<T>::TStack()
{
  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ > 0)
  {
    len = len_;
    data = data_;
    isNew = false;
    for (int i = 0; i < len; i++)
    {
      if (data[i] == nullptr)
      {
        pTop = i;
        break;
      }
    }
  }
}

template<class T>
inline TStack<T>::~TStack()
{
  if (isNew)
  {
    if (data != nullptr)
    {
      for (int i = 0; i < len; i++)
      {
        if (data[i] != nullptr)
          delete data[i];
      }

      delete[] data;
    }
  }

  data = nullptr;
  isNew = true;
  len = 0;
}


template<class T>
inline int TStack<T>::GetLen()
{
  return len;
}


template<class T>
inline void TStack<T>::Resize(int len_)
{
  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ == 0)
  {

    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    isNew = true;
    len = 0;
  }
  else if (len_ == len)
  {
    return;
  }
  else
  {
    T** newData = new T * [len_];
    int i = 0;
    for (; i < std::min(len, len_); i++)
    {
      newData[i] = data[i];
    }
    if (isNew)
    {
      for (; i < len; i++)
      {
        delete data[i];
      }
      delete[] data;
    }
    data = newData;
    len = len_;
    isNew = true;
  }
  
}


template<class T>
inline void TStack<T>::SetData(T** data_, int len_)
{

  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ == 0)
  {

    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    isNew = true;
    len = 0;
  }
  else if (len_ > 0)
  {
    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    data = data_;
    len = len_;
    isNew = false;
    for (int i = 0; i < len; i++)
    {
      if (data[i] == nullptr)
      {
        pTop = i;
        break;
      }
    }
  }

}

template<class T>
bool TStack<T>::IsEmpty()
{
  if (pTop == 0)
    return true;
  else
    return false;
}

template<class T>
bool TStack<T>::IsFull()
{
  if (pTop >= len)
    return true;
  return false;
}

template<class T>
inline int TStack<T>::GetCount()
{
  return pTop;
}

template<class T>
inline void TStack<T>::Push(T value)
{
  if (IsFull())
    Resize(len + 1);
  
  data[pTop] = new T(value);
  pTop++;
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty())
    throw - 1;
  pTop--;
  T p = *(data[pTop]);
  delete data[pTop];
  data[pTop] = nullptr;
  return p;
}

template<class T>
inline TStack<T>& TStack<T>::operator=(const TStack<T>& obj)
{
  return *this;
  // TODO: вставьте здесь оператор return
}

template<class T>
inline TStack<T>& TStack<T>::operator=(TStack<T>&& obj)
{
  return *this;
  // TODO: вставьте здесь оператор return
}

template<class T>
inline bool TStack<T>::operator==(const TStack<T>& obj)
{
  return false;
}

template<class T>
inline bool TStack<T>::operator!=(const TStack<T>& obj)
{
  return false;
}

template<class O>
inline std::ostream& operator<<(std::ostream& o, TStack<O>& v)
{
  return o;
  // TODO: вставьте здесь оператор return
}

template<class I>
inline std::istream& operator>>(std::istream& i, TStack<I>& v)
{
  return i;
  // TODO: вставьте здесь оператор return
}
