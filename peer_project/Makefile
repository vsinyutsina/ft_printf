NAME = libftprintf.a

TEST = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_L = srcs/

INCLUDES = -I includes/ -I libft/

LIST = 		my_printf.c \
			trait.c \
			ft_cheloedouble.c \
			analysis.c \
			forma_chesla.c \
			int_number.c \
			data_types1.c \
			data_types2.c \
			data_types3.c \
			check_types.c \
			zapolne_f.c \
			write_f.c \
			okrug.c \
			okrug_3s.c \
			new_drob.c \
			print_probel.c \
			characters_int.c \
			analysis_flag.c

OBJS =$(SRCS:.c=.o)

SRCS = $(addprefix $(DIR_L), $(LIST))

all: $(NAME)

$(NAME): my_lib $(OBJS)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

my_lib: 
	@make -C $(LIBFT)

%.o: %.c includes/ft_printf.h
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean