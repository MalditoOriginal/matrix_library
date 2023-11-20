CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11
OS := $(shell uname)
CSRC := $(filter-out s21_*_test.c, $(wildcard s21_*.c))
OBJ := $(CSRC:.c=.o)

ifeq ($(OS),Linux)
FLAGS := -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage -lcheck
else
FLAGS := -lm -lpthread -fprofile-arcs -ftest-coverage -lcheck
endif

TESTS := s21_calc_complements_test s21_create_test s21_determinant_test \
	s21_eq_matrix_test s21_inverse_matrix_test s21_matrix_test s21_mul_matrix_test \
	s21_mul_number_test s21_sub_matrix_test s21_sum_matrix_test

all: clean s21_matrix.a test gcov_report

test: $(TESTS)

$(TESTS): %: %.c s21_matrix.a
	$(CC) $< s21_matrix.a $(FLAGS) -o $@
	./$@

s21_matrix.a: $(OBJ)
	ar -crs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all test clean gcov_report style style_test cppcheck

gcov_report: clean 
	lcov -t "Code Coverage Report" -o report.info --no-external -c -d .
	genhtml -o report report.info

	open ./report/index.html

clean:
	rm -rf *.o *.a $(TESTS) *.gcno *gcda *.gcov gcov report report.info

style_apply:
	clang-format -i -style=google *.c *.h

style_test:
	clang-format -n -style=google *.c *.h

cppcheck:
	cppcheck *.c *.h