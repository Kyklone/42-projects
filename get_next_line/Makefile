# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkortela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 14:10:48 by hkortela          #+#    #+#              #
#    Updated: 2020/02/17 12:10:00 by hkortela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YEL		 =		\033[0;33m

NC		 =		\033[0m

BASE	 =		get_next_line.c GNL_main.c

FLAGS	 =		-Wall -Wextra -Werror

LIB		 =		-L. -lft

TAR?	 =

all: compile mains

compile:
	make -f libft/Makefile
	ar rc libft.a *.o

mains: main1 main2 main3 main4
	
main1:
	gcc -o gnl1 $(FLAGS) main_gnl1.c $(BASE) $(LIB)
	printf "\nContent of test file: \n"
	printf "${YEL}"
	cat -e test_1l
	printf "${NC}\n"
	./gnl1

main2:
	gcc -o gnl2 $(FLAGS) main_gnl2.c $(BASE) $(LIB)
	printf "\nContent of test file: \n"
	printf "${YEL}"
	cat -e test_1l_nl
	printf "${NC}\n"
	./gnl2

main3:
	gcc -o gnl3 $(FLAGS) main_gnl3.c $(BASE) $(LIB)
	printf "\nContent of test file: \n"
	printf "${YEL}"
	cat -e test_2l
	printf "${NC}\n"
	./gnl3

main4:
	gcc -o gnl4 $(FLAGS) main_gnl4.c $(BASE) $(LIB)
	printf "\nContent of test file: \n"
	printf "${YEL}"
	cat -e test_2l_nl
	printf "${NC}\n"
	./gnl4

t:
	gcc -o gnl5 $(FLAGS) main_gnl5.c $(BASE) $(LIB)
	printf "\nContent of test file: \n"
	printf "${YEL}"
	cat -e $(TAR) 
	printf "${NC}\n"
	./gnl5 $(TAR)

lib:
	make -f libft/Makefile re
	make wiki

wiki:
	gcc main.c get_next_line.c -L. -lft
	./a.out wikiarticle

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a gnl*

re: fclean all
