#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char **argv)
{
  int longest = 0;
  int terms = 0;
  int i;
  unsigned long j;
        
  auto startTime = std::chrono::system_clock::now();

  for (i = 1; i <= 5000000; i++)
  {
      j = i;
      int this_terms = 1;

      while (j != 1)
      {
            this_terms++;
      
            if (this_terms > terms)
            {
                    terms = this_terms;
                    longest = i;
                  }
      
            if (j % 2 == 0)
            {
                    j = j / 2;
                  }
            else
            {
                    j = 3 * j + 1;
                  }
          }
    }

    auto endTime = std::chrono::system_clock::now();
    std::cout << std::chrono::duration<double, milli>(endTime - startTime).count() / 1000.0 << std::endl;

  printf("longest: %d (%d)\n", longest, terms);
  return 0;
}
