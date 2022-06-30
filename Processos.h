#include <iostream>
using namespace std;

class Processos {
private:

    string ID;
    int tempoCPU;
    int prioridadeProcesso;

public:
    Processos(string,int,int);
    virtual ~Processos();

    void setID(string);
    void setTempoCPU(int);
    void setPrioridadeProcesso(int);

    string getID();
    int getTempoCPU();
    int getPrioridadeProcesso();

};

