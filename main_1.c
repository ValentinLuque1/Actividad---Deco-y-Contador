#include "mkl25z4.h"
#include "TeclaM.h"
#include "actdeco.h"

int main(){

SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;

}

while(1){
    char tecla = ObtenerTecla('a');
    deco7seg(tecla);
}
