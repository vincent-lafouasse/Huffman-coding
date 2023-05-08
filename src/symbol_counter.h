#pragma once

#define N_MAX_SYMBOLS 128

typedef struct {
  char symbol;
  int count;
} SymbolCount;

typedef struct {
  SymbolCount map[N_MAX_SYMBOLS];
  int len;
} FrequencyMap;

FrequencyMap* frequency_map_from_string(const char* input);
void print_frequency_map(FrequencyMap* frequency_map);
void print_symbol_count(SymbolCount symbol_count);
