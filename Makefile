# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 23:45:33 by Nathanael         #+#    #+#              #
#    Updated: 2022/03/21 03:27:00 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################
#					DIRECTORIES						#
#####################################################
SRCDIR	=	sources
OBJDIR	=	objects
BINDIR	=	bin
INCDIR	=	headers
LIBDIR	=	libraries

TEMPDIR	=	$(BINDIR) $(OBJDIR)

#####################################################
#					FILES							#
#####################################################
SOURCES	:=	$(wildcard $(SRCDIR)/*.c)
INCLUDES:=	$(wildcard $(INCDIR)/*.h)
OBJECTS	:=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM		=	rm -rf
MKDIR	=	mkdir -p

#####################################################
#					COMPILER						#
#####################################################
NAME 	=	so_long
CC		=	gcc

#####################################################
#					FLAGS							#
#####################################################
CFLAGS	=	-Wall -Wextra -Werror -std=c99 -g -I $(INCDIR)
LFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR) -lm

MLXFLAGS=	-L /usr/X11/lib -framework OpenGL -framework AppKit

LIBFLAGS=	$(MLXFLAGS)

#####################################################
#					LIBRARIES						#
#####################################################
FPFDIR	=	$(LIBDIR)/ft_printf
FPRINT	=	$(FPFDIR)/printf.lib

GNLDIR	=	$(LIBDIR)/get_next_line
GNL		=	$(GNLDIR)/get_next_line.lib

LFTDIR	=	$(LIBDIR)/libft
LIBFT	=	$(LFTDIR)/libft.lib

MLXDIR	=	$(LIBDIR)/mlx
MLX		=	$(MLXDIR)/libmlx.a

LIBS	=	$(FPRINT) $(GNL) $(LIBFT) $(MLX)

#####################################################
#					COMMANDS						#
#####################################################
all: dirs makelib $(LIBS) $(BINDIR)/$(NAME)

dirs:
	@$(MKDIR) $(TEMPDIR)
	@printf "Made directories: %s\n" $(TEMPDIR)

cleanlib:
	@$(MAKE) -C $(LFTDIR) re
	@$(MAKE) -C $(FPFDIR) re
	@$(MAKE) -C $(GNLDIR) re
	@$(MAKE) -C $(MLXDIR) re
	@clear
	@printf "Cleaned libraries: %s\n" $(LIBS)

makelib:
	@cp $(LFTDIR)/$(INCDIR)/*.h $(INCDIR)
	@cp $(FPFDIR)/$(INCDIR)/*.h $(INCDIR)
	@cp $(GNLDIR)/$(INCDIR)/*.h $(INCDIR)
	@cp $(MLXDIR)/*.h $(INCDIR)
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(FPFDIR)
	@$(MAKE) -C $(GNLDIR)
	@$(MAKE) -C $(MLXDIR)
	@clear
	@printf "Remade libraries: %s\n" $(LIBS)

$(BINDIR)/$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LFLAGS) -o $@ $(LIBS) $(LIBFLAGS)
	@clear
	@printf "Compiled %s successfully\n" $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@printf "Linked %s to %s\n" $< $@

clean:
	@$(RM) $(TEMPDIR)
	@clear
	@printf "Cleaned directories: %s\n" $(TEMPDIR)

fclean: clean
	@clear

re: fclean all
	@printf "Cleaned and remade all files!\n"
