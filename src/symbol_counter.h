#pragma once

#define N_MAX_SYMBOLS 128
#define INVALID_SYMBOL_COUNT \
  { 0, -1 }

typedef struct {
  char symbol;
  int count;
} SymbolCount;

typedef struct {
  SymbolCount map[N_MAX_SYMBOLS];
  int len;
} FrequencyMap;

FrequencyMap* new_frequency_map(void);
void add_occurence(FrequencyMap* frequency_map, char c);
void print_frequency_map(FrequencyMap* frequency_map);
void print_symbol_count(SymbolCount symbol_count);
