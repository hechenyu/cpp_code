// unique_ptr::release example
#include <iostream>
#include "my_auto_ptr.h"

int main () {
  Auto_ptr<int> auto_pointer (new int);
  int * manual_pointer;

  *auto_pointer=10;

  manual_pointer = auto_pointer.release();
  // (auto_pointer is now empty)

  std::cout << "manual_pointer points to " << *manual_pointer << '\n';

  delete manual_pointer;

  return 0;
}
