# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:26:28 by amayo-ca          #+#    #+#              #
#    Updated: 2022/05/17 13:56:54 by amayo-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSCLIENT	= client.c
SRCSSERVER = server.c
INCLUDE		= -Ift_printf/includes/ -I libft/
LIB	= ft_printf/libftprintf.a libft/libft.a
DIRS = ${dir ${LIB}}
LDPATH = -Lft_printf -Llibft/
LDLIBS = -lft -lftprintf

OBJSCLIENT		= ${SRCSCLIENT:.c=.o}
OBJSSERVER		= ${SRCSSERVER:.c=.o}
NAMECLIENT		= client
NAMESERVER		= server

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o:%.c 	minitalk.h
	${CC} ${CFLAGS} ${INCLUDE}  -c $< -o $@

all:		make_libs 
	$(MAKE) ${NAMECLIENT} 
	$(MAKE) ${NAMESERVER}



${NAMECLIENT}:	${OBJSCLIENT} $(LIB)
			
			${CC} ${CFLAGS} ${INCLUDE} ${LDPATH} ${LDLIBS} ${SRCSCLIENT}  -o ${NAMECLIENT}
	

$(NAMESERVER):	${OBJSSERVER} $(LIB)
			${CC} ${CFLAGS} ${INCLUDE} ${LDPATH} ${LDLIBS} ${SRCSSERVER}  -o ${NAMESERVER}

make_libs: 
	${MAKE} all -C ./ft_printf
	${MAKE} all -C ./libft

clean:
			${MAKE} clean -C ./ft_printf
			${MAKE} clean -C ./libft
			${RM} ${OBJSSERVER} ${OBJSCLIENT}
		

fclean:		clean
			${MAKE} fclean -C ./ft_printf
			${MAKE} fclean -C ./libft
			${RM} ${NAMECLIENT} ${NAMESERVER}

re:			fclean all

.PHONY:		all clean fclean re