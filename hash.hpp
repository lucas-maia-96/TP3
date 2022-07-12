#include "tree.hpp"

class Hash_AB {
 public:
  Hash_AB(int tam);
  email Pesquisa(int chave);
  void Insere(email item);
  void Remove(int chave);

 private:
  int M;
  int Hash(int Chave);
  ArvoreBinaria *Tabela = new ArvoreBinaria[M];
};