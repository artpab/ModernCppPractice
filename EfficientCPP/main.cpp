#include <deque>
#include <iostream>

using namespace std;

//// Uzycie decltype ponizej C++14:
// template <typename Container, typename Index>
// auto getValue(Container &c, Index i) -> decltype(
//    c[i]) { // auto umozliwia tutaj tzw opozniona deklaracje typu zwracanego
//  return c[i];
//}
//// Ta same metoda w C++14, powodujaca jednak pewne problemy z
/// uzyciem(kompiluje / sie ale nie bedzie mozliwe podstawienie jakiejs wartosci
/// pod wynik metody:
// template <typename Container, typename Index>
// auto getValue(Container &c, Index i) { // nie trzeba podawac decltype
//  return c[i];
//}

//// Poprawiona powyzsza metoda aby w pelni wykorzystac zarowno cechy decltype
/// jak / i auto
// template <typename Container, typename Index>
// decltype(auto) getValue(Container &c, Index i) {
//  return c[i];
//}

// Problem powyzszej implementacji jest zamkniecie sie jedynie na kontenery
// przekazywane jako lvalue. Aby rozszerzyc to na rvalue nalezy zmodyfikowac
// deklaracje metody (C++14):
template <typename Container, typename Index>
decltype(auto) getValue(Container &&c, Index i) {
  return std::forward<Container>(c)[i];
}
// c staje sie w tym momencie odwolaniem uniwersalnym. W takim przypadku dobrze
// jest aby metoda zwracala forward<Container>(c)[i] a nie move(c[i]).

//// Finalna Wersja dla C++11:
// template <typename Container, typename Index>
// auto getValue(Container &&c, Index i) -> decltype(c[i]) {
//  return std::forward<Container>(c)[i];
//}

int main() {
  const float &&a = std::move(2.1);
  std::cout << typeid(decltype(a)).name() << "\n";
  // decltype wyluskuje typ swojego parametru i przekazuje go dalej. Dzieki
  // czemu mozemy go wykorzystywac w szablonach funkcji

  std::deque<int> d(10, 5);
  std::cout << getValue(d, 5) << "\n";
  getValue(d, 5) = 10;
  std::cout << getValue(d, 5);
  return 0;
}
