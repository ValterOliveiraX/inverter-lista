/***********
+------------------------------------------+
| INSTITUTO FEDERAL DE CIÊNCIA             |
|E TECNOLOGIA DO MARANHÃO                  |
| SISTEMAS DE INFORMAÇÃO -                 |
| ALGORITMOS E ESTRUTUTURAS DE DADOS I     |
| Professor Gentil Cutrim                  | 
| Acadêmico: Pedro Lemos & Valter Oliveira |  
+------------------------------------------+
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 #include <locale.h>
//idioma
 // setlocale(LC_ALL, "");
//facilitadores de função 

void limpatela() { system("cls || clear"); }
void pausa() { getchar(); }
int sorteio(int i) { return rand() % i; }

