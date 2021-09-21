/*

2012160 - Joao Victor Cesa Andrade 

Implementar uma lista encadeada simples, com operações de inserção e remoção no início, meio e fim da fila, além de busca de elementos.

A lista deve armazenar valores referentes ao pagamento de uma conta, com dia, mês e ano do vencimento, valor (double) e situação do pagamento (true para pago,  false para não pago).*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Conta{

  int dia;
  int mes;
  int ano;
  double valor;
  bool pagamento;
  
  struct Conta *nextInLine;
  
};


void inserirNoInicio(struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento);
void inserirNoMeio(int pos, struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento);
void inserirNoFinal(struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento);
void printList(struct Conta *contaNova);
int tamanhoLista(struct Conta *contaNova);
void removerPrimeiro(struct Conta** Inicio);
void removerUltimo(struct Conta** Inicio);
void removerMeio(struct Conta* Inicio, int pos);


struct Conta *criarNovaConta(int dia, int mes, int ano, double valor, bool pagamento){
  
  struct Conta *contaNova = NULL;
  contaNova = (struct Conta *) malloc(sizeof(struct Conta));
  contaNova->dia = dia;
  contaNova->mes = mes;
  contaNova->ano = ano;
  contaNova->valor = valor;
  contaNova->pagamento = pagamento;
  contaNova->nextInLine = NULL;
  
  return contaNova;
}

int main(){
  
  struct Conta *Lista = NULL;
  
  inserirNoInicio(&Lista,01,01,2003,100.0,false);
  inserirNoInicio(&Lista,04,04,2005,150.0,true);
  inserirNoFinal(&Lista,02,02,2004,100.0,false);
  inserirNoFinal(&Lista,77,02,2004,100.0,false);
  printList(Lista);
  printf("\n------------------------------\n");
  inserirNoMeio(1,&Lista,3,3,2004,100.0,true);
  inserirNoMeio(3,&Lista,78,45,2077,100.0,true);
  inserirNoMeio(2,&Lista,16,3,2010,120.0,true);
  printList(Lista);
  printf("\n------------------------------\n");
  removerPrimeiro(&Lista);
  printList(Lista);
  printf("\n------------------------------\n");
  removerUltimo(&Lista);
  printList(Lista);
  printf("\n------------------------------\n");
  removerMeio(Lista,4);
  printList(Lista);
  printf("\n------------------------------\n");
  
  return 0;
}

//INICIO
void inserirNoInicio(struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento){
  
  struct Conta *contaNova = NULL;
  contaNova = (struct Conta *) malloc(sizeof(struct Conta));
  contaNova->dia = dia;
  contaNova->mes = mes;
  contaNova->ano = ano;
  contaNova->valor = valor;
  contaNova->pagamento = pagamento;
  
  contaNova->nextInLine = *Inicio;
  *Inicio = contaNova;  

}

//FINAL
void inserirNoFinal(struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento){
   
  struct Conta *contaNova = NULL;
  contaNova = (struct Conta *) malloc(sizeof(struct Conta));
  contaNova->dia = dia;
  contaNova->mes = mes;
  contaNova->ano = ano;
  contaNova->valor = valor;
  contaNova->pagamento = pagamento;
  
  contaNova->nextInLine = NULL;
  
  if(*Inicio == NULL){
   *Inicio = contaNova;
   return;
  }
  
  struct Conta *temp = *Inicio;
  while(temp->nextInLine != NULL)
   temp = temp->nextInLine;
   
   
  temp->nextInLine = contaNova;
}

//MEIO
void inserirNoMeio(int pos, struct Conta** Inicio,int dia, int mes, int ano, double valor, bool pagamento){
  int tamanho = tamanhoLista(*Inicio);
  
  if(pos < 1 || tamanho < pos ){
   printf("Nao eh possivel inserir na posicao determinada");
  }
  else{
  
  struct Conta *temp = *Inicio; 
  struct Conta *contaNova = (struct Conta *) malloc(sizeof(struct Conta));;
  contaNova->dia = dia;
  contaNova->mes = mes;
  contaNova->ano = ano;
  contaNova->valor = valor;
  contaNova->pagamento = pagamento;
  
  contaNova->nextInLine = NULL;
  
  while(--pos){
    temp = temp->nextInLine;
   }
   
  contaNova->nextInLine = temp->nextInLine;
  temp->nextInLine = contaNova;
   
   
  }
}

//PRINT DO CONTEUDO DA LISTA
void printList(struct Conta *contaNova){
 while(contaNova != NULL){
 printf("Dia -> %d,\n Mes -> %d,\nAno -> %d,\nValor -> %f,\nCondicao -> %d\n", contaNova->dia,contaNova->mes,contaNova->ano,contaNova->valor, contaNova->pagamento);
 contaNova = contaNova->nextInLine;
 }
}

//DETERMINAR O TAMANHO DA LISTA	
int tamanhoLista(struct Conta *contaNova){
 int tamanho = 0;
 
 while(contaNova != NULL){
   contaNova = contaNova->nextInLine;
   tamanho++;
 }
 
 return tamanho; 
}

//REMOVER PRIMEIRO ELEMENTO DA LISTA
void removerPrimeiro(struct Conta** Inicio){
  
 if(*Inicio == NULL || Inicio == NULL){
   return;
 }

 struct Conta *temp = *Inicio;
 *Inicio = (*Inicio)->nextInLine;
 
 free(temp);
}

//REMOVER ULTIMO ELEMENTO DA LISTA
void removerUltimo(struct Conta** Inicio){
  
 if(*Inicio == NULL || Inicio == NULL){
   return;
 }
 
 struct Conta *temp;
 struct Conta *ant;
  
 temp = *Inicio;
 ant = temp;
 
 while(temp != NULL && temp->nextInLine != NULL){
  ant = temp;
  temp = temp->nextInLine;
 }
 
 if(ant == temp){
   free(temp);
   *Inicio = NULL;
 }else{
   free(ant->nextInLine);
   ant->nextInLine = NULL;
 }
}

//REMOVER ITEM DO MEIO
void removerMeio(struct Conta* Inicio, int pos){
 
 struct Conta *temp = Inicio;
 struct Conta *temp2;
 int i;
 
 if(pos == 1){
  Inicio = temp->nextInLine;
  free(temp);
  return;
 }

 for(i=0; i < pos - 2;i++){
    temp = temp->nextInLine;
  }
 temp2 = temp->nextInLine;
 temp->nextInLine = temp2->nextInLine;

 free(temp2);
}
