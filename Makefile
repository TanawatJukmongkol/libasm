NAME		= libasm.a
BUILD_DIR	= build
SRCS_DIR	= src
ASM			= nasm
ASM_FLAGS	= -f elf64

SRC 	= \
		ft_write.s \
		ft_read.s \
		ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s

OBJ 	= $(SRC:.s=.o)

SRCS	= $(addprefix $(SRCS_DIR)/,$(SRC))
OBJS	= $(addprefix $(BUILD_DIR)/,$(OBJ))

BUILD_DEP	= Makefile $(SRCS)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	echo "BUILD_DEP_INC=$(BUILD_DEP)" > $(BUILD_DIR)/deps.mk
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

.PHONY: all clean fclean re
