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
  email Pesquisa(int chave);
  void Remove(int chave);
  void Limpa();

 private:
  void InsereRecursivo(No*& p, email item);
  void ApagaRecursivo(No* p);
  email PesquisaRecursivo(No* p, int chave);
  void RemoveRecursivo(No*& p, int chave);
  void Antecessor(No* q, No*& r);
  void PorNivel();

  No* raiz;
};