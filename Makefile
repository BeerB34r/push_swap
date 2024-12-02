# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: mde-beer <mde-beer@student.codam.nl>          +#+                     #
#                                                     +#+                      #
#    Created: 2024/11/27 13:22:56 by mde-beer       #+#    #+#                 #
#    Updated: 2024/12/02 19:52:52 by mde-beer       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
SRC				=	accountancy.c \
					curta.c \
					ft_dlist.c \
					init_stack.c \
					instructions.c \
					juggler.c \
					oracle.c \
					program_management.c \
					stack_management.c \
					thief_of_joy.c \
					rotate_tandem.c \
					main.c
SRCDIR			=	source
OBJ				=	$(SRC:.c=.o)
OBJDIR			=	objects
LIBFTDIR		=	libft
LIBFT			=	$(LIBFTDIR)/libft.a
INCLDIR			=	include $(LIBFTDIR)/include

SOURCE			=	$(addprefix $(SRCDIR)/,$(SRC))
OBJECTS			=	$(addprefix $(OBJDIR)/,$(OBJ))
INCLUDE			=	$(addprefix -I ,$(INCLDIR))

BONUSSRC		=	checker.c \
					checker_instructions.c
BONUSDIR		=	bonusobj
BONUSOBJ		=	$(BONUSSRC:.c=.o)
BONUSOBJECTS	=	$(addprefix $(BONUSDIR)/,$(BONUSOBJ)) \
					$(addprefix $(BONUSDIR)/,$(OBJ))

CHECKER			=	checker
NAME			=	push_swap

all				:	$(NAME)

$(NAME)			:	$(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBFT) -o $@

bonus			:	$(CHECKER)

$(CHECKER)		:	$(BONUSOBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(BONUSOBJECTS) $(LIBFT) -D CHECKER=1 -o $(CHECKER)

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c | $(OBJDIR)
				$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(BONUSDIR)/%.o	:	$(SRCDIR)/%.c | $(BONUSDIR)
				$(CC) $(CFLAGS) -D CHECKER=1 -c $(INCLUDE) $< -o $@

$(OBJDIR)		:
				mkdir $(OBJDIR)

$(BONUSDIR)		:
				mkdir $(BONUSDIR)

$(LIBFT)		:
				make -C $(LIBFTDIR)

test			:	$(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBFT) $(SRCDIR)/test.c -o $@
clean			:
				make clean -C $(LIBFTDIR)
				rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean			: clean
				make fclean -C $(LIBFTDIR)
				rm -f $(NAME) $(CHECKER)
				rm -rf $(OBJECTDIR) $(BONUSDIR)

re				: fclean all

.PHONY			: clean fclean re
