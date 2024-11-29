# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: mde-beer <mde-beer@student.codam.nl>          +#+                     #
#                                                     +#+                      #
#    Created: 2024/11/27 13:22:56 by mde-beer       #+#    #+#                 #
#    Updated: 2024/11/29 20:30:20 by mde-beer       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-g
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
					killme.c
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
BONUSOBJ		=	$(BONUSSRC:.c=.o)
NAME			=	push_swap

all				:	$(NAME)

$(NAME)			:	$(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBFT) -o $@

bonus			:	bonus_checker

bonus_checker	:	$(addprefix $(OBJDIR)/,$(BONUSOBJ)) $(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(addprefix $(OBJDIR)/,$(BONUSOBJ)) $(LIBFT) -o bonus_checker

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(OBJDIR)
				$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(OBJDIR)		:
				mkdir $(OBJDIR)

$(LIBFT)		:
				make -C $(LIBFTDIR)

test			:	$(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBFT) $(SRCDIR)/test.c -o $@
clean			:
				rm -rf $(OBJDIR)

fclean			: clean
				rm -f $(NAME)

re				: fclean all

.PHONY			: clean fclean re bonus all
