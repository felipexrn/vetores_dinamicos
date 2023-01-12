#include <stdlib.h> // biblioteca de alocação e de liberação de memoria
#include "linked_list_int.h" // biblioteca de linked_list_int

linked_list_int* linked_list_create() { // cria linked_list
 linked_list_int* new_list = malloc(sizeof(linked_list_int));
  if(new_list == 0)
    return 0;
  new_list->first = 0;
  new_list->last = 0;
  new_list->size = 0;
  return new_list;
}

node* create_node() { // retorna ponteiro para node
  node* new_node = malloc(sizeof(node));  
  new_node->next = 0;
  new_node->previous = 0;
  return new_node;
}

int linked_list_get(linked_list_int* list, int index, int *error) { // Retorna um elemento localizado no índice index.
  *error = 0;
  if (list->size == 0)
    return 0;
  if (index < 0 || index >= list->size) {
    *error = 1;
    return 0;
  }
  node* aux = list->first;
  int value;
  for (int i = 0; i < index; i++) {
    aux = aux->next;
  }
  return aux->value;
}

unsigned int linked_list_push_back(linked_list_int * list, int i) { // Adiciona um novo elemento ao final da lista.
  if (list == 0)
    return 0;
  node* new_node = create_node();
  new_node->value = i;
  if (list->size == 0) {
    list->first = new_node;
    list->last = new_node;
  } else {
    list->last->next = new_node;
    new_node->previous = list->last;
    list->last = new_node;
  }
  list->size++;
  return list->size;
}

unsigned int linked_list_pop_back(linked_list_int * list) { // Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho -1.
  if(list == 0)
    return 0;
  if (list->size == 0)
    return 0;
  node* old_node = list->last;
  if (list->last->previous == 0) {
    list->first = 0;
    list->last = 0;
  } else {  
    list->last = list->last->previous;
    list->last->next = 0;
  }
  free(old_node);
  list->size--;
}

unsigned int linked_list_size(linked_list_int * list) { // Retorna a quantidade de elementos na lista.
  if (list == 0)
    return 0;
  return list->size;
}

int linked_list_find(linked_list_int * list, int element) {// Busca um elemento na lista. Retorna o índice onde ele se encontra ou −1 se ele não estiver na lista.
  if(list == 0)
    return 0;
  node* aux = list->first;
  for (int i = 0; i < list->size; i++) {
    if(aux->value == element)
      return i;
    aux = aux->next;
  }
  return -1;
}

unsigned int linked_list_insert_at(linked_list_int * list, int index, int value) { //Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.
  if(list == 0)
    return 0;
  if(index < 0 || index >= list->size)
    return 0;
  node* new_node = create_node();
  new_node->value = value;
  node* current = list->first;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  if (list->size == 0) {
    list->first = new_node;
    list->last = new_node;
    new_node->value = value;
  } else if (list->first == current) {
    new_node->next = current;
    new_node->previous = current->previous;
    current->previous = new_node;
    list->first = new_node;
  } else {
    new_node->next = current;
    new_node->previous = current->previous;
    node* prev = current->previous;
    prev->next = new_node;
    current->previous = new_node;
  }
  list->size++;
  return list->size;
}

int linked_list_remove_from(linked_list_int * list, int index) { // Remove elemento localizado no índice index.
  if(list == 0)
    return 0;
  if(index < 0 || index >= list->size)
    return 0;
  node* current = list->first;
  for (int i = 0; i <= index; i++) {
    current = current->next;
    if (current == 0) {
      current = list->last;
    }
  }
  if (current->previous == 0) {
    list->first = current->next;
  } else if (current->next == 0) {
    list->last = current->previous;
  } else {
    node* next = current->next;
    node* prev = current->previous;
    prev->next = next;
    next->previous = prev;
  }
  free(current);
  list->size--;
  return list->size;
}

double linked_list_percent_occupied(linked_list_int * list) { // Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0, 0 e 1, 0.
  if(list == 0)
    return 0;
  if(list->first == 0)
    return 0;
  return 1;
}

void linked_list_destroy(linked_list_int * list) { // Libera memória usado pela lista list.
  if(list == 0)
    return 0;
  node* freeded = list->first;
  node* next = freeded->next; 
  for(int i = 0; i < list->size; i++) {
    next = freeded->next;
    free(freeded);
    freeded = next;
  }
  free(list);
}

void linked_list_print(linked_list_int* list) { // imprime linked_list
  printf("{");
  node* aux = list->first;
  for (int i = 0; i < list->size; i++) {
    printf("%d", aux->value);
    if (i < list->size - 1) {
      printf(", ");
    }
    aux = aux->next;
  }
  printf("}\n");
}