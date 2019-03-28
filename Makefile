SHELL = /bin/sh

.DEFAULT_GOAL := test

# C

HDRS := $(wildcard c/algorithms/*.h)
SRCS := $(wildcard c/algorithms/*.c)
OBJS := $(SRCS:%.c=%.o)

TEST_HDRS := $(wildcard c/test/*.h)
TEST_SRCS := $(wildcard c/test/*.c)
TEST_OBJS := $(TEST_SRCS:%.c=%.o)

INC := \
	c/algorithms \
	c/test \

CC := clang

CFLAGS := -g -Weverything

CPPFLAGS = $(INC:%=-I%)

.PHONY: clean-c
clean-c:
	rm -rf "build"
	find "c" -type f -name "*.o" -exec rm -f {} +

.PHONY: format-c
format-c:
	clang-format -i \
		-style=file \
		$(HDRS) $(SRCS) $(TEST_HDRS) $(TEST_SRCS)

.PHONY: lint-c
lint-c:
	clang-tidy \
		$(HDRS) $(SRCS) $(TEST_HDRS) $(TEST_SRCS) \
		-- \
		$(CPPFLAGS)

.PHONY: test-c
test-c: $(OBJS) $(TEST_OBJS)
	mkdir -p "build"
	$(CC) $^ -o "build/test_c"
	./build/test_c

# Python

.PHONY: clean-python
clean-python:
	find "python" -type d -name "__pycache__" -exec rm -rf {} +
	find "python" -type f -name "*.py[cod]" -exec rm -f {} +

.PHONY: format-python
format-python:
	yapf --in-place --recursive "python"

.PHONY: lint-python
lint-python:
	pylint "python/algorithms" || true
	# Disable `invalid-name`, test method names do not conform to snake_case
	# naming style. See https://github.com/PyCQA/pylint/issues/2047 for more
	# information.
	# Disable `too-many-public-methods`, test classes have lots of tests.
	pylint "python/test" \
		--disable=invalid-name,too-many-public-methods \
		|| true

.PHONY: test-python
test-python:
	python -m unittest discover \
		--start-directory "python/test" \
		--top-level-directory "python"

# All

.PHONY: clean
clean: clean-c clean-python

.PHONY: format
format: format-c format-python

.PHONY: lint
lint: lint-c lint-python

.PHONY: test
test: test-c test-python
