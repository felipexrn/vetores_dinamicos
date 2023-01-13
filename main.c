// para efetuar cada teste retire o comentário da função desejada

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"
#include "linked_list_int.h"

int main() {
  
  int m = 17000000, n = 1, p = 2;
  srand(time(0));

  printf("l01: array começa com 8 e dobra memória.\n");
  printf("l02: array começa com 10 e aumenta memória de 10 em 10.\n");
  printf("l03: array começa com 10k e aumenta memória de 10k em 10k.\n");
  printf("l04: lista duplamente ligada.\n\n");

  printf("N: de %d a %d\n\n", n, m);

  
  while (n < m) {
    
    array_list_int* l01 = array_list_create_8();
    array_list_int* l02 = array_list_create_10();
    array_list_int* l03 = array_list_create_10k();
    linked_list_int* l04 = linked_list_create();
    
    // em casos de testes envolvendo push back, comente as próximas 4 linhas
    array_list_populate(l01, n);
    array_list_populate(l02, n);
    array_list_populate(l03, n);
    linked_list_populate(l04, n);
    
    //push_back_test(l01, l02, l03, l04, n); // feito
    //get_test(l01, l02, l03, l04, rand()%n); // feito
    //insert_at_test(l01, l02, l03, l04, rand()%n, rand()%n); // feito
    //remove_from_test(l01, l02, l03, l04, rand()%n, rand()%n); // feito
    //find_test(l01, l02, l03, l04, rand()%n); // feito
    //pop_back_test(l01, l02, l03, l04); // feito
    //status_test(l01, l02, l03, l04); // feito
    ///destroy_test(l01, l02, l03, l04); // feito
    //find_and_remove_from_test(l01, l02, l03, l04, rand()%n); // feito
    //push_back_find_and_remove_from_test(l01, l02, l03, l04, n, rand()%n); // feito
    //print_list(l01, l02, l03, l04); // execute com valores de N abaixo de 100, vai por mim
    
    // em caso de testes envolvendo destroy comente as próximas 4 linhas
    array_list_destroy(l01);
    array_list_destroy(l02);
    array_list_destroy(l03);
    linked_list_destroy(l04);
    
    n *= p;
  }
  
    return 0;
}

void array_list_populate(array_list_int* list, int n) {
  for (int i = 0; i < n; i++) {
    array_list_push_back(list, rand()%n);
  }
}

void linked_list_populate(linked_list_int* list, int n) {
  for (int i = 0; i < n; i++) {
    linked_list_push_back(list, rand()%n);
  }
}

void array_list_print_status(array_list_int* list) {
  printf("\narray_list_status:\n\tsize: %d\n\tcapacity: %d\n\toccupied: %.1f\n\n", array_list_size(list), array_list_capacity(list), array_list_percent_occupied(list));
}

void linked_list_print_status(linked_list_int* list) {
  printf("\nlinked_list_status:\n  size: %d\n  occupied: %.1f\n\n", linked_list_size(list), linked_list_percent_occupied(list));
}

void tempo(clock_t i, clock_t f) {
  //printf("Tempo: %.3lf ms\n", (f-i)/(CLOCKS_PER_SEC/1000.0));
  printf("%.3lf\t", (f-i)/(CLOCKS_PER_SEC/1000.0));
} 

void push_back_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int n) {
  
  clock_t inicio, fim;
  
  //printf("list_create:\n");
  
  //printf("l01: ");
  inicio = clock();
  array_list_populate(l1, n);
  fim = clock();
  tempo(inicio, fim);
  
  //printf("l02: ");
  inicio = clock();
  array_list_populate(l2, n);
  fim = clock();
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  array_list_populate(l3, n);
  fim = clock();
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  linked_list_populate(l4, n);
  fim = clock();
  tempo(inicio, fim);

  printf("\n");

}

void get_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int index) {

  clock_t inicio, fim;
  
  int error, num;

  //printf("list_get:\n");

  //printf("l01: ");
  inicio = clock();
  num = array_list_get(l1, index, &error);
  fim = clock();
  //printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  num = array_list_get(l2, index, &error);
  fim = clock();
  //printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  num = array_list_get(l3, index, &error);
  fim = clock();
  //printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  num = linked_list_get(l4, index, &error);
  fim = clock();
  //printf("numero retornado: %d\n", num);
  tempo(inicio, fim);

  printf("\n");
}

void insert_at_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num, int index) {

  clock_t inicio, fim;

  int length;
  //num = rand()%n;
  
  //printf("list_insert_at:\n");

  //printf("l01: ");
  inicio = clock();
  length = array_list_insert_at(l1, index, num);
  fim = clock();
  //printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  length = array_list_insert_at(l2, index, num);
  fim = clock();
  //printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  length = array_list_insert_at(l3, index, num);
  fim = clock();
  //printf("numero %d inserido no indice %d\n", num, index); 
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  length = linked_list_insert_at(l4, index, num);
  fim = clock();
  //printf("numero %d inserido no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("\n");
}

void remove_from_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num, int index) {

  clock_t inicio, fim;

  int length;
  //num = rand()%n;

  //printf("list_remove_from:\n");

  //printf("l01: ");
  inicio = clock();
  length = array_list_remove_from(l1, index);
  fim = clock();
  //printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  length = array_list_remove_from(l2, index);
  fim = clock();
  //printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  length = array_list_remove_from(l3, index);
  fim = clock();
  //printf("numero removido do indice %d\n", index); 
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  length = linked_list_remove_from(l4, index);
  fim = clock();
  //printf("numero removido em: %d\n", index);
  tempo(inicio, fim);

  printf("\n");

}

void pop_back_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;

  int length;
  
  //printf("list_pop_back:\n");

  //printf("l01: ");
  inicio = clock();
  length = array_list_pop_back(l1);
  fim = clock();
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  length = array_list_pop_back(l2);
  fim = clock();
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  length = array_list_pop_back(l3);
  fim = clock();
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  length = linked_list_pop_back(l4);
  fim = clock();
  tempo(inicio, fim);

  printf("\n");
}

void find_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num) {

  clock_t inicio, fim;

  int index, length;

  //printf("list_find:\n");

  //printf("l01: ");
  inicio = clock();
  index = array_list_find(l1, num);
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l02:\ ");
  inicio = clock();
  index = array_list_find(l2, num);
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  index = array_list_find(l3, num);
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  index = linked_list_find(l4, num);
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("\n");
}

void status_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;

  int size, capacity, occupied;

  //printf("list_print_status:\n");
  
  //printf("l01: ");
  inicio = clock();
  size = array_list_size(l1);
  capacity = array_list_capacity(l1);
  occupied = array_list_percent_occupied(l1);
  fim = clock();
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  size = array_list_size(l2);
  capacity = array_list_capacity(l2);
  occupied = array_list_percent_occupied(l2);
  fim = clock();
  tempo(inicio, fim);
  
  //printf("l03: ");
  inicio = clock();
  size = array_list_size(l3);
  capacity = array_list_capacity(l3);
  occupied = array_list_percent_occupied(l3);
  fim = clock();
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  size = linked_list_size(l4);
  occupied = linked_list_percent_occupied(l4);
  fim = clock();
  tempo(inicio, fim);

  printf("\n");
}

void destroy_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;
  
  //printf("array_list_destroy:\n");

  //printf("l01: ");
  inicio = clock();
  array_list_destroy(l1);
  fim = clock();
  tempo(inicio, fim);

  //printf("l02: ");
  inicio = clock();
  array_list_destroy(l2);
  fim = clock();
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  array_list_destroy(l3);
  fim = clock();
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  linked_list_destroy(l4);
  fim = clock();
  tempo(inicio, fim);  

  printf("\n");
}

void find_and_remove_from_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int num) {

  clock_t inicio, fim;

  int length;

  //printf("list_find:\n");

  //printf("l01: ");
  inicio = clock();
  length = array_list_remove_from(l1, array_list_find(l1, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l02:\ ");
  inicio = clock();
  length = array_list_remove_from(l2, array_list_find(l2, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  length = array_list_remove_from(l3, array_list_find(l3, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  length = linked_list_remove_from(l4, linked_list_find(l4, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("\n");
  
}

void push_back_find_and_remove_from_test(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4, int n, int num) {

  clock_t inicio, fim;

  int length;

  //printf("list_find:\n");

  //printf("l01: ");
  inicio = clock();
  array_list_populate(l1, n);
  length = array_list_remove_from(l1, array_list_find(l1, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l02:\ ");
  inicio = clock();
  array_list_populate(l2, n);
  length = array_list_remove_from(l2, array_list_find(l2, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l03: ");
  inicio = clock();
  array_list_populate(l3, n);
  length = array_list_remove_from(l3, array_list_find(l3, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  //printf("l04: ");
  inicio = clock();
  linked_list_populate(l4, n);
  length = linked_list_remove_from(l4, linked_list_find(l4, num));
  fim = clock();
  //printf("numero %d encontrado no indice %d\n", num, index);
  tempo(inicio, fim);

  printf("\n");
  
}

void print_list(array_list_int* l1, array_list_int* l2, array_list_int* l3, linked_list_int* l4) {

  clock_t inicio, fim;

  inicio = clock();
  array_list_print(l1);
  fim = clock();
  tempo(inicio, fim);

  inicio = clock();
  array_list_print(l2);
  fim = clock();
  tempo(inicio, fim);

  inicio = clock();
  array_list_print(l3);
  fim = clock();
  tempo(inicio, fim);

  inicio = clock();
  linked_list_print(l4);
  fim = clock();
  tempo(inicio, fim);
  

}
