#include <iostream>

int main()
{
  int* p = nullptr;
  if (!p) {
    std::cout << "p is nullptr" << std::endl;
  }

  return 0;
}