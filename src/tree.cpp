#include "tree.hpp"

No::No() {
  this->esq = nullptr;
  this->dir = nullptr;
}

ArvoreBinaria::ArvoreBinaria() { raiz = nullptr; };

ArvoreBinaria::~ArvoreBinaria() { Limpa(); };

void ArvoreBinaria::Insere(email item) { InsereRecursivo(raiz, item); };

string ArvoreBinaria::Pesquisa(int id_user, int id_msg) {
  return PesquisaRecursivo(raiz, id_user, id_msg);
};

string ArvoreBinaria::Remove(int chave) {
  return RemoveRecursivo(raiz, chave);
};

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

string ArvoreBinaria::PesquisaRecursivo(No* p, int id_user, int id_msg) {
  email aux;
  if (p == nullptr) {
    return "MENSAGEM INEXISTENTE";
  }
  if (id_msg < p->item.get_ID_MSG())
    return PesquisaRecursivo(p->esq, id_user, id_msg);
  else if (id_msg > p->item.get_ID_MSG())
    return PesquisaRecursivo(p->dir, id_user, id_msg);
  else if (p->item.get_ID_USER() == id_user)
    return p->item.get_mensagem();
  else
    return "MENSAGEM INEXISTENTE";
};

string ArvoreBinaria::RemoveRecursivo(No*& p, int chave) {
  No* aux;
  if (p == nullptr) {
    return "ERRO: MENSAGEM INEXISTENTE";
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
      return "OK: MENSAGEM APAGADA";
    } else if (p->esq == nullptr) {
      aux = p;
      p = p->dir;
      free(aux);
      return "OK: MENSAGEM APAGADA";
    } else {
      Antecessor(p, p->esq);
      return "OK: MENSAGEM APAGADA";
    }
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
