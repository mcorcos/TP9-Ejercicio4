/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   str_check.h
 * Author: mcorcos
 *
 * Created on 16 de octubre de 2019, 19:11
 */

#ifndef RECURSIVE_H
#define RECURSIVE_H

void str_check (char * origen, char * final);  /* Funcion recursiva,utilizada  para verificar si un string es palindromo*/
                                               /*Es una funcion que no devuelve nada,y recibe dos punteros:el de inicio del string y del final*/


char* get_str (char string[]); /*Funcion que guarda un string de hasta 100 letras en un arreglo y devuelve un puntero al ultimo elemento*/
                                            /*La funcion recibe un puntero al comienzo del arreglo y devuelve un puntero al final*/
#endif /* RECURSIVE_H */

