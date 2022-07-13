#include <iostream>

#include "hash.hpp"

int main() {
  int m = 7;
  Hash_AB a = Hash_AB(m);

  email b;

  b.set_ID_MSG(5);
  b.set_ID_USER(2);
  b.set_mensagem("OI! ESSE TESTE E LEGAL");

  cout << a.Insere(b) << endl;

  cout << a.Pesquisa(2, 5) << endl;

  cout << a.Remove(2, 5) << endl;

  return 0;
}
