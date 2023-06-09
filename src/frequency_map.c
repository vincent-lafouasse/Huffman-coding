#include "frequency_map.h"

#include <stdio.h>
#include <stdlib.h>

static FrequencyMap* new_frequency_map(void);
static void add_occurence(FrequencyMap* frequency_map, char c);

FrequencyMap* frequency_map_from_string(const char* input) {
  FrequencyMap* new = new_frequency_map();

  while (*input != '\0') {
    add_occurence(new, *input);
    input++;
  }
  return new;
}

static void add_occurence(FrequencyMap* frequency_map, char c) {
  for (int i = 0; i < frequency_map->len; i++) {
    if (frequency_map->map[i].symbol == c) {
      frequency_map->map[i].count++;
      return;
    }
  }
  int len = frequency_map->len;
  frequency_map->map[len].symbol = c;
  frequency_map->map[len].count = 1;
  frequency_map->len++;
}

static FrequencyMap* new_frequency_map(void) {
  FrequencyMap* new = malloc(sizeof(FrequencyMap));
  new->len = 0;
  for (int i = 0; i < N_MAX_SYMBOLS; i++) {
    new->map[i].symbol = 0;
    new->map[i].count = -1;
  }
  return new;
}

void print_frequency_map(FrequencyMap* frequency_map) {
  printf("Frequency map:\n");
  for (int i = 0; i < frequency_map->len; i++) {
    SymbolCount current = frequency_map->map[i];
    if (current.count < 0) {
      continue;
    }
    print_symbol_count(current);
  }
  printf("\n");
}

void print_symbol_count(SymbolCount symbol_count) {
  printf("Symbol: '%c' \t Count: %i\n", symbol_count.symbol,
         symbol_count.count);
}
