NAME = philo

FILES = \
	philo resrc counter atoi

OFILES = $(FILES:%=%.o)
CFLAGS = -Wall -Wextra -Werror
OPTIM = -ggdb3
LIBS= -lpthread

all: $(NAME)

$(NAME): $(OFILES)
	gcc $(OFILES) $(LIBS) -o $@

$(OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
