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

#define IS_LETTER(i)    ((i)>='a'&&(i)<='z'||(i)>='A'&&(i)<='Z')
#define IS_CAPITAL(i)   ((i)>='A'&&(i)<='Z')
#define CANT    50

/*
 * 
 */
int main(void) {
    char string[CANT];
    char *str=&string[0], *origen, *final;
    int cntinue=1, i=0;
    while (cntinue) {

        printf("Ingrese un string: \n");
        origen=str;
        final=get_str(str, string);
        if(origen<final) {
            str_check(origen, final);
            printf("\nPresione enter para continuar, o Q para salir\n");
            i=getchar();
            if ((i == 'q') || (i == 'Q')) {
                cntinue = 0;  
            }
        }
        else{
            printf("string no valido,intentelo nuevamente\n");
        }
    }
    return (EXIT_SUCCESS);

}

void str_check(char * origen, char * final) {
    
    if (origen == final || origen == (final+1)) {
        printf("Es palindromo\n");
    }
    else if (*origen == *final) {
        str_check((origen+1), (final-1));
    } 
    else {
        printf("No es palindromo\n");
    }
}

char * get_str(char * str, char string[CANT]) {
    char pull_char;
    int j,i;
    
    for (i=0;j;) {
        pull_char = getchar();
        if( (pull_char=='\n')||(i==CANT) ) {
            j=0;
            i-=1;
        }
        else if (IS_LETTER(pull_char)) {
            
            if (IS_CAPITAL(pull_char)){
                pull_char+=('a'-'A');
            }
            
            string[i] = pull_char;
            i++;
        }
    }
    str=&string[i];
    return str;
}