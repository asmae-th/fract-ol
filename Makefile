CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx-linux -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm
FRACT = fract
SRC_F = fractol.c init.c utils.c mandelbrot.c julia.c

OBJF = $(SRC_F:.c=.o)

all : $(FRACT) clean

$(FRACT) : $(OBJF)
	$(CC) $(CFLAGS) -o $(FRACT) $(OBJF) $(LDFLAGS)

clean :
	rm -f $(OBJF)

fclean : clean
	rm -f $(FRACT)

re : clean all

.PHONY : all clean fclean re 
