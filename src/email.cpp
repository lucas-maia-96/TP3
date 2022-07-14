#include "email.hpp"

email::email() {
  ID_USER = 0;
  ID_MSG = 0;
  mensagem = "";
}

email::email(int id_user, int id_msg, string msg) {
  ID_USER = id_user;
  ID_MSG = id_msg;
  mensagem = msg;
}

int email::get_ID_USER() { return this->ID_USER; }

void email::set_ID_USER(int id) { this->ID_USER = id; }

int email::get_ID_MSG() { return this->ID_MSG; }

void email::set_ID_MSG(int id) { this->ID_MSG = id; }

string email::get_mensagem() { return this->mensagem; }

void email::set_mensagem(std::string msg) { this->mensagem = msg; }

bool email::Vazio() { return this->get_ID_MSG() == 0; };