# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/04/10 15:21:38 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = lem-in

FLAG = -Wall -Wextra -Werror

LIBFT = sources/libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = lem_in.c \
          init.c \
          suurbali.c \
          copy_links.c \
          write_result.c \
          write_result2.c \
          bellman_ford.c \
          cost.c \
          divide.c \
          divide2.c \
          weight.c \
          valid.c \
          free.c \
          give_peak.c \
          bfs.c \
          list.c \
          add_in_final.c \
          look_weight_pretend.c \
          stack_and_fill_weight.c \
          read_start_end_ants.c \
          read_peak.c \
          read_tunnel.c \
          read_std.c \


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	gcc -o $(NAME) $(FLAG) $(SRCS) -L $(LIBFT) -lft

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all