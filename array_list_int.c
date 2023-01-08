#include <stdlib.h> // biblioteca de alocação e de liberação de memoria
#include "array_list_int.h" // biblioteca de array_list_int

array_list_int* array_list_create_8() { // cria array_list de tamanho 8
  array_list_int* new_list = malloc(sizeof(array_list_int));
  if (new_list == 0)
    return 0;
  new_list->increase = 8;
  new_list->a = malloc(sizeof(int) * new_list->increase);
  if (new_list->a == 0) {
    free(new_list);
    return 0;
  }
  new_list->size = 0;
  new_list->capacity = new_list->increase;
  
  return new_list;
}

array_list_int* array_list_create_10() { // cria array_list de tamanho 10
  array_list_int *new_list = malloc(sizeof(array_list_int));
  if (new_list == 0)
    return 0;
  new_list->increase = 10;
  new_list->a = malloc(sizeof(int)*new_list->increase);
  if (new_list->a == 0) {
    free(new_list);
    return 0;
  }
  new_list->size = 0;
  new_list->capacity = new_list->increase;
  
  return new_list;
}

array_list_int* array_list_create_10k() { // cria array_list de tamanho 10k
  array_list_int* new_list = malloc(sizeof(array_list_int));
  if (new_list == 0)
    return 0;
  new_list->increase = 10000;
  new_list->a = malloc(sizeof(int) * new_list->increase);
  if (new_list->a == 0) {
    free(new_list);
    return 0;
  }
  new_list->size = 0;
  new_list->capacity = new_list->increase;
  
  return new_list;
}

int array_list_increase_memory(array_list_int* list) { // dobra a capacidade da lista
  if (list == 0)
    return 0;
  if (list->increase == 8)
    list->capacity += list->capacity;
  else
    list->capacity += list->increase;
  list->a = realloc(list->a, sizeof(int) * list->capacity);
  return 1;
}

int array_list_get(array_list_int* list, int index, int *error) { // Retorna um elemento localizado no índice index.
  *error = 0;
  if (index < 0 || index >= list->size) {
   *error = 1;
    return 0;
  }
  return list->a[index];
}

unsigned int array_list_push_back(array_list_int* list, int i)  { // Adiciona um novo elemento ao final da lista.
  if (list == 0)
    return 0;
  if (list->size == list->capacity) {
    array_list_increase_memory(list);
  }
  list->a[list->size] = i;
  list->size++;
  return list->size;
}

unsigned int array_list_pop_back(array_list_int* list) { // Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.
  if(list == 0)
    return 0;
  if (list->size == 0)
    return 0;
  list->size--;
  return list->size;
}

unsigned int array_list_size(array_list_int* list) { // Retorna a quantidade de elementos na lista.
  if (list == 0)
    return 0;
  return list->size;
}

int array_list_find(array_list_int* list, int element) { // Busca um elemento na lista. Retorna o índice onde ele se encontra ou −1 se ele não estiver na lista.
  if (list == 0)
    return 0;
  for (int i = 0; i < list->size; i++) {
    if (list->a[i] == element)
      return i;
  }
  return -1;
}

unsigned int array_list_insert_at(array_list_int* list, int index, int value) { // Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.
  if(list == 0) // verifica se a referência da lista é vazia
    return 0;
  if (index < 0 || index >= list->size) // verifica se o índice é inválido
    return 0;
  if (list->size == list->capacity) { // Se a lista estiver cheia aloca mais memória
    array_list_increase_memory(list);
  }
  list->size++; // aumenta tamanho da lista
  int prev = list->a[index]; // variável auxiliar que recebe valor anterior
  list->a[index] = value; // insere value na lista na posição index
  int next = list->a[index+1]; //variável auxiliar que recebe próximo valor
  for (int i = index+1; i < list->size; i++) { // laço que organiza lista
    next = list->a[i]; // variável auxiliar recebe o valor atual
    list->a[i] = prev; // insere valor anterior na posição atual
    prev = next; // variavél auxiliar recebe o valor atual
  }
  return list->size; // retorna o tamanho da lista
}

unsigned int array_list_remove_from(array_list_int* list, int index) { // Remove elemento localizado no índice index.
  if(list == 0)
    return 0;
  if (index < 0 || index >= list->size)
    return 0;
  list->size--;
  for (int i = index; i < list->size; i++) {
    list->a[i] = list->a[i+1];
  }
  return list->size;
}

unsigned int array_list_capacity(array_list_int* list) { // Retorna o espaço efetivamente reservado para a lista.
  if(list == 0)
    return 0;
  return list->capacity;
}

double array_list_percent_occupied(array_list_int* list) { // Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0, 0 e 1, 0.
  if(list == 0)
    return 0;
  if(list->size == 0)
    return 0;
  return (double) list->size / (double) list->capacity;
}

void array_list_print(array_list_int* list) { // imprime array_list
  int x, erro;
  printf("{");
  for (int i = 0; i < array_list_size(list); i++) {
    x = array_list_get(list, i, &erro);
    if(!erro) {
      printf("%d", x);
    } else {
      printf("ERRO: índice %d não é válido!\n", i);
      exit(2);
    }
    if (i < list->size - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

void array_list_destroy(array_list_int* list) { // Libera memória usada pela lista
  free(list->a);
  free(list);
}