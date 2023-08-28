PROJECT_NAME := cub3d
BIN_NAME  := cub3d
CC        := cc
ROOTDIR   := .
SRCDIR    := src
HEADERDIR := inc
LIBDIR    := lib
BUILDDIR  := build
BINDIR    := bin
LIBSRCDIR := libraries
TARGET    := $(BINDIR)/$(BIN_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name '*.c' | grep -v tests)
HEADERS   := $(shell find $(HEADERDIR) -type f -name '*.h' | grep -v tests)
LIB       := -L./lib -lft -lmlx -lXext -lX11 -lm -lz
LIBS      := $(shell find $(LIBDIR) -type f -name '*.a')
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)%,$(addsuffix .d,$(basename $(SOURCES))))
BONUS     := 0
CFLAGS    := -Wall -Wextra -Werror -g -DBONUS=$(BONUS)
INC       := -Iinc -Isrc

LIB_DIRS  := $(shell find $(LIBSRCDIR) -type d -exec test -e '{}/Makefile' ';' -print)

RESET=`tput sgr0`
GREEN=`tput setaf 2`
RED=`tput setaf 1`
YELLOW=`tput setaf 3`
BLUE=`tput setaf 4`
MAGENTA=`tput setaf 5`

define print_yellow
	echo "$(YELLOW)$(1)$(RESET)"
endef

define print_green
	echo "$(GREEN)$(1)$(RESET)"
endef

define print_red
	echo "$(RED)$(1)$(RESET)"
endef

all: $(LIBDIR) $(BINDIR) $(BUILDDIR) $(OBJECTS)
	@$(call print_green,"Linking object files")
	@$(CC) -o $(TARGET) $(OBJECTS) $(LIB)
	@printf "$(RED)$(TARGET)$(RESET)$(GREEN) has been created!\n$(RESET)";

$(LIBDIR):
	@mkdir -p $(LIBDIR)
	@for dir in $(LIB_DIRS); do \
		printf "$(BLUE)Making $(RESET)$(RED)$$dir\n$(RESET)"; \
		make -C $$dir && mv $$dir/*.a $(LIBDIR)/; \
	done

bonus:
	make all BONUS=1

clean:
	@printf "$(BLUE)Deleting the $(RESET)$(BUILDDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BUILDDIR) 
	@for dir in $(LIB_DIRS); do \
		make -C $$dir clean; \
	done

fclean: clean
	@printf "$(BLUE)Deleting the $(RESET)$(BINDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BINDIR);
	@printf "$(BLUE)Deleting the $(RESET)$(LIBDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(LIBDIR)

re: fclean all

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.d)

-include $(DEPS)

.PHONY: all clean fclean re
