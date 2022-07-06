#include <fstream>
#include <iostream>
#include "Processos.h"

Processos *p[6];
bool readFile(ifstream& iFile, string strFile); // Funcao para garantir que o arquivo foi aberto para leitura
void criarProcesso(int i,string ID, int TCPU, int Prioridade);
Processos ordenarProcessos(Processos *p, int valor);
int i;

using namespace std;

int main () {
  
  ifstream File; // Variavel do arquivo 
  bool status; // Variavel status do arquivo 

  string ID,ID2,ID3; // strings para serem usadas no while
  int TCPU,prioDade; // int para ser usada para criar o processo
  
  
  status = readFile(File,"teste.txt"); // Verificando como está o arquivo
  if (!status){
    // Caso o arquivo não possa abrir independente do motivo
    cout << "O arquivo nao pode ser aberto para leitura " << endl;
    cout << "Programa terminado !" << endl;
    return 0;
  }

  else {
    // tudo certo com o arquivo 
    int i = 0;
    while(!File.fail()){
      // preciso do getline para ignorar o espaçamento do ponto e virgula e salvar em uma variavel do tipo string 
      getline(File,ID,';'); 
      getline(File,ID2,';');
      getline(File,ID3,';');

      TCPU = stoi(ID2); // Conversão de variavel
      prioDade = stoi(ID3);

      // Criar o objeto do tipo Processos 
      criarProcesso(i,ID,TCPU,prioDade);
      i+=1;
    }
    ordenarProcessos(*p,6);

    

  }
  
}

bool readFile(ifstream& iFile, string strFile){
  iFile.open(strFile);
  return !(iFile.fail()||!iFile.is_open()||!iFile.good());
  // eu abro o arquivo aqui e testo se ele está bem
}

void criarProcesso(int i, string ID, int TCPU, int Prioridade){
  // criando  objeto dinamicamente
  p[i] = new Processos(ID,TCPU,Prioridade);
}

Processos ordenarProcessos(Processos *p, int valor){
  Processos copy;
  for (int i = 0; i < valor; i++){
    for (int j = 0; i < valor; j++){
        if (p[i].getPrioridadeProcesso() > p[j].getPrioridadeProcesso()){
            copy = p[j];
            p[j] = p[i];
            p[i] = copy; }
    }
  }
  return *p;
}