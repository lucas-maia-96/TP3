#include "email.hpp"

email::email() {
  ID_USER = 0;
  ID_MSG = 0;
  mensagem = "";
}

int email::get_ID_USER() { return this->ID_USER; }

void email::set_ID_USER(int id) { this->ID_USER = id; }

int email::get_ID_MSG() { return this->ID_MSG; }

void email::set_ID_MSG(int id) { this->ID_MSG = id; }

string email::get_mensagem() { return this->mensagem; }

void email::set_mensagem(std::string msg) { this->mensagem = msg; }
