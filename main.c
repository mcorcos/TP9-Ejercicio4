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
#include "recursive.h"

#define IS_LETTER(i)    ((i)>='a' && (i)<='z'||(i)>='A'&& (i)<='Z')
#define CANT    50
/*
 * 
 */
int main (void)
{
    char string[CANT];
    char *str,*origen,*final;
    str=string;
    int cntinue=1,i;
    while(cntinue){
        
        printf("Ingrese un String: \n");
        origen= str;
        final= get_str(char * str);
        str_check(origen,final);
        printf("Si desea salir presione Q ,de lo contrario ingrese cualquier tecla\n");
        i=getchar();
        if((i=='q')||(i=='Q')) {
            cntinue=0;
        }   
    }
    return (EXIT_SUCCESS);
    
}

void str_check (char * origen,char * final){
    if (origen == final){
        printf("Es palindromo\n");
    }
    
    else if (*origen == *final){
        str_check((origen+1),(final-1));
    }
    else {
        printf("No es palindromo\n");
    }
}

char* get_str (char * str){
    char pull_char;
    int i;
    i=0;     
    pull_char=getchar();
    while ( i<CANT && IS_LETTER(pull_char) && pull_char!='\n'){
        *str[i]=pull_char;
        i++;
    }
    return str[i];
}