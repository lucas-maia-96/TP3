#include "tree.hpp"

No::No() {
  this->esq = nullptr;
  this->dir = nullptr;
}

ArvoreBinaria::ArvoreBinaria() { raiz = nullptr; };

ArvoreBinaria::~ArvoreBinaria() { Limpa(); };

void ArvoreBinaria::Insere(email item) { InsereRecursivo(raiz, item); };

email ArvoreBinaria::Pesquisa(int chave) {
  return PesquisaRecursivo(raiz, chave);
};

void ArvoreBinaria::Remove(int chave) { return RemoveRecursivo(raiz, chave); };

void ArvoreBinaria::Limpa() {
  ApagaRecursivo(raiz);
  raiz = nullptr;
};

void ArvoreBinaria::InsereRecursivo(No*& p, email item) {
  if (p == nullptr) {
    p = new No();
    p->item = item;
  } else {
    if (item.get_ID_MSG() < p->item.get_ID_MSG())
      InsereRecursivo(p->esq, item);
    else
      InsereRecursivo(p->dir, item);
  }
};

void ArvoreBinaria::ApagaRecursivo(No* p) {
  if (p != nullptr) {
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
};

email ArvoreBinaria::PesquisaRecursivo(No* p, int chave) {
  email aux;
  if (p == nullptr) {
    cout << "CONSULTA U E: MENSAGEM INEXISTENTE";
  }
  if (chave < p->item.get_ID_MSG())
    return PesquisaRecursivo(p->esq, chave);
  else if (chave > p->item.get_ID_MSG())
    return PesquisaRecursivo(p->dir, chave);
  else
    return p->item;
};

void ArvoreBinaria::RemoveRecursivo(No*& p, int chave) {
  No* aux;
  if (p == nullptr) {
    cout << "Item nao está presente";
  }
  if (chave < p->item.get_ID_MSG())
    return RemoveRecursivo(p->esq, chave);
  else if (chave > p->item.get_ID_MSG())
    return RemoveRecursivo(p->dir, chave);
  else {
    if (p->dir == nullptr) {
      aux = p;
      p = p->esq;
      free(aux);
    } else if (p->esq == nullptr) {
      aux = p;
      p = p->dir;
      free(aux);
    } else
      Antecessor(p, p->esq);
  }
};

void ArvoreBinaria::Antecessor(No* q, No*& r) {
  if (r->dir != nullptr) {
    Antecessor(q, r->dir);
    return;
  }
  q->item = r->item;
  q = r;
  r = r->esq;
  free(q);
};
