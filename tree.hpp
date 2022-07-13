#include "email.hpp"

class No {
 public:
  No();

 private:
  email item;
  No* esq;
  No* dir;
  friend class ArvoreBinaria;
};

class ArvoreBinaria {
 public:
  ArvoreBinaria();
  ~ArvoreBinaria();
  void Insere(email item);
  void Caminha(int tipo);
  string Pesquisa(int chave);
  string Remove(int chave);
  void Limpa();

 private:
  void InsereRecursivo(No*& p, email item);
  void ApagaRecursivo(No* p);
  string PesquisaRecursivo(No* p, int chave);
  string RemoveRecursivo(No*& p, int chave);
  void Antecessor(No* q, No*& r);

  No* raiz;
};