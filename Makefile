NAME		= test
BUILD_DIR	= build
SRCS_DIR	= src
LINK_FLAGS	= -L../ -lasm
CC			= cc
CFLAGS		= -I./include

SRC 	= main.c

OBJ 	= $(SRC:.c=.o)

SRCS	= $(addprefix $(SRCS_DIR)/,$(SRC))
OBJS	= $(addprefix $(BUILD_DIR)/,$(OBJ))

-include ../build/deps.mk
BUILD_DEP	= $(addprefix ../,$(BUILD_DEP_INC)) \
				Makefile

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	@ make -s -C ..
	@ $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LINK_FLAGS)

$(BUILD_DIR):
	@ mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o : $(SRCS_DIR)/%.c $(BUILD_DEP)
	@ $(CC) -c $< -o $@ $(CFLAGS)

clean:
	@ make -s -C .. clean
	@ rm -f $(NAME)

fclean: clean
	@ make -s -C .. fclean
	@ rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
