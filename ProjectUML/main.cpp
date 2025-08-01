#include "Header.h"


#include <direct.h>
#include <windows.h>


typedef TPoint<int, 2>* Init_t();

int main()
{
  HINSTANCE mLibHandle;


  TPoint < int, 2>* B = nullptr;


  mLibHandle = LoadLibrary(TEXT("MyUML.dll"));
  if (!mLibHandle)
  {
    std::cerr << "Cannot load library: " << TEXT("PointLib.dll") << std::endl;
    return -1;
  }


  Init_t* mInit = (Init_t*)GetProcAddress(mLibHandle, "Init");

  if (!mInit)
  {
    std::cerr << "Cannot load symbols: " << GetLastError() << std::endl;

    FreeLibrary(mLibHandle);

    mLibHandle = NULL;
    return -1;
  }

  B = mInit();

  B->setCoordinates(1, 2);

  std::cout << *B << std::endl;

  return 0;
}