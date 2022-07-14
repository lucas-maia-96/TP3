#include "tree.hpp"

class Hash_AB {
 public:
  Hash_AB(int tam);
  string Pesquisa(int id_user, int id_msg);
  string Insere(email item);
  string Remove(int id_user, int id_msg);

 private:
  int M;
  int Hash(int Chave);
  ArvoreBinaria *Tabela;
};