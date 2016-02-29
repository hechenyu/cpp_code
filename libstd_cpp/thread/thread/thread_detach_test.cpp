#include <iostream>       // std::cout
#include "thread.h"         // std::thread, std::this_thread::sleep_for
#include "chrono.h"         // std::chrono::seconds
 
void pause_thread(int n) 
{
  Hx::this_thread::sleep_for (Hx::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}
 
int main() 
{
  std::cout << "Spawning and detaching 3 threads...\n";
  Hx::thread (pause_thread,1).detach();
  Hx::thread (pause_thread,2).detach();
  Hx::thread (pause_thread,3).detach();
  std::cout << "Done spawning threads.\n";

  std::cout << "(the main thread will now pause for 5 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  pause_thread(5);
  return 0;
}


/*
Output (after 5 seconds):

Spawning and detaching 3 threads...
Done spawning threads.
(the main thread will now pause for 5 seconds)
pause of 1 seconds ended
pause of 2 seconds ended
pause of 3 seconds ended
pause of 5 seconds ended
*/

