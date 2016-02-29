// duration::count
#include <iostream>     // std::cout
#include "chrono.h"       // std::chrono::seconds, std::chrono::milliseconds
                        // std::chrono::duration_cast

int main ()
{
  using namespace Hx::chrono;
  // std::chrono::milliseconds is an instatiation of std::chrono::duration:
  milliseconds foo (1000); // 1 second
  foo*=60;

  std::cout << "duration (in periods): ";
  std::cout << foo.count() << " milliseconds.\n";

  std::cout << "duration (in seconds): ";
  std::cout << foo.count() * milliseconds::period::num / milliseconds::period::den;
  std::cout << " seconds.\n";

  return 0;
}


/*
Output:

duration (in periods): 60000 milliseconds
duration (in seconds): 60 seconds
*/
