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
#include "template.h"

//struct
typedef struct {
  char cargo[80];
  int numCand;
  char nomeCand[80];
  char partido[80];
  int qtd_votos;
} candidato;
typedef candidato elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES ------*/
const elemento VL_NULO = {"", 0, "", "", 0};
#include "tad_lst2.h"

/*definição da lista- ----------------------*/
tipo_lista lista;

/*PROTÓTIPO DAS FUNÇÕES --------------------*/
void monta_tela();
char escolhe_opcao(); 
int posicao_para_alterar(int tam);
int posicao_para_incluir(int tam);
int posicao_para_excluir(int tam);
int entra_nomeCand(char *nomeCand);
int entra_numCand(int *numCand);
int entra_partido(char *partido);
int entra_cargo(char *cargo);
int entra_qtdVotos(int *qtd_votos);
void incluir();
void listar();
void alterar();
void excluir();
int carregar_lista(tipo_lista *lista);
int gravar_lista(tipo_lista lista);
void lerArquivo();
void gravarArquivo();
int votar_lista(tipo_lista lista);
void votar();

//######### MAIN ######################
int main() {
  char opcao;
  inicializa_lista(&lista);
  do {
    limpa_tela();
    limpatela();
    monta_tela();
    opcao = escolhe_opcao();
    switch (opcao) {
    case '1':
      lerArquivo();
      break;
    case '2':
      listar();
      break;
    case '3':
      incluir();
      break;
    case '4':
      alterar();
      break;
    case '5':
      excluir();
      break;
    case '6':
      votar();
      break;
    case '9':
      gravarArquivo();
      break;
    case '0':
      exit(1);
    }
  } while (1);
}


//#########  FUNÇÕES  ############
void monta_tela() {
  limpatela();
  printf("\n\n\n---- URNA ELETRÔNICA ----\n");
  printf("\n1 - ler arquivo");
  printf("\n2 - lista de candidatos com quantidade de votos");
  printf("\n3 - Cadastrar candidatos");
  printf("\n4 - Editar dados do candidatos");
  printf("\n5 - Excluir candidato");
  printf("\n6 - Votar");
  printf("\n9 - Gravar os dados");
  printf("\n10 - INVERTER A LISTA\n");
  printf("\n0 - Sair\n");
}

char escolhe_opcao() { 
  printf("\nDigite a opção desejada: ");
  return getchar(); }

int posicao_para_alterar(int tam) {
  int pos;
  if (tam > 0) {
    do {
      printf("\nEm qual posicao vc deseja alterar");
      scanf("%d", &pos);
    } while ((pos < 0) || (pos > lista.tamanho + 1));
    return pos;
  } else
    return 1;
}

int posicao_para_incluir(int tam) {
  int pos;
  if (tam > 0) {
    do {
      printf("\nEm qual posicao vc deseja incluir");
      scanf("%d", &pos);
    } while ((pos < 0) || (pos > lista.tamanho + 1));
    return pos;
  } else
    return 1;
}

int posicao_para_excluir(int tam) {
  int pos;
  if (tam > 0) {
    do {
      printf("\nEm qual posicao vc deseja excluir");
      scanf("%d", &pos);
    } while ((pos < 0) || (pos > lista.tamanho + 1));
    return pos;
  } else
    return 1;
}

limpa_tela() { system("clear"); }

int entra_nomeCand(char *nomeCand) {
  printf("\nDigite o nome do candidato? ");
  fflush(stdin);
  scanf("%s", nomeCand);
}

int entra_numCand(int *numCand) {
  printf("\nDigite o numero do candidato? ");
  fflush(stdin);
  scanf("%d", numCand);
}

int entra_partido(char *partido) {
  printf("\nDigite o partido do candidato? ");
  fflush(stdin);
  scanf("%s", partido);
}

int entra_cargo(char *cargo) {
  printf("\nDigite o cargo do candidato? ");
  fflush(stdin);
  scanf("%s", cargo);
}

int entra_qtdVotos(int *qtd_votos) {
  printf("\nDigite em qual candidato deseja votar: ");
  fflush(stdin);
  scanf("%d", qtd_votos);
}

void incluir() {
  int pos, i;
  elemento elem = VL_NULO;
  limpa_tela();
  entra_nomeCand(&elem.nomeCand[i]);
  entra_numCand(&elem.numCand);
  entra_partido(&elem.partido[i]);
  entra_cargo(&elem.cargo[i]);
  pos = (tamanho(lista) + 1);
  limpatela();
  incluir_elemento(&lista, pos, elem);
  printf("elemento incluido com sucesso!");
  getchar();
}

void listar() {
  int i, j, tam;
  elemento elem;
  limpa_tela();
  printf("\nEXIBINDO A LISTA DE CANDIDATOS:\n");
  tam = tamanho(lista);
  if (tam > 0) {
    for (i = 1; i <= tam; i++) {
      if (obter_elemento(lista, i, &elem))
        printf("\n%d - %s - %d - %s - %s - -> %d VOTOS RECEBIDOS ", i,
               elem.nomeCand, elem.numCand, elem.partido, elem.cargo,
               elem.qtd_votos);
    }
    printf("\n\n\n* FIM DA LISTA *\n");
  } else
    printf("Lista vazia");
  getchar();
  getchar();
}

void alterar() {
  int pos, i;
  elemento elem = VL_NULO;
  limpa_tela();
  listar();
  pos = posicao_para_alterar(tamanho(lista));

  entra_nomeCand(&elem.nomeCand[i]);
  entra_numCand(&elem.numCand);
  entra_partido(&elem.partido[i]);
  entra_cargo(&elem.cargo[i]);

  if (alterar_elemento(&lista, pos, elem))
    printf("Elemento alterado com sucesso!");
  getchar();
}

void excluir() {
  int pos;
  elemento elem = VL_NULO;
  limpa_tela();
  listar();
  pos = posicao_para_excluir(tamanho(lista));
  if (excluir_elemento(&lista, pos))
    printf("Elemento incluído com sucesso!");
  getchar();
}

//----SALVAR DADOS-------
int carregar_lista(tipo_lista *lista) {
  FILE *arquivo;
  elemento e;
  int i = 0;
  arquivo = fopen("dados.dat", "rb");
  if (arquivo != NULL) {
    while (fread(&e, sizeof(elemento), 1, arquivo)) {
      incluir_elemento(lista, ++i, e);
    }
    fclose(arquivo);
    return 1;
  } else
    return 0;
}

int gravar_lista(tipo_lista lista) {
  FILE *arquivo;
  elemento e;
  arquivo = fopen("dados.dat", "wb");
  for (int i = 1; i <= tamanho(lista); i++) {
    obter_elemento(lista, i, &e);
    fwrite(&e, sizeof(elemento), 1, arquivo);
  }
  fclose(arquivo);
}

void lerArquivo() { 
  carregar_lista(&lista); 
  limpa_tela();
  printf("Lista carregada com sucesso!");
  getchar();
  }

void gravarArquivo() { gravar_lista(lista); }

int votar_lista(tipo_lista lista) {

  int num, i, tam;
  elemento elem;
  tam = tamanho(lista);
  printf("Digite o numero do voto:");
  scanf("%d", &num);
  for (i = 0; i <= tam; i++) {
    obter_elemento(lista, i, &elem);
    if (elem.numCand == num) {
      elem.qtd_votos++;
      if(alterar_elemento(&lista, i, elem)){
      }
      break;
    }
  }
  printf("votação realizada com sucesso!!!! ");
  getchar();
  getchar();
  }

void votar() {
  votar_lista(lista);
}