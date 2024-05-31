#include "mkl25z4.h"
#include "actdeco.h"
#include <ctype.h>
const uint8_t pines[7] = {1,2,3,4,5,6,7,8};

int display [14][8]={
    {1,1,1,1,1,1,0},       //0
    {0,1,1,0,0,0,0},       //1
    {1,1,0,1,1,0,1},       //2
    {1,1,1,1,0,0,1},       //3
    {0,1,1,0,0,1,1},       //4
    {1,0,1,1,0,1,1},       //5
    {1,0,1,1,1,1,1},       //6
    {1,1,1,0,0,0,0},       //7
    {1,1,1,1,1,1,1},       //8
    {1,1,1,0,0,1,1},       //9
    {1,1,1,0,1,1,1},       //A
    {0,0,1,1,1,1,1},       //B
    {1,0,0,1,1,1,0},       //C
    {0,1,1,1,1,0,1},       //D    
};

void deco7seg(char Num){
   char num = tolower(Num);
    for(int i = 0; i < 8;i++){
        PORTA -> PCR [i] |= PORT_PCR_MUX(1);
    }
    switch (num){
        
    case '0':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[0][i]<<pines[i]);
       } 
        break;   

    case '1':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[1][i]<<pines[i]);
       } 
        break;
            
    case '2':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[2][i]<<pines[i]);
       } 
        break;
            
    case '3':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[3][i]<<pines[i]);
       } 
        break;
            
    case '4':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[4][i]<<pines[i]);
       } 
        break;
            
    case '5':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[5][i]<<pines[i]);
       } 
        break;
            
    case '6':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[6][i]<<pines[i]);
       } 
        break;
            
    case '7':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[7][i]<<pines[i]);
       } 
        break;
            
    case '8':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[8][i]<<pines[i]);
       } 
        break;
            
    case '9':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[9][i]<<pines[i]);
       } 
        break;

    case 'a':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[10][i]<<pines[i]);
       } 
        break;

    case 'b':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[11][i]<<pines[i]);
       } 
        break;

    case 'c':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[12][i]<<pines[i]);
       } 
        break;

    case 'd':
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(display[13][i]<<pines[i]);
       } 
        break;    
    default:
        for(int i = 0; i < 8; i++){
    PTE->PSOR|=(0<<pines[i]);
        break;
    }
}
}
