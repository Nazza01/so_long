# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 20:21:14 by nervin            #+#    #+#              #
#    Updated: 2022/03/21 02:54:09 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################
#					DIRECTORIES						#
#####################################################
SRCDIR	=	sources
OBJDIR	=	objects
INCDIR	=	headers

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
NAME 	=	printf.lib
CC		=	gcc

#####################################################
#					FLAGS							#
#####################################################
CFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR)
LFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR)

#####################################################
#					COMMANDS						#
#####################################################
all: dirs $(NAME)

dirs:
	@$(MKDIR) $(OBJDIR)
	@clear

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@clear
	@echo "Created "$(NAME)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@echo "Compiled "$<" successfully!"

clean:
	@$(RM) $(OBJDIR)
	@clear
	@echo $(OBJDIR)" directory removed!"

fclean: clean
	@$(RM) $(NAME)
	@clear
	@printf "%s library files cleaned\n" $(NAME)

re: fclean all
	@clear
	@echo $(NAME) "files cleaned and remade successfully!"