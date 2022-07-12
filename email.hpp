#include <iostream>

using namespace std;

class email {
 public:
  email();
  int get_ID_USER();
  void set_ID_USER(int id);
  int get_ID_MSG();
  void set_ID_MSG(int id);
  std::string get_mensagem();
  void set_mensagem(std::string msg);

 private:
  int ID_USER;
  int ID_MSG;
  std::string mensagem;
};
