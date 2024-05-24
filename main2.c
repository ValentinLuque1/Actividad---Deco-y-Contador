#include "mkl25z4.h"
int bcd1[4] = {1,2,3,4};
int bcd2[4] = {5,6,7,8};
int puls = 10;
int display [10][4]={
    {0,0,0,0}, //0
    {0,0,0,1}, //1
    {0,0,1,0}, //2
    {0,0,1,1}, //3
    {0,1,0,0}, //4
    {0,1,0,1}, //5
    {0,1,1,0}, //6
    {0,1,1,1}, //7
    {1,0,0,0}, //8
    {1,0,0,1}, //9
};

int main(){

SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
PORTA -> PCR [puls]|=PORT_PCR_MUX(0);


for(int i = 0; i < 4 ; i++){
PORTA -> PCR [bcd1[i]]|=PORT_PCR_MUX(1);
PORTA -> PCR [bcd2[i]]|=PORT_PCR_MUX(1);

}


int contD=0;

while(1){
int estPuls = PTA -> PDIR & (1u << puls);
    while(estPuls == 1){
for(int i = 0 ; i < 10 ; i++ ){ //cont y -> estados de salidas
    for(int j = 0 ; j < 4 ; j++ ){ // cont x -> pines
        PTA->PSOR|=(display[i][j]<< bcd1[j] );       
    }
    if(i==9){
        for (int j = 0; j < 4; j++)
        {
     PTA->PSOR|=(display[j][contD]<<bcd1[j]);
        }
        
        contD++;
        i=0;       
    }
}
} while(estPuls != 1){
for(int i = 9 ; i >= 0 ; i-- ){ //cont y -> estados de salidas
    for(int j = 0 ; j < 4 ; j++ ){ // cont x -> pines
        PTA->PSOR|=(display[j][i]<<bcd2[j]);       
    }
    if(i==0){
         for (int j = 0 ; j < 4 ; j++) 
        {
     PTA->PSOR|=(display[j][contD]<<bcd2[j]);
        }
        
        contD--;
        i=9;       
    }
}

}
}
}