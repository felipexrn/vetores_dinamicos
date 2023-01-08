#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"
#include "linked_list_int.h"

int main() {

  //array_list_insertion_test(); // Método para leitura de arquivos de entrada
  
  int n = 10000000;

  printf("N: %d\n", n);
  array_list_int* l01 = array_list_create_8();
  array_list_int* l02 = array_list_create_10();
  array_list_int* l03 = array_list_create_10k();
  linked_list_int* l04 = linked_list_create();

  printf("\n\nl01: array começa com 8 e dobra memória.\n");
  array_list_test(l01, n);
  printf("\n\nl02: array começa com 10 e aumenta memória de 10 em 10.\n");
  array_list_test(l02, n);
  printf("\n\nl03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  array_list_test(l03, n);
  printf("\n\nl04: lista duplamente ligada.\n");
  linked_list_test(l04, n);
  
  return 0;
}

void array_list_populate(array_list_int* list, int n) {
  for (int i = 0; i < n; i++) {
    array_list_push_back(list, i);
  }
}

void linked_list_populate(linked_list_int* list, int n) {
  for (int i = 0; i < n; i++) {
    linked_list_push_back(list, i);
  }
}

void array_list_print_status(array_list_int* list) {
  printf("array_list_status:\n  size: %d\n  capacity: %d\n  occupied: %.1f\n\n", array_list_size(list), array_list_capacity(list), array_list_percent_occupied(list));
}

void linked_list_print_status(linked_list_int* list) {
  printf("linked_list_status:\n  size: %d\n  occupied: %.1f\n\n", linked_list_size(list), linked_list_percent_occupied(list));
}
void tempo(clock_t i, clock_t f) {
  printf("Tempo: %.3lf ms\n\n", (f-i)/(CLOCKS_PER_SEC/1000.0));
} 

void array_list_test(array_list_int* list, int n) {
  
  clock_t inicio, fim;
  
  printf("array_list_create:\n");
  inicio = clock();
  array_list_populate(list, n);
  fim = clock();
  tempo(inicio, fim);
  
  int error, num;

  printf("array_list_get:\n");
  inicio = clock();
  num = array_list_get(list, n-1, &error);
  fim = clock();
  tempo(inicio, fim);
  //printf("numero pesquisado: %d\n", num);  
  
  printf("array_list_insert_at:\n");
  num = 3;
  inicio = clock();
  array_list_insert_at(list, num, 42);
  fim = clock();
  tempo(inicio, fim);
  //printf("numero inserido em: %d\n", num); 

  printf("array_list_remove_from:\n");
  num = 3;
  inicio = clock();
  array_list_remove_from(list, 3);
  fim = clock();
  tempo(inicio, fim);
  //printf("numero removido em: %d\n", num); 
  
  printf("array_list_pop_back:\n");
  inicio = clock();
  num = array_list_pop_back(list);
  fim = clock();
  tempo(inicio, fim);

  printf("array_list_find:\n");
  inicio = clock();
  num = array_list_find(list, n-1);
  fim = clock();
  tempo(inicio, fim);
  //printf("indice do numero procurado: %d\n", num);

  //array_list_print(list);
  array_list_print_status(list);

  printf("array_list_destroy:\n");
  inicio = clock();
  array_list_destroy(list);
  fim = clock();
  tempo(inicio, fim);
}

void linked_list_test(linked_list_int* list, int n) {

  clock_t inicio, fim;

  printf("linked_list_create:\n");
  inicio = clock();
  linked_list_populate(list, n);
  fim = clock();
  tempo(inicio, fim);;
  
  int error, num;

  printf("linked_list_get:\n");
  inicio = clock();
  num = linked_list_get(list, n-1, &error);
  fim = clock();
  tempo(inicio, fim);;
  //printf("numero pesquisado: %d\n", num); 

  printf("linked_list_insert_at:\n");
  num = 3;
  inicio = clock();
  linked_list_insert_at(list, num, 42);
  fim = clock();
  tempo(inicio, fim);
  //printf("numero inserido em: %d\n", num); 

  printf("linked_list_remove_from:\n");
  num = 3;
  inicio = clock();
  linked_list_remove_from(list, 3);
  fim = clock();
  tempo(inicio, fim);
  //printf("numero removido em: %d\n", num); 

  printf("linked_list_pop_back:\n");
  inicio = clock();
  num = linked_list_pop_back(list);
  fim = clock();
  tempo(inicio, fim);

  printf("linked_list_find:\n");
  inicio = clock();
  num = linked_list_find(list, n-1);
  fim = clock();
  tempo(inicio, fim);
  //printf("indice do numero procurado: %d\n", num);

  //linked_list_print(list);
  linked_list_print_status(list);

  printf("linked_list_destroy:\n");
  inicio = clock();
  linked_list_destroy(list);
  fim = clock();
  tempo(inicio, fim);
  
}

/* Mostra valor não inserido e sai do programa.*/
void error_at_insertion(array_list_int *list, int x) {
  printf("\033[0;31mErro:\033[0m:\tValor %d não inserido!\n", x);
  printf("\tA lista possui %d elementos.\n", array_list_size(list));
  exit(1);
}

/* Imprime a lista na saída padrão. */
void print_vector(array_list_int *list) {
  int i, x, erro;
  for (i = 0; i < array_list_size(list); ++i) {
    x = array_list_get(list, i, &erro);
    if (!erro) {
      printf("%d ", x);
    } else {
      printf("ERRO: índice %d não é válido!\n", i);
      exit(2);
    }
  }
  printf("\n");
}

int array_list_insertion_test() {
  time_t inicio, fim;
  int n, i, x;
  array_list_int *l01 = array_list_create_8();
  scanf("%d", &n);
  inicio = time(0);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    /* array_list_push_back retorna o novo tamanho da lista. 
       Se não houve inserção o tamanho não será (i+1). 
       O programa então mostra que não inseriu e termina.
       */
    if (array_list_push_back(l01, x) != (i + 1)) {
      error_at_insertion(l01, x);
    }
  }
  fim = time(0);
  printf("Inserção de %d elementos em %.4lf milissegundos.\n", n,
          (((double)fim - (double)inicio) / CLOCKS_PER_SEC) * 1000);
  printf("Tamanho do vetor: %d\n", array_list_size(l01));
  print_vector(l01);
  return 0;
}