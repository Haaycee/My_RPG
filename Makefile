##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
END = \033[0m

SRC	=	$(wildcard ./src/*.c) \
		$(wildcard ./src/utils/*.c) \
		$(wildcard ./src/lib/*.c) \
		$(wildcard ./src/inits/*.c) \
		$(wildcard ./src/game/others/*.c) \
		$(wildcard ./src/game/player/*.c) \
		$(wildcard ./src/game/battle/*.c) \
		$(wildcard ./src/game/pnj_enemies/*.c) \
		$(wildcard ./src/menu/*.c) \
		$(wildcard ./src/map_generation/*.c) \
		$(wildcard ./src/game/hunter/*.c)

NBR_OF_FILES := $(words $(SRC))

SRC_LIB = 	$(wildcard src/lib/*.c)
SRC_TESTS = $(wildcard tests/*.c)

SRC_OBJ	=	$(SRC:.c=.o)
OBJ_LIB = 	$(SRC_LIB:.c=.o)
OBJ_TESTS = $(SRC_TESTS:.c=.o)

SRC_NAME	=	my_rpg
UNIT_TEST = unit_tests

CSFMLF	=	-lcsfml-system -lcsfml-window -lcsfml-audio \
			-lcsfml-graphics -lm -Wno-deprecated-declarations
CFLAGS	=	-I./include -g3
CRFLAGS = --coverage -lcriterion
ifeq	($(DEBUG),yes)
	CFLAGS += -g3
endif

all:	$(SRC_NAME)

$(SRC_NAME):	$(SRC_OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
	@ $(CC) -o $(SRC_NAME) $(SRC_OBJ) $(CSFMLF)

clean:
	@ echo "$(RED) Removing .o's"
	@ $(RM) $(SRC_OBJ)
	@ echo "$(RED) Done"
	@@rm -rf *.gcno
	@@rm -rf *.gcda

fclean:	clean
	@ echo "$(RED) Removing binary"
	@ $(RM) $(SRC_NAME)
	@@rm -rf $(UNIT_TEST)

re:	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY:	all clean fclean re

$(UNIT_TEST): $(OBJ_LIB)
	gcc -o $(UNIT_TEST) $(SRC_TESTS) $(SRC_LIB) $(CRFLAGS) -I./include

tests_run: $(UNIT_TEST)
	./$(UNIT_TEST)

run_tests: $(UNIT_TEST)
	./$(UNIT_TEST)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
