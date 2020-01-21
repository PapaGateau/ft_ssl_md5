# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 16:15:48 by plogan            #+#    #+#              #
#    Updated: 2019/05/21 16:58:57 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c singleton.c process.c dispatch.c error.c globals.c \
util/prep_util.c util/buffer_util.c util/bit_util.c util/print_util.c \
md5/md5_algo.c md5/md5_aux.c \
sha256/sha256_algo.c

CC			= clang
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

NAME		= ft_ssl
CFLAGS		= -Wall -Wextra -Werror
OBJS		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
LIBS		= Libft/libft.a Libft/my_printf/libftprintf.a

.PHONY: all

all: makelibs $(NAME)

makelibs:
	@make -C Libft

$(NAME): $(OBJS)
	@$(CC) -o $@ $(LIBS) $(OBJS)
	@echo "Executable:\033[92m OK\033[0m"

$(OBJ_DIR)/%.o: $(addprefix $(SRC_DIR)/,%.c)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/md5
	@mkdir -p $(OBJ_DIR)/sha256
	@mkdir -p $(OBJ_DIR)/util
	@$(CC) -c $^ $(CFLAGS) -o $@

clean:
	@make -C Libft clean
	@rm -rf $(OBJS)
	@echo "Deleting:\033[33m object files\033[0m"

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME)
	@echo "Deleting:\033[33m $(NAME)\033[0m"

re: fclean $(NAME)
