# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/01/22 17:46:49 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_minishell1

CC =			gcc

FLAGS =			-Wall -Werror -Wextra -g

HEADER =		./includes/minishell.h \
				./includes/filedir.h \
				./includes/get_next_line.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR)

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME)

FT_LIB_NAME =	ft

FT_LIB =		lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				handle_sigint.o \
				interpret_status.o \
				get_next_line.o \
				read_stdin.o \
				ft_strjoinfree.o \
				isdir.o \
				filedir.o \
				del_filedir.o \
				shell_perror.o \
				ft_sort_string_array.o \
				init_shell_env.o \
				gen_env_key.o \
				add_env_key.o \
				del_env_key.o \
				key_str.o \
				fetch_env_key.o \
				ft_putfourstr.o \
				parse_input_args.o \
				get_exec_path.o \
				fork_exec_with_env.o \
				append_quote.o \
				print_env.o \
				env_key_count.o \
				del_input_args.o \
				check_malloc.o

COMPILED =		$(SRC_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(SRC_COMPILED)
	$(CC) -o $(NAME) $(FLAGS) $(LIBRARIES) $(HEADER_DIR) $(SRC_COMPILED)

$(SRC_COMPILED): %.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c $(FLAGS) $(HEADER_DIR) $< -o $@

$(FT_LIB):
	@make -C $(FT_LIB_DIR);

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
