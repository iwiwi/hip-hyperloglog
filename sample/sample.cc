#include "../src/hip_estimator.h"
#include <iostream>
#include <string>

int main() {
  {
    // Integers
    hip_estimator::hip_estimator<int> h;
    h.insert(1);
    h.insert(10);
    h.insert(5);
    h.insert(1);
    h.insert(3);
    h.insert(10);
    std::cout << h.count() << std::endl;  // #{1, 3, 5, 10} = 4
  }

  {
    // Strings
    hip_estimator::hip_estimator<std::string> h;
    std::cout << h.count() << std::endl;  // #{} = 0
    h.insert("akiba");
    h.insert("iwi");
    h.insert("akiba");
    h.insert("iwi");
    h.insert("akiba");
    h.insert("iwi");
    h.insert("akiba");
    std::cout << h.count() << std::endl;  // #{akiba, iwi} = 2
    h.insert("takuya");
    std::cout << h.count() << std::endl;  // #{akiba, iwi, takuya} = 3
  }

  return 0;
}