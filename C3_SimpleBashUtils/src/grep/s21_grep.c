#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc > 2) {
    if (parser(argc, argv, &options) == 0) {
      if (options.e_multi == 0) {
        sprintf(options.pattern, "%s", argv[optind]);
        optind++;
      }
      if (optind + 1 < argc) {
        options.files_count = 1;
      }
      while (optind < argc) {
        search(argv, &options);
        optind++;
      }
    }
  }
  return 0;
}

int parser(int argc, char *argv[], opt *options) {
  const char *short_options = "e:ivclnhsf:o";
  int flags_err = 0;
  int rez;
  FILE *file_pattern;
  char ch;
  unsigned int pattern_len;
  int blank;

  while ((rez = (getopt_long(argc, argv, short_options, 0, 0))) != -1) {
    switch (rez) {
      case 'e':
        options->e = 1;
        if (options->e_multi > 0) {
          strcat(options->pattern, "|");
        }
        strcat(options->pattern, optarg);
        options->e_multi++;
        break;
      case 'i':
        options->i = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        options->f = 1;
        file_pattern = fopen(argv[optind - 1], "r");
        if (file_pattern != NULL) {
          if (options->e_multi > 0) strcat(options->pattern, "|");
          while ((ch = fgetc(file_pattern)) != EOF) {
            pattern_len = strlen(options->pattern);
            if ((ch == '\0') || (ch == '\n')) {
              if (blank == 0) {
                strcat(options->pattern, "|");
                blank = 1;
              } else {
                strcat(options->pattern, ".");
              }
            } else {
              options->pattern[pattern_len] = ch;
              blank = 0;
            }
          }
          options->e_multi++;
        } else {
          fprintf(stderr, "grep: %s: No such file or directory\n",
                  argv[optind]);
        }
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        flags_err = 1;
        break;
    };
  };
  if (options->f == 1) fclose(file_pattern);
  return flags_err;
}

void search(char **argv, opt *options) {
  FILE *file_name;
  file_name = fopen(argv[optind], "r");
  regex_t regex;
  size_t len;
  char *tmp_line = NULL;
  int cflags = REG_EXTENDED;
  int success;
  int str_num = 0;
  int str_match = 0;
  int i;
  if (options->i) cflags = REG_EXTENDED | REG_ICASE;
  if (file_name) {
    if (regcomp(&regex, options->pattern, cflags) == 0) {
      while (getline(&tmp_line, &len, file_name) != -1) {
        str_num++;
        if ((options->o == 1) && (options->l == 0) && (options->v == 0) &&
            (options->c == 0)) {
          o_case(tmp_line, regex, options, str_num, argv);
        } else {
          if (tmp_line) {
            success = regexec(&regex, tmp_line, 0, NULL, 0);
            if (((success == 0) && (options->v == 0)) ||
                ((success == 1) && (options->v == 1))) {
              str_match++;
              i = 0;
              if (options->c == 0) {
                if (options->l == 1) {
                  printf("%s\n", argv[optind]);
                  break;
                }
                if (((options->files_count == 1) && (options->h == 0))) {
                  printf("%s:", argv[optind]);
                }
                if (options->n == 1) {
                  printf("%d:", str_num);
                }
                while (tmp_line[i]) {
                  if (tmp_line[i] != '\n') printf("%c", tmp_line[i]);
                  i++;
                }
                printf("\n");
              }
            }
          }
        }
      }
      free(tmp_line);
    }
    regfree(&regex);
  } else {
    if (options->s != 1) {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
    }
  }
  if ((options->c == 1) && (str_match == 0)) {
    if (options->files_count == 1) {
      if (options->h == 0) {
        printf("%s:%d\n", argv[optind], str_match);
      } else {
        printf("%d\n", str_match);
      }
    } else {
      if (options->l == 1) printf("%d\n", str_match);
      if ((options->l == 0)) printf("%d\n", str_match);
    }
  }
  if ((options->c == 1) && (str_match > 0)) {
    if (options->files_count == 1) {
      if (options->l == 1) {
        if (options->h == 0) {
          printf("%s:1\n%s\n", argv[optind], argv[optind]);
        } else if (options->h == 1) {
          printf("1\n%s\n", argv[optind]);
        }
      } else if (options->h == 1) {
        printf("%d\n", str_match);
      } else {
        printf("%s:%d\n", argv[optind], str_match);
      }
    } else {
      if (options->l == 1) printf("1\n%s\n", argv[optind]);
      if (options->l == 0) printf("%d\n", str_match);
    }
  }
  fclose(file_name);
}

void o_case(char *line, regex_t regex, opt *options, int str_count,
            char **argv) {
  regmatch_t pmatch[1];
  int i;
  int point = 0;
  while (regexec(&regex, line, 1, pmatch, 0) != REG_NOMATCH) {
    if (point == 0) {
      if (options->files_count == 1) {
        if ((options->h == 0) && (options->n == 0)) printf("%s:", argv[optind]);
        if ((options->h == 0) && (options->n == 1)) printf("%s:", argv[optind]);
        if ((options->h == 1) && (options->n == 1)) printf("%d:", str_count);
        if ((options->h == 0) && (options->n == 1)) printf("%d:", str_count);

      } else {
        if (options->n == 1) printf("%d:", str_count);
      }
    }
    for (i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
      printf("%c", line[i]);
      point++;
    }
    printf("\n");
    line = line + pmatch[0].rm_eo;
  }
}
