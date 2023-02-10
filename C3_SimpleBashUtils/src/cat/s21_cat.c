#include "s21_cat.h"

#include <getopt.h>
#include <stdio.h>

int parser(int argc, char *argv[], opt *options);
void output(char *argv[], opt *options);

int main(int argc, char *argv[]) {
  parser(argc, argv, &options);

  while (optind < argc) {
    output(argv, &options);
    optind++;
  }
  return 0;
}

int parser(int argc, char *argv[], opt *options) {
  const char *short_options = "+benstvTE";
  int rez;
  int option_index;

  while ((rez = (getopt_long(argc, argv, short_options, long_options,
                             &option_index))) != -1) {
    switch (rez) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      default:
        printf("usage: s21_cat [-benstvTE] [file ...]\n");
        break;
    };
  };
  if (options->b) options->n = 0;
  return 0;
}

void output(char *argv[], opt *options) {
  FILE *file_name = fopen(argv[optind], "r");
  if (file_name != NULL) {
    int line_counter = 0;
    int blank_line = 0;
    char previous_symbol = '\n';
    char current_symbol;
    while ((current_symbol = fgetc(file_name)) != EOF) {
      if ((current_symbol == '\n') && (previous_symbol == '\n') &&
          options->s == 1) {
        blank_line = blank_line + 1;
        if (blank_line > 1) continue;
      } else {
        blank_line = 0;
      }
      if (((previous_symbol == '\n') && (current_symbol != '\n')) &&
          ((options->b == 1))) {
        line_counter = line_counter + 1;
        printf("%6d\t", line_counter);
      }
      if ((previous_symbol == '\n') && (options->n == 1)) {
        line_counter = line_counter + 1;
        printf("%6d\t", line_counter);
      }
      if ((current_symbol == '\n') && (options->e == 1)) {
        printf("$");
      }
      if ((current_symbol == 9) && (options->t == 1)) {
        printf("^I");
        previous_symbol = current_symbol;
        continue;
      }
      if (options->v == 1) {
        if (((current_symbol >= 0) && (current_symbol < 9)) ||
            ((current_symbol > 10) && (current_symbol < 32))) {
          current_symbol = current_symbol + 64;
          printf("^");
        } else if (current_symbol == 127) {
          current_symbol = current_symbol - 64;
          printf("^");
        }
      }
      printf("%c", current_symbol);
      previous_symbol = current_symbol;
    }
    fclose(file_name);
  }
}
