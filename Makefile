# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: mde-beer <mde-beer@student.codam.nl>          +#+                     #
#                                                     +#+                      #
#    Created: 2024/11/27 13:22:56 by mde-beer       #+#    #+#                 #
#    Updated: 2024/11/27 14:35:44 by mde-beer       ########   odam.nl         #
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
					thief_of_joy.c
SRCDIR			=	source
OBJ				=	$(SRC:.c=.o)
OBJDIR			=	objects
LIBFTDIR		=	libft
LIBFT			=	$(LIBFTDIR)/libft.a
INCLDIR			=	include $(LIBFTDIR)/include
SOURCE			=	$(addprefix $(SRCDIR)/,$(SRC))
OBJECTS			=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))
INCLUDE			=	$(addprefix -I ,$(INCLDIR))
NAME			=	push_swap

all				:	$(NAME)

$(NAME)			:	$(OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBFT) -o $@

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

.PHONY			: clean fclean re
