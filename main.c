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

#define IS_LETTER(i)    (((i)>='a'&&(i)<='z')||((i)>='A'&&(i)<='Z'))
#define IS_CAPITAL(i)   ((i)>='A'&&(i)<='Z')
#define CANT    100

/*
 * 
 */
int main(void) {
    char string[CANT];                  /*creo un arreglo para guardar el string*/
    char *str=&string[0], *origen, *final;
    int cntinue=1, i=0;
    while (cntinue) {

        printf("Ingrese un string (hasta 100 letras): \n");
        origen=str;                     /*el puntero origen apunta al comienzo del arreglo*/
        final=get_str(str, string);     /*llamo a la funcion que define el puntero al final del arreglo*/
        if(origen<final) {
            
            str_check(origen, final);      /*llamo a la funcion que analiza el string*/
            printf("\nPresione enter para continuar, o cualquier letra para salir\n");
           
            i=getchar();                    /*espero a ver si termino o se quiere ingresar un nuevo string*/
           
            if (i != '\n') {                 /*si se presiono enter termino*/
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
    
    if (origen == final || origen == (final+1)) {      /*caso base:cuando los punteros apuntan a una unica letra */
        printf("Es palindromo\n");                     /*o apuntan a letras consecutivas*/
    }
    else if (*origen == *final) {               /*caso recursivo: la letra que apuntan los punteros es la misma*/
        str_check((origen+1), (final-1));
    } 
    else {
        printf("No es palindromo\n");          /*cuando no se cumple se debe terminar*/
    }
}

char * get_str(char * str, char string[CANT]) {
    char pull_char;
    int j=1,i;
    
    for (i=0;j;) {
        
	
	pull_char = getchar();             /*leo el string de a un caracter*/
        if (IS_LETTER(pull_char)) {         /*si es una letra la tengo que guardar*/
            
            if (IS_CAPITAL(pull_char)){
                pull_char+=('a'-'A');       /*si fue mayuscula, la convierto en minuscula*/
            }
            
            string[i] = pull_char;          /*guardo las letras*/
            i++;
        }
	else if( (pull_char=='\n')||(i==CANT) ) {   /*si copie todo el string o ya se completo el rango termino*/
            j=0;
            i-=1;                               /*le resto uno ya que funciona como indice para el puntero del final*/
        }
        
    }
    str=&string[i];
    return str;
}
