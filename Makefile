NAME		= libasm.a
BUILD_DIR	= build
SRCS_DIR	= src
ASM			= nasm
ASM_FLAGS	= -f elf64
GITIGNORE	= "*"
GITINCLUDE	= \
			  .idx/dev.nix \
			  .idx/README.md \
			  Makefile \
			  README.md \
			  tester \
			  $(SRCS)

SRC 	= \
		ft_write.s \
		ft_read.s \
		ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s

OBJ 	= $(SRC:.s=.o)

SRCS	= $(addprefix $(SRCS_DIR)/,$(SRC))
OBJS	= $(addprefix $(BUILD_DIR)/,$(OBJ))

BUILD_DEP	= Makefile $(SRCS)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS) .gitignore
	@ echo "BUILD_DEP_INC=$(BUILD_DEP)" > $(BUILD_DIR)/deps.mk
	ar -rcs $(NAME) $(OBJS)

$(BUILD_DIR):
	mkdir -p $(shell dirname $(OBJS))

$(BUILD_DIR)/%.o : $(SRCS_DIR)/%.s $(BUILD_DEP)
	$(ASM) $(ASM_FLAGS) $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(BUILD_DIR)

re: fclean all

GITINCLUDE_DIRS	= $(shell dirname $(GITINCLUDE))
GITINCLUDE_ALL	= $(GITINCLUDE_DIRS) $(GITINCLUDE)
.gitignore: $(OBJS)
	@ echo "Generating gitignore..."
	@ echo "### -- generated .gitignore file -- ###" > .gitignore
	@ echo $(GITIGNORE) >> .gitignore
	@ echo -ne "$(shell echo -ne "$(addprefix \n!,$(GITINCLUDE_ALL))" | uniq | xargs | sed 's/ /\\n/g')" >> .gitignore

.PHONY: all clean fclean re
