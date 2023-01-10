#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"
#include "linked_list_int.h"

int main() {

  //array_list_insertion_test(); // Método para leitura de arquivo de entrada
  
  int n = 10;
  srand(time(0));

  printf("N: %d\n", n);
  
  array_list_int* l01 = array_list_create_8();
  array_list_int* l02 = array_list_create_10();
  array_list_int* l03 = array_list_create_10k();
  linked_list_int* l04 = linked_list_create();

  list_create_test(l01, l02, l03, l04, n);
  linked_list_print(l04);
  list_get_test(l01, l02, l03, l04, 0);
  linked_list_print(l04);
  list_get_test(l01, l02, l03, l04, n-1);
  linked_list_print(l04);
  list_insert_at_test(l01, l02, l03, l04, n, 0);
  linked_list_print(l04);
  list_insert_at_test(l01, l02, l03, l04, n, n-1);
  linked_list_print(l04);
  list_remove_from_test(l01, l02, l03, l04, n, 0);
  linked_list_print(l04);
  list_remove_from_test(l01, l02, l03, l04, n, n-1);
  linked_list_print(l04);
  list_find_test(l01, l02, l03, l04, 0); // num = rand()%n;
  linked_list_print(l04);
  list_find_test(l01, l02, l03, l04, n-1);
  linked_list_print(l04);
  list_pop_back_test(l01, l02, l03, l04);
  linked_list_print(l04);
  list_print_status(l01, l02, l03, l04);
  linked_list_print(l04);
  list_destroy_test(l01, l02, l03, l04);
  linked_list_print(l04);
  
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

void list_create_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int n) {
  
  clock_t inicio, fim;
  
  printf("\nlist_create:\n");
  
  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  array_list_populate(l1, n);
  fim = clock();
  tempo(inicio, fim);
  
  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  array_list_populate(l2, n);
  fim = clock();
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  array_list_populate(l3, n);
  fim = clock();
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  linked_list_populate(l4, n);
  fim = clock();
  tempo(inicio, fim);

}

void list_get_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int index) {

  clock_t inicio, fim;
  
  int error, num;

  printf("\nlist_get:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  num = array_list_get(l1, index, &error);
  fim = clock();
  printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  num = array_list_get(l2, index, &error);
  fim = clock();
  printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  num = array_list_get(l3, index, &error);
  fim = clock();
  printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  num = linked_list_get(l4, index, &error);
  fim = clock();
  printf("numero retornado: %d\n", num);
  tempo(inicio, fim);
}

void list_insert_at_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num, int index) {

  clock_t inicio, fim;

  int length;
  //num = rand()%n;
  
  printf("\nlist_insert_at:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  length = array_list_insert_at(l1, index, num);
  fim = clock();
  printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  length = array_list_insert_at(l2, index, num);
  fim = clock();
  printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  length = array_list_insert_at(l3, index, num);
  fim = clock();
  printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  length = linked_list_insert_at(l4, index, num);
  fim = clock();
  printf("numero %d inserido no indice %d\n", num, index);
  tempo(inicio, fim);
}

void list_remove_from_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num, int index) {

  clock_t inicio, fim;

  int length;
  //num = rand()%n;

  printf("\nlist_remove_from:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  length = array_list_remove_from(l1, index);
  fim = clock();
  printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  length = array_list_remove_from(l2, index);
  fim = clock();
  printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  length = array_list_remove_from(l3, index);
  fim = clock();
  printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  length = linked_list_remove_from(l4, index);
  fim = clock();
  printf("numero removido em: %d\n", index);
  tempo(inicio, fim);

}

void list_pop_back_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;

  int length;
  
  printf("\nlist_pop_back:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  length = array_list_pop_back(l1);
  fim = clock();
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  length = array_list_pop_back(l2);
  fim = clock();
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  length = array_list_pop_back(l3);
  fim = clock();
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  length = linked_list_pop_back(l4);
  fim = clock();
  tempo(inicio, fim);
}

void list_find_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num) {

  clock_t inicio, fim;

  int index, length;

  printf("\nlist_find:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  index = array_list_find(l1, num);
  fim = clock();
  printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  index = array_list_find(l2, num);
  fim = clock();
  printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  index = array_list_find(l3, num);
  fim = clock();
  printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  index = linked_list_find(l4, num);
  fim = clock();
  printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);
}

void list_print_status(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;

  printf("\nlist_print_status:\n");
  
  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  array_list_print_status(l1);
  fim = clock();
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  array_list_print_status(l2);
  fim = clock();
  tempo(inicio, fim);
  
  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  array_list_print_status(l3);
  fim = clock();
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  linked_list_print_status(l4);
  fim = clock();
  tempo(inicio, fim);
}

void list_destroy_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;
  
  printf("\narray_list_destroy:\n");

  printf("l01: array começa com 8 e dobra memória.\n");
  inicio = clock();
  array_list_destroy(l1);
  fim = clock();
  tempo(inicio, fim);

  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  inicio = clock();
  array_list_destroy(l2);
  fim = clock();
  tempo(inicio, fim);

  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  inicio = clock();
  array_list_destroy(l3);
  fim = clock();
  tempo(inicio, fim);

  printf("l04: lista duplamente ligada.\n");
  inicio = clock();
  linked_list_destroy(l4);
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