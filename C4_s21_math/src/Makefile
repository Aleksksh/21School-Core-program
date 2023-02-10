CC= gcc 
CFLAGS= -Wall -Wextra -Werror -std=c11
PROJECT= s21*.c
TEST= tests/*.c
TEST_FLAGS = -lcheck

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    TEST_FLAGS = -lcheck
else
	TEST_FLAGS = -lcheck -lpthread -pthread -lrt -lm -lsubunit
endif

all: gcov_report

s21_math.a:
	$(CC) $(CFLAGS) $(PROJECT) -c 
	ar rcs s21_math.a *.o
	rm -rf *.o

test:
	$(CC) --coverage $(TEST_FLAGS) $(CFLAGS) $(TEST) $(PROJECT) -o test

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST) $(PROJECT) -pthread -lcheck -pthread -lm -o gcov_test
	./gcov_test
	lcov -t "report" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	rm -rf report
	rm -rf *.a *.out *.o coverage *.gc* *.info
	rm -rf *.gcda *.gcno
	rm -rf gcov_test

rebuild:	clean	all

valgrind_test: clean
	cd ../materials/build/Valgrind/ && bash run.sh

leak:
	CK_FORK=no leaks --atExit -- ./test

linter:
	cp ../materials/linters/.clang-format ../src
	clang-format -i *.c *.h tests/*.c 
	clang-format -n *.c *.h tests/*.c
	rm -rf .clang-format
