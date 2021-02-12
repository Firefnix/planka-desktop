#~~~ Meta ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CC = gcc
.PHONY : clean

#~~~ Sources ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
main_SOURCE = src/main.c
layout = glade/layout.glade

#~~~ Paths ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CC_INCLUDE = -I./src
SOURCE_DIR = src
ROOT_DIR = $(shell realpath .)

#~~~ Libraries ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
gtk3_flags ?= $(shell pkg-config --cflags --libs gtk+-3.0)
webkit2_flags ?= $(shell pkg-config --cflags --libs webkit2gtk-4.0)
libs_FLAGS ?= $(gtk3_flags) $(webkit2_flags)


#~~~ Warnings ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WARN ?= -Wall -Walloca -Walloc-zero  -Warray-bounds=2  -Wbad-function-cast \
	-Wcast-align -Wcast-qual -Wdisabled-optimization -Wdouble-promotion \
	-Wduplicated-branches -Wduplicated-cond -Wextra -Wfloat-conversion \
	-Wfloat-equal -Wformat=2 -Wformat-overflow=2 -Wformat-security \
	-Wformat-signedness -Winit-self -Winvalid-pch -Wjump-misses-init \
	-Wlogical-op -Wmissing-include-dirs -Wnested-externs -Wno-shadow \
	-Wnull-dereference -Wold-style-definition -Wpacked -Wpointer-arith \
	-Wredundant-decls -Wstrict-prototypes -Wsuggest-attribute=noreturn \
	-Wtrampolines -Wundef -Wunused-macros -Wvector-operation-performance \
	-Wwrite-strings
NO_WARN ?= -Wno-unused-parameter
WARNINGS ?= $(WARN) $(NO_WARN)


#~~~ Compiler options ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CC_OPTIONS ?= -pthread -rdynamic
CFLAGS ?= $(CC_INCLUDE) $(CC_OPTIONS) $(libs_FLAGS) $(WARNINGS)


#~~~~ TARGETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TARGET ?= bin/planka
header_files ?= $(shell find ./src/ -name *.h)
c_files = $(shell find ./src/ -name *.c)
objects_with_c ?= $(filter $(c_files), $(patsubst %.h,%.c,$(header_files)))
# _OBJECTS ?= $(patsubst %.h,%.o,$(objects_HEADERS))
# TODO: Select all .h files near to a .c file
OBJECTS ?= $(patsubst ./src/%.c,./obj/%.o,$(objects_with_c))

#~~~ Build rules ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$(TARGET): $(main_SOURCE) $(OBJECTS)
	@echo "🤖 $(main_SOURCE) -> $(TARGET)"
	@$(CC) $(main_SOURCE) $(OBJECTS) -o $(TARGET) $(CFLAGS)

obj/%.o: src/%.c
	@echo "⚙ $< -> $@"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@echo "🗑 $(shell find . -name *.o) $(TARGET)"
	@find . -name *.o | xargs rm -f $(TARGET)
