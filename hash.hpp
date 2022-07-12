#include "tree.hpp"

class Hash_AB {
 public:
  Hash_AB();
  email Pesquisa(int chave);
  void Insere(email item);
  void Remove(int chave);

 private:
  static const int M = 7;
  int Hash(int Chave);
  ArvoreBinaria Tabela[M];
};