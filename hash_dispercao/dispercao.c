#include <stdio.h>
#include <stdlib.h>

typedef struct Hash_Map_No {
  unsigned int hash_index;
  int valor;
} Hash_Map_No;

typedef struct Hash_Map {
  int cont_elemento;
  int map_size;
  Hash_Map_No **node_list;
} Hash_Map;

Hash_Map *hash_map_new(int);
unsigned int hash_map_hash_fun(Hash_Map *, unsigned int);
Hash_Map_No *hash_map_verifica(Hash_Map *, unsigned int);
void hash_map_insere(Hash_Map *, unsigned int, int);
void hash_map_remove(Hash_Map *, int);

int main() {
  Hash_Map *hash_map = hash_map_new(100);

  hash_map_insere(hash_map, 1, 42);
  hash_map_insere(hash_map, 2, 88);
  hash_map_insere(hash_map, 3, 100);

  Hash_Map_No *resultado = hash_map_verifica(hash_map, 2);

  if (resultado != NULL) {
    printf("\nChave encontrada! Valor: %d\n", resultado->valor);
  } else {
    printf("\nChave não encontrada");
  }

  hash_map_remove(hash_map, 2);

  resultado = hash_map_verifica(hash_map, 2);
  if (resultado != NULL) {
    printf("\nChave encontrada! Valor: %d\n", resultado->valor);
  } else {
    printf("\nChave não encontrada");
  }

  for (int i = 0; i < hash_map->map_size; i++) {
    if (hash_map->node_list[i] != NULL) {
      free(hash_map->node_list[i]);
    }
  }
  free(hash_map->node_list);
  free(hash_map);

  return 0;
}

Hash_Map *hash_map_new(int size) {
  int i;
  Hash_Map *hash_map = (Hash_Map *)malloc(sizeof(Hash_Map));
  hash_map->node_list = (Hash_Map_No **)malloc(size * sizeof(Hash_Map_No *));
  hash_map->cont_elemento = 0;
  hash_map->map_size = size;

  for (i = 0; i < size; i++) {
    hash_map->node_list[i] = NULL;
  }

  return hash_map;
}

unsigned int hash_map_hash_fun(Hash_Map *hash_map, unsigned int key) {
  unsigned int hash = key;
  hash = (hash >> 3) * 2654435761;
  hash = hash % hash_map->map_size;
  return hash;
}

Hash_Map_No *hash_map_verifica(Hash_Map *hash_map, unsigned int key) {
  unsigned int hash = hash_map_hash_fun(hash_map, key);
  Hash_Map_No *hash_map_node = hash_map->node_list[hash];

  if (hash_map_node == NULL) {
    return NULL;
  } else {
    return hash_map_node;
  }
}

void hash_map_insere(Hash_Map *hash_map, unsigned int key, int valor) {
  unsigned int hash = hash_map_hash_fun(hash_map, key);
  Hash_Map_No *hash_map_node = hash_map->node_list[hash];

  if (hash_map_node != NULL && hash_map_node->hash_index == key) {
  } else {
    hash_map_node = (Hash_Map_No *)malloc(sizeof(Hash_Map_No));
    hash_map_node->hash_index = key;
    hash_map_node->valor = valor;
    hash_map->node_list[hash] = hash_map_node;
    hash_map->cont_elemento++;
  }
}

void hash_map_remove(Hash_Map *hash_map, int key) {
  unsigned int hash = hash_map_hash_fun(hash_map, key);
  Hash_Map_No *hash_map_node = hash_map->node_list[hash];

  if (hash_map_node != NULL && hash_map_node->hash_index == key) {
    free(hash_map_node);
    hash_map->node_list[hash] = NULL;
    hash_map->cont_elemento--;
  }
}
