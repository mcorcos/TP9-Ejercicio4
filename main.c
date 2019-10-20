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

#define IS_LETTER(i)    (((i)>='a'&&(i)<='z')||((i)>='A'&&(i)<='Z'))  /*Verifica(devuelve 1) si un caracter es letra*/
#define IS_CAPITAL(i)   ((i)>='A'&&(i)<='Z')  /*Verifica si un caracter es una letra mayuscula*/
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
        final=get_str(string);     /*llamo a la funcion que define el puntero al final del arreglo*/
        
        if(origen<=final) {           /*si el puntero no fue  valido no ingresa*/
            
            str_check(origen, final);      /*llamo a la funcion que analiza el string*/
            printf("\nPresione enter para continuar, o cualquier letra para salir\n");
           
            i=getchar();                    /*espero a ver si termino o se quiere ingresar un nuevo string*/
           
            if (i != '\n') {                 /*si no se presiono enter termino*/
                cntinue = 0;  
            }
            
        }
        else{
            printf("\nString invalido\n");
            cntinue=0;                             /*si se ingreso un string invalido (vacio o excedido de letras) termino el programa*/
        }
    }
    return (EXIT_SUCCESS);

}

void str_check(char * origen, char * final) {
    
    if ((origen >= final) || (*origen != *final) ) {      /*caso base:cuando los punteros recorren se encuentran o pasan (ya se analizo todo el string) */
                                                          /*o apuntan a letras distintas*/
        if( origen >= final ){
            
            printf("Es palindromo\n");                  /* si se recorrio todo el string es palindromo*/
        }
        else {
            printf("No es palindromo\n");               /*sino es porque alguna letra no coincidia por lo tanto no es palindromo*/
        }
    }
    else {               /*caso recursivo: la letra que apuntan los punteros es la misma*/
        str_check((origen+1), (final-1));
    } 
    
}

char * get_str(char string[CANT]) {
    char pull_char, *str ;
    int j=1,i;
    
    for (i=0;j;) {
        
	
	pull_char = getchar();             /*leo el string de a un caracter*/
        
      if( (pull_char=='\n')||(i==CANT) ) {   /*si copie todo el string o ya se completo el rango termino*/
            
            j=0;
            i-=1;                               /*le resto uno ya que funciona como indice para el puntero del final*/
       
            if((i==CANT-1) && (pull_char != '\n')){          /* si ya hay 100 letras y la siguiente no es un enter se considera invalido*/
			printf("\n CANTIDAD DE LETRAS EXCEDIDAS \n");
			i=-1;                                  /*defino asi para devolver un puntero menor a origen*/
		}
      }
        
       else if (IS_LETTER(pull_char)) {         /*si es una letra la tengo que guardar*/
            
            if (IS_CAPITAL(pull_char)){
                pull_char+=('a'-'A');       /*si fue mayuscula, la convierto en minuscula*/
            }
            
            string[i] = pull_char;          /*guardo las letras*/
            i++;
        }
	
        
    }
    str=&string[i];                     /*devuelvo el puntero final*/
    return str;
}
