NAME		= test
BUILD_DIR	= build
SRCS_DIR	= src
INCLUDE_DIR	= include
LINK_FLAGS	= -L../ -lasm -z noexecstack
CC			= cc
CFLAGS		= #-Wall -Werror -Wextra
GITIGNORE	= "*"
GITINCLUDE	= Makefile README.md $(SRCS)

HEADERS	= libasm.h utils.h tests.h ansi_color.h

SRC 	= main.c \
$(addprefix utils/, \
	assert_fn.c \
	assert_int.c \
	assert_str.c \
) \
$(addprefix tests/, \
	ft_read.c \
	ft_write.c \
	ft_strlen.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
)

OBJ 	= $(SRC:.c=.o)

SRCS	= $(addprefix $(SRCS_DIR)/,$(SRC))
OBJS	= $(addprefix $(BUILD_DIR)/,$(OBJ))

CFLAGS		+= -I$(INCLUDE_DIR)
-include ../build/deps.mk
BUILD_DEP	= $(addprefix ../,$(BUILD_DEP_INC)) \
			$(addprefix $(INCLUDE_DIR)/, $(HEADERS)) \
			Makefile

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS) .gitignore
	@ make -s -C ..
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LINK_FLAGS)

$(BUILD_DIR):
	mkdir -p $(shell dirname $(OBJS))

$(BUILD_DIR)/%.o : $(SRCS_DIR)/%.c $(BUILD_DEP)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@ make -s -C .. clean
	rm -f $(NAME)

fclean: clean
	@ make -s -C .. fclean
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
