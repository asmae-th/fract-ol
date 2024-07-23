CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx-linux -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm
FRACT = fractol
SRC_F = fractal/fractol.c fractal/init.c fractal/utils.c fractal/mandelbrot.c fractal/julia.c\
	fractal/hook.c fractal/burning_ship.c

OBJF = $(SRC_F:.c=.o)

all: $(FRACT)

$(FRACT): $(OBJF)
	@$(CC) $(CFLAGS) -o $(FRACT) $(OBJF) $(LDFLAGS)
	@echo "Compilation done."

clean:
	@rm -f $(OBJF)

fclean: clean
	@rm -f $(FRACT)

re: clean all

.PHONY: all clean fclean re
