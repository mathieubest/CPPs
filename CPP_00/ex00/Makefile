NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = objs/
SRCS_DIR = srcs/

FILES = megaphone.cpp

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
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re check

# ==================================================================================
# CHECKING MANDATORY RESULTS =======================================================
check: $(NAME)
	@/bin/echo
	@/bin/echo "Expected  : SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	@/bin/echo -n "megaphone : "
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@/bin/echo
	@/bin/echo "Expected  : DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	@/bin/echo -n "megaphone : "
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@/bin/echo
	@/bin/echo "Expected  : * LOUD AND UNBEARABLE FEEDBACK NOISE *"
	@/bin/echo -n "megaphone : "
	@./$(NAME)
	@/bin/echo
# ==================================================================================