NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCF = Srcs/HighestFunctions/*.c \
		Srcs/HighestFunctions/Parsing/*.c \
		Srcs/HighestFunctions/*.c \
		Srcs/HighestFunctions/Parsing/*.c \
		Srcs/Char/*.c \
		Srcs/String/*.c \
		Srcs/Pointer/*.c \
		Srcs/OxX/*.c \
		Srcs/DI/*.c \
		Srcs/Unsigned/*.c \
		Srcs/Float/*.c

SRCFLIB = libft/ft_*.c

OBJF = obj/*.o

INCLUDE = -I MainHeader/ft_printf.h

LIB_INCLUDE = -I libft/libft.h

all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) -c $(SRCF) $(SRCFLIB) $(INCLUDE) $(LIB_INCLUDE)
	mkdir obj
	mv *.o obj
	ar rc $(NAME) $(OBJF)
	ranlib $(NAME)
	gcc $(FLAGS) $(NAME)

clean:
	/bin/rm -rf obj/*
	/bin/rm -f libft/*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf obj
	/bin/rm -f a.out
	/bin/rm -f libft/libft.a

re: fclean all
