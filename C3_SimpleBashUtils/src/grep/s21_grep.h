#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct options {
  char pattern[8096];
  int e_multi;
  int files_count;
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} opt;
opt options = {0};

int parser(int argc, char *argv[], opt *options);
void search(char **argv, opt *options);
void o_case(char *line, regex_t regex, opt *options, int str_count,
            char **argv);

#endif  // SRC_GREP_S21_GREP_H_