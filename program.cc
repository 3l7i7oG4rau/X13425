#include <iostream>
using namespace std;

#include "CuaIOParInt.hh"

void repartir_cues(queue<ParInt>& p, queue<ParInt>& c1, queue<ParInt>& c2) {
    int temps_p=0;
    int temps_c1=0;
    int temps_c2=0;
    while(not p.empty()){
        ParInt aux = p.front();
        p.pop();
        temps_p += aux.segon();
        if(temps_c2 == temps_c1){
            c1.push(aux);
            temps_c1 += aux.segon();
        }
        else if(temps_c1 < temps_p and temps_c2 < temps_p){
            if(temps_c1 < temps_c2){
                c1.push(aux);
                temps_c1 += aux.segon();
            }
            else{
                c2.push(aux);
                temps_c2 += aux.segon();
            }
        }
    }
}

int main(){
    queue<ParInt> p;
    llegirCuaParInt(p);
    queue<ParInt> c1;
    queue<ParInt> c2;
    repartir_cues(p, c1, c2);
    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);
}