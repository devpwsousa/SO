#include "Processos.h"

Processos::Processos(string ID, int tempoCPU, int prioridadeProcessos){
    this->ID = ID;
    this->tempoCPU = tempoCPU;
    this->prioridadeProcesso = prioridadeProcessos;
}

Processos::~Processos(){   
    cout << " O processo foi terminado " << endl;
}

string Processos :: getID(){
    return ID;
}

int Processos :: getTempoCPU(){
    return tempoCPU;
}

int Processos :: getPrioridadeProcesso(){
    return prioridadeProcesso;
}

void Processos :: setID(string ID){
    this->ID = ID;
}

void Processos :: setTempoCPU (int tempoCPU){
    this->tempoCPU = tempoCPU;
}

void Processos :: setPrioridadeProcesso (int prioridadeProcesso){
    this->prioridadeProcesso = prioridadeProcesso;
}