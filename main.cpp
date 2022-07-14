#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "hash.hpp"

int main() {
  fstream input_file;
  int i = 0, tam_msg = 0, id_user = 0, id_msg = 0;

  stringstream buff;

  string input_name, token, linha, comando, mensagem;

  cin >> input_name;

  input_file.open(input_name, fstream::in);

  if (!input_file.is_open()) {
    cout << "Erro no arquivo de entrada! " << endl;
    return 0;
  }

  getline(input_file, token);

  int m = stoi(token);

  Hash_AB a = Hash_AB(m);

  while (!input_file.eof()) {
    getline(input_file, linha);
    if (input_file.eof()) break;
    buff << linha;
    buff >> comando;
    if (comando == "ENTREGA") {
      buff >> id_user >> id_msg >> tam_msg;
      for (i = 0; i < tam_msg; i++) {
        buff >> token;
        mensagem.append(token);
        if (i < tam_msg - 1) mensagem.append(" ");
      }
      cout << a.Insere(email(id_user, id_msg, mensagem)) << endl;
      mensagem.clear();
      linha.clear();
      buff.clear();
    } else if (comando == "CONSULTA") {
      buff >> id_user >> id_msg;
      cout << a.Pesquisa(id_user, id_msg) << endl;
      linha.clear();
      buff.clear();
    } else if (comando == "APAGA") {
      buff >> id_user >> id_msg;
      cout << a.Remove(id_user, id_msg) << endl;
      linha.clear();
      buff.clear();
    } else {
      cout << "INVALIDO" << endl;
    }
  }

  input_file.close();

  return 0;
}
