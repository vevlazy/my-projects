CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
GCFLAGS = -fprofile-arcs -ftest-coverage
CHECK_VERSION = 0.15.2
LCOV_VERSION = 2.0
LOCAL_DIR = $(HOME)/local
PATH := $(LOCAL_DIR)/bin:$(PATH)
export PATH

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	PLATFORM = macos
else
	PLATFORM = linux
endif

all: install_deps s21_string.a gcov_report

s21_string.o: s21_string.c
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o

test: s21_string.a
	$(CC) $(FLAGS) -o test test.c -L. s21_string.a -L$(LOCAL_DIR)/lib -lcheck -lsubunit -lm -I$(LOCAL_DIR)/include
	./test || true

gcov_report: s21_string.a test
	$(CC) $(FLAGS) $(GCFLAGS) -o test test.c -L. s21_string.a -L$(LOCAL_DIR)/lib -lcheck -lsubunit -lm -I$(LOCAL_DIR)/include
	./test || true
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info -o gcov_report

install_deps:
ifeq ($(PLATFORM), macos)
	@$(MAKE) install_check
	@$(MAKE) install_lcov
else
	@echo "Installing dependencies using system package manager..."
	@sudo apt-get update && sudo apt-get install -y check lcov
endif

install_check:
	@if [ ! -f "$(LOCAL_DIR)/lib/libcheck.a" ]; then \
		echo "Downloading and installing check library..."; \
		mkdir -p $(LOCAL_DIR); \
		curl -L -o check-$(CHECK_VERSION).tar.gz https://github.com/libcheck/check/releases/download/$(CHECK_VERSION)/check-$(CHECK_VERSION).tar.gz; \
		tar -xvzf check-$(CHECK_VERSION).tar.gz; \
		cd check-$(CHECK_VERSION) && ./configure --prefix=$(LOCAL_DIR) && make && make install; \
		rm -rf check-$(CHECK_VERSION) check-$(CHECK_VERSION).tar.gz; \
		echo "Check library installed to $(LOCAL_DIR)"; \
	else \
		echo "Check library is already installed."; \
	fi

install_lcov:
	@if ! command -v lcov &> /dev/null; then \
		echo "Downloading and installing lcov..."; \
		mkdir -p $(LOCAL_DIR); \
		curl -L -o lcov-$(LCOV_VERSION).tar.gz https://github.com/linux-test-project/lcov/releases/download/v$(LCOV_VERSION)/lcov-$(LCOV_VERSION).tar.gz; \
		tar -xvzf lcov-$(LCOV_VERSION).tar.gz; \
		cd lcov-$(LCOV_VERSION) && make install PREFIX=$(LOCAL_DIR); \
		rm -rf lcov-$(LCOV_VERSION) lcov-$(LCOV_VERSION).tar.gz; \
		echo "lcov installed to $(LOCAL_DIR)"; \
	else \
		echo "lcov is already installed."; \
	fi

clean:
	rm -f s21_string.o s21_string.a test *.gcda *.gcno coverage.info
	rm -rf gcov_report

.PHONY: all install_deps install_check install_lcov clean