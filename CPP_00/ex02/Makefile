NAME = accounts

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

OBJS_DIR = objs/
SRCS_DIR = srcs/

FILES = tests.cpp \
		Account.cpp

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.cpp=.o))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@c++ $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@echo "Cleaning: log files"
	-rm -f *.log
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re