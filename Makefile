NAME		=	push_swap

FIL_M		=	main.c \
				utils.c \
				utils2.c \
				init_list.c \
				mouv_push.c \
				traitement.c \

OBJ_M		=	$(FIL_M:.c=.o)

CC			=	gcc
CFLAG		=	
RM			=	rm -f
MAKE		=	make

%.o			:	%.c
			$(CC) $(CFLAG) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJ_M)
			$(CC) $(OBJ_M) $(CFLAG) -o $(NAME)

bonus		:	$(all)

clean		:
			$(RM) $(OBJ_M)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all