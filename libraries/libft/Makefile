PROJECT_NAME := Libft
BIN_NAME  := libft.a
CC        := cc
AR        := ar rcs
ROOTDIR   := ../
SRCDIR    := src
HEADERDIR := inc
LIBDIR    := lib
BUILDDIR  := build
TARGET    := $(BIN_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name *.c*)
HEADERS   := $(shell find $(HEADERDIR) -type f -name *.h*)
LIB       := 
LIBS      := $(shell find $(ROOTDIR) -type f -name *.a*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -Wall -Werror -Wextra -g
INC       := -Iinc -Isrc

GREEN=`tput setaf 2`
RED=`tput setaf 1`
RESET=`tput sgr0`

define print_green
	@echo "$(GREEN)$(1)$(RESET)"
endef

define print_red
	@echo "$(RED)$(1)$(RESET)"
endef

all: $(TARGET)

clean:
	$(call print_red,"Deleting the $(BUILDDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BUILDDIR) 

fclean: clean
	$(call print_red,"Deleting the $(BINDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BIN_NAME)

re: fclean all

$(TARGET): $(BUILDDIR) $(OBJECTS)
	$(call print_green,"Linking object files...")
	@$(AR) $(TARGET) $(OBJECTS)
	$(call print_green,"$(TARGET) has been created!")

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.d)

-include $(DEPS)

.PHONY: clean fclean all
