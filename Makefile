PROJECT_NAME := Cub3d
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
LIB       := -L./lib -lft -lgnl -Lmlx -lXext -lX11 -lm -lz
LIBS      := $(shell find $(LIBDIR) -type f -name '*.a')
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -Wall -Werror -Wextra
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

debug: CFLAGS += -g
release: CFLAGS += -O3

all: libs $(BINDIR) $(BUILDDIR) $(OBJECTS)
	@$(call print_green,"Linking object files")
	@$(CC) -o $(TARGET) $(OBJECTS) $(LIB)
	@printf "$(RED)$(TARGET)$(RESET)$(GREEN) has been created!\n$(RESET)";

libs: $(LIBDIR) lib/$(PROJECT_NAME).flag

lib/$(PROJECT_NAME).flag: $(LIBS)
	@for dir in $(LIB_DIRS); do \
		printf "$(BLUE)Making $(RESET)$(RED)$$dir\n$(RESET)"; \
		make -C $$dir && ( mv $$dir/bin/*.a $(LIBDIR)/ || mv $$dir/*.a $(LIBDIR)/ ); \
	done
	@find $(LIBSRCDIR) -type d -empty -name 'bin' -delete
	@touch $@

clean:
	@printf "$(BLUE)Deleting the $(RESET)$(BUILDDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BUILDDIR) 
	@for dir in $(LIB_DIRS); do \
		make -C $$dir clean; \
	done

fclean: clean
	@printf "$(BLUE)Deleting the $(RESET)$(BINDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BINDIR)
	@for dir in $(LIB_DIRS); do \
		rm -rf $$dir/bin; \
	done

re: fclean all

prod: fclean
	@printf "$(BLUE)Deleting the $(RESET)$(LIBDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(LIBDIR)

fre: fclean libs
	@printf "$(BLUE)Deleting the $(RESET)$(LIBDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(LIBDIR)
	@$(MAKE) libs
	@$(MAKE) all

debug: fre

release: 
	@printf "$(MAGENTA)Release mode enabled\n$(RESET)";
	@$(MAKE) all

$(LIBDIR) :
	@mkdir -p $(LIBDIR)

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)

-include $(DEPS)

.PHONY: clean fclean all libs remove-empty-bin-dirs
