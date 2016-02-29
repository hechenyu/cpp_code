// example for thread::joinable
#include <iostream>       // std::cout
#include "thread.h"         // std::thread
 
void mythread() 
{
  // do stuff...
}
 
int main() 
{
  Hx::thread foo;
  Hx::thread bar(mythread);

  std::cout << "Joinable after construction:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  if (foo.joinable()) foo.join();
  if (bar.joinable()) bar.join();

  std::cout << "Joinable after joining:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  return 0;
}


/*
Output (after 3 seconds):

Joinable after construction:
foo: false
bar: true
Joinable after joining:
foo: false
bar: false
*/
