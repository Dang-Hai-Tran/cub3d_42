PROJECT_NAME := Libft
BIN_NAME  := libft.a
CC        := cc
AR        := ar rcs
ROOTDIR   := ../
SRCDIR    := src
HEADERDIR := inc
LIBDIR    := lib
BUILDDIR  := build
BINDIR    := bin
TARGET    := $(BINDIR)/$(BIN_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name *.c*)
HEADERS   := $(shell find $(HEADERDIR) -type f -name *.h*)
LIB       := 
LIBS      := $(shell find $(ROOTDIR) -type f -name *.a*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -Wall -Werror -Wextra
INC       := -Iinc -Isrc

RESET=`tput sgr0`
GREEN=`tput setaf 2`
RED=`tput setaf 1`
YELLOW=`tput setaf 3`
BLUE=`tput setaf 4`

define print_yellow
	echo "$(YELLOW)$(1)$(RESET)"
endef

define print_green
	echo "$(GREEN)$(1)$(RESET)"
endef

define print_red
	echo "$(RED)$(1)$(RESET)"
endef

all: $(TARGET)

clean:
	@printf "$(BLUE)Deleting the $(RESET)$(BUILDDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BUILDDIR) 

fclean: clean
	@printf "$(BLUE)Deleting the $(RESET)$(BINDIR) directory in $(RED)$(PROJECT_NAME)\n$(RESET)";
	@rm -rf $(BINDIR)

re: fclean all

debug: CFLAGS += -g
debug:
	@printf "$(MAGENTA)Debug mode enabled\n$(RESET)";
	@$(MAKE) all

release: CFLAGS += -O3
release: 
	@printf "$(MAGENTA)Release mode enabled\n$(RESET)";
	@$(MAKE) all

$(TARGET): $(BINDIR) $(BUILDDIR) $(OBJECTS)
	@$(call print_yellow,"Linking object files")
	@$(AR) $(TARGET) $(OBJECTS)
	@printf "$(RED)$(TARGET)$(RESET)$(GREEN) has been created!\n$(RESET)";
	@echo "\n"

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)


-include $(DEPS)

.PHONY: clean fclean all
