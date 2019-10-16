/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mcorcos
 *
 * Created on 16 de octubre de 2019, 19:06
 */

#include <stdio.h>
#include <stdlib.h>
#include "str_check.h"
/*
 * 
 */
int main (void){
    int cntinue=1;
    while(cntinue){
        
        printf("Ingrese un String: \n");
        get_str()
        str_check(origen,final);
        printf("Desea continuar? [y/n]:");
        cntinue=wanna_follow();
        
    }
    return (EXIT_SUCCESS);
    
}

void str_check (char * origen,char * final){
    
    if (origen == final){
        printf("Es palindromo\n");
    }
    
    else if (*origen == *final){
        str_check((origen+1),(final-1))
    }
    else {
        printf("No es palindromo\n")
    }
    
}

int wanna_follow (void) {
    
    int a;
    a=getchar();
    if (a=='y'||a=="Y"){
        return 1;
    }
    else{
        return 0;
    }
}