#include <getopt.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "hash.hpp"

int main(int argc, char* const* argv) {
  fstream input_file;
  fstream output_file;

  char c;

  int i = 0, tam_msg = 0, id_user = 0, id_msg = 0;

  stringstream buff;

  string input_name, output_name, token, linha, comando, mensagem;

  while ((c = getopt(argc, argv, "i:o:m:s:")) != EOF) {
    switch (c) {
      case 'i':
      case 'I':
        input_name = optarg;
        break;

      case 'o':
      case 'O':
        output_name = optarg;
        break;

      default:
        break;
    }
  }

  input_file.open(input_name, fstream::in);
  output_file.open(output_name, fstream::out);

  if (!input_file.is_open()) {
    cout << "Erro no arquivo de entrada! " << endl;
    return 0;
  }

  if (!output_file.is_open()) {
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
      output_file << a.Insere(email(id_user, id_msg, mensagem)) << endl;
      mensagem.clear();
      linha.clear();
      buff.clear();
    } else if (comando == "CONSULTA") {
      buff >> id_user >> id_msg;
      output_file << a.Pesquisa(id_user, id_msg) << endl;
      linha.clear();
      buff.clear();
    } else if (comando == "APAGA") {
      buff >> id_user >> id_msg;
      output_file << a.Remove(id_user, id_msg) << endl;
      linha.clear();
      buff.clear();
    } else {
      output_file << "INVALIDO" << endl;
    }
  }

  input_file.close();
  output_file.close();

  return 0;
}
