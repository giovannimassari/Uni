#include "Razionale.hh"

#include <iostream>

void do_something(Numerica::Razionale r) {
  (void) r;
}

void
test01() {
  using Numerica::Razionale;

  Razionale r;        // costruttore default

  Razionale r1(r);     // costruttore di copia
  Razionale r2 = r;    // costruttore di copia

  Razionale r3 { r };    // costruttore di copia (C++11)
  Razionale r4 = { r };  // costruttore di copia (C++11)

  Razionale r5(1, 2);  // costruzione diretta
  Razionale r6 {1, 2}; // costruzione diretta (C++11)
  Razionale r7(1);     // costruzione diretta
  Razionale r8{1};     // costruzione diretta (C++11)

  // Razionale r9 = '?'; // costruzione implicita (da evitare!)

  do_something(r8);
  // do_something(1234);  // da evitare!

  r = r1;           // assegnamento per copia
  r = Razionale(1); // assegnamento per spostamento
  r2 = r1 = r;      // concatenazione assegnamenti (da evitare?)
}

void test02() {
  using Numerica::Razionale;

  Razionale r, r1, r2;

  // Operatori aritmetici binari.
  r = r1 + r2;
  r = r1 - r2;
  r = r1 * r2;
  r2 = Razionale(1);
  r = r1 / r2; // divisione per zero?

  // Operatori aritmetici unari.
  r = -r1;
  r = +r1;

  // op-assign.
  r += r1;
  r -= r1;
  r *= r1;
  r /= r1; // divisione per zero?

  // concatenazione assegnamenti?
  r = (r += r1);
  r += r += r1 -= r1; // anche no?
}

void test03() {
  using Numerica::Razionale;

  Razionale r;

  // Pre- incremento e decremento.
  ++r;
  --r;
  ++ ++r;

  // Post- incremento e decremento (evitare?).
  r++;
  r--;

  ++++++++++++++++++++++++++++++++++++++++r; // anche no?
}

void test04() {
  using Numerica::Razionale;

  // Operatori relazionali.
  Razionale r1, r2;
  bool b;
  b = (r1 == r2);
  b = (r1 != r2);
  b = (r1 < r2);
  b = (r1 <= r2);
  b = (r1 >= r2);
  b = (r1 > r2);

  (void) b;
}

void test05() {
  using Numerica::Razionale;

  Razionale r1, r2;

  // r1 = r1 + 1234; // aritmetica mista?
  // r1 = 1234 + r1; // aritmetica mista?


  // Input e output
  std::cin >> r1;
  std::cin >> r1 >> r2;

  std::cout << r1;
  // std::cout << r1 << " + " << r2 << " = " << (r1 + r2) << std::endl;
}


void test06(const Numerica::Razionale& r) {
  std::cout << r;
}


int main() {
  test01();
  test02();
  test03();
  test04();
  test05();
}


