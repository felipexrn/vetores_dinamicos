/*
Autor: Felipe Xavier
*/
#ifndef _ARRAY_LIST_INT_H_ // verificação de declaração de funções
#define _ARRAY_LIST_INT_H_

struct array_list_int {
  int *a; // ponteiro do array
  unsigned int size; // tamamanho do array
  unsigned int capacity; // capacidade do array
  unsigned int increase; // taxa de crescimento array
};

typedef struct array_list_int array_list_int; // redefinição do tipo de array_list_int

array_list_int * array_list_create_8(); // cria array_list nde tamanho 8

array_list_int * array_list_create_10(); // cria array_list de tamanho 10

  array_list_int * array_list_create_10k(); // cria array_list de tamanho 10k

int array_list_increase_memory(array_list_int* list); // aumenta a capacidade da lista de acordo com a estrutura

int array_list_get(array_list_int* list, int index, int* error); // Retorna um elemento localizado no índice index.

unsigned int array_list_push_back(array_list_int* list, int i); // Adiciona um novo elemento ao final da lista.

unsigned int array_list_pop_back(array_list_int* list); // Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.

unsigned int array_list_size(array_list_int* list); // Retorna a quantidade de elementos na lista.

int array_list_find(array_list_int* list, int element); // Busca um elemento na lista. Retorna o índice onde ele se encontra ou −1 se ele não estiver na lista.

unsigned int array_list_insert_at(array_list_int* list, int index, int value); // Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.

unsigned int array_list_remove_from(array_list_int* list, int index); // Remove elemento localizado no índice index.

unsigned int array_list_capacity(array_list_int* list); // Retorna o espaço efetivamente reservado para a lista.

double array_list_percent_occupied(array_list_int* list); // Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0, 0 e 1, 0.

void array_list_print(array_list_int* list); // imprime array_list

void array_list_destroy(array_list_int* list); // Libera memória usada pela lista

#endif