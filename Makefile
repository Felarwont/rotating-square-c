TARGET := rotating_square

CC ?= gcc
CFLAGS ?= -Wall -std=gnu99
LDFLAGS ?= -lm

BUILD_DIR := build/

.PHONY: build clean

build: $(BUILD_DIR)main.o
	$(CC) -o $(BUILD_DIR)$(TARGET) $^ $(LDFLAGS)

$(BUILD_DIR)main.o: main.c | $(BUILD_DIR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
