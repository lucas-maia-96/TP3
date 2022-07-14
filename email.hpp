#include <iostream>

using namespace std;

class email {
 public:
  email();
  email(int id_user, int id_msg, string msg);
  int get_ID_USER();
  void set_ID_USER(int id);
  int get_ID_MSG();
  void set_ID_MSG(int id);
  std::string get_mensagem();
  void set_mensagem(std::string msg);
  bool Vazio();

 private:
  int ID_USER;
  int ID_MSG;
  std::string mensagem;
};
