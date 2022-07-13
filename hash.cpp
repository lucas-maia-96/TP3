#include "hash.hpp"

Hash_AB::Hash_AB(int tam) {
  M = tam;
  Tabela = new ArvoreBinaria[M];
};

int Hash_AB::Hash(int chave) { return (chave % M); }

string Hash_AB::Pesquisa(int id_user, int id_msg) {
  int pos;
  pos = Hash(id_user);
  return "CONSULTA: " + to_string(id_user) + " " + to_string(id_msg) + ": " +
         Tabela[pos].Pesquisa(id_msg);
};

string Hash_AB::Insere(email item) {
  int pos;
  pos = Hash(item.get_ID_USER());
  Tabela[pos].Insere(item);
  return "OK: MENSAGEM " + to_string(item.get_ID_MSG()) + " PARA " +
         to_string(item.get_ID_USER()) + " ARMAZENADA EM " + to_string(pos);
};
string Hash_AB::Remove(int id_user, int id_msg) {
  int pos;
  pos = Hash(id_user);
  return Tabela[pos].Remove(id_msg);
};
