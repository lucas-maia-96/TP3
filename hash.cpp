#include "hash.hpp"

Hash_AB::Hash_AB(int tam) { M = tam; };

int Hash_AB::Hash(int chave) { return (chave % M); }

email Hash_AB::Pesquisa(int chave) {
  int pos;
  email item;
  pos = Hash(chave);
  item = Tabela[pos].Pesquisa(chave);
  return item;
};

void Hash_AB::Insere(email item) {
  email aux;
  int pos;
  aux = Pesquisa(item.get_ID_MSG());
  if (!aux.Vazio()) cout << "Erro: Item já está presente";
  pos = Hash(item.get_ID_MSG());
  Tabela[pos].Insere(item);
};
void Hash_AB::Remove(int chave) {
  int pos;
  pos = Hash(chave);
  Tabela[pos].Remove(chave);
};
