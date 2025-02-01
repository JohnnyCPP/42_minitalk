# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:27:13 by jonnavar          #+#    #+#              #
#    Updated: 2024/09/26 20:37:23 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################


INCLUDES_PATH	= ./include/
B_INCLUDES_PATH	= ${INCLUDES_PATH}bonus/
LIB_PATH		= ./src/lib/
LIBFT_PATH		= ${LIB_PATH}libft/
LIBFT_INC_PATH	= ${LIBFT_PATH}include/
OBJECTS_PATH	= ./object/
BONUS_OBJ_PATH	= ${OBJECTS_PATH}bonus/
SOURCES_PATH    = ./src/
B_SOURCES_PATH	= ${SOURCES_PATH}bonus/


LIBFT_FILE		= libft.a
LIBFT_NAME		= ${LIBFT_PATH}${LIBFT_FILE}
NAME			= server
DEBUG			= debug


CC				= cc
DEBUG_SYMBOLS	= -g3
CFLAGS			= -Wall -Wextra -Werror ${DEBUG_SYMBOLS}
GDB				= gdb
# both "-g" or "-g3" flags can be used.
# "-g3" includes everything included with "-g", but with 
# additional information to debug preprocessor directives
SANITIZE_FLAGS	= -fsanitize=address ${DEBUG_SYMBOLS}
# "--track-origin=yes" tracks the origin of uninitialized values
# "-s" display a summary of the results directly in the terminal
# "--leak-check=full" enable detailed memory leak detection, and 
#                     report every possible memory leak
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full --show-leak-kinds=all
# "-I <path>" instructs the compiler where to look for header files
# "-L <path>" instructs the linker where to look for static (.a) or 
#             shared (.so) libraries
# "-l<file>" instructs the linker to add a specific library by its name.
#            the linker will consider the "lib" prefix and ".a"/".so" sufix.
#            e.g. "-lft" links against "libft.a" or "libft.so".
#            note: this flag can't have a space in between, it's 
#                  processed as a single token
INCLUDE_LIBFT	= -I ${LIBFT_INC_PATH}
INCLUDE_BONUS	= -I ${B_INCLUDES_PATH}
INCLUDE			= -I ${INCLUDES_PATH} ${INCLUDE_BONUS} ${INCLUDE_LIBFT}
MAKE_LIB		= make -sC


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re
BONUS			= bonus
HELP			= help
CC_SANITIZER	= sanitize
B_CC_SANITIZER	= sanitize_bonus
VALGRIND		= valgrind
PREFIX_LIB		= lib_
LIB_DELETE		= ${PREFIX_LIB}${DELETE}
LIB_CLEAN		= ${PREFIX_LIB}${CLEAN}
LIB_FCLEAN		= ${PREFIX_LIB}${FCLEAN}
LIB_RE			= ${PREFIX_LIB}${RE}


PHONY			= .PHONY
STD_PHONY		= ${ALL} ${CLEAN} ${FCLEAN} ${RE} ${BONUS} ${HELP}
DEBUG_PHONY		= ${CC_SANITIZER} ${B_CC_SANITIZER} ${VALGRIND} ${GDB}
LIB_PHONY		= ${LIB_DELETE} ${LIB_CLEAN} ${LIB_FCLEAN} ${LIB_RE}


MAKE_LIBFT		= ${MAKE_LIB} ${LIBFT_PATH}
DELETE_LIBFT	= ${MAKE_LIBFT} ${DELETE}
CLEAN_LIBFT		= ${MAKE_LIBFT} ${CLEAN}
FCLEAN_LIBFT	= ${MAKE_LIBFT} ${FCLEAN}
RE_LIBFT		= ${MAKE_LIBFT} ${RE}


SOURCE_FILES	= $(wildcard ${SOURCES_PATH}*.c)
BONUS_SOURCES	= $(wildcard ${B_SOURCES_PATH}*.c)
# "patsubst": pattern substitution
# parameters: pattern, replacement, text
#
# pattern: the pattern to match. Supports wildcards
# replacement: the string to replace the pattern with. By using wildcards, 
#              Make keeps the original text matched by the same 
#              wildcard in the pattern
# text: the list of strings on which the substitution will be performed
OBJECT_FILES	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${SOURCE_FILES}}
BONUS_OBJECTS	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${BONUS_SOURCES}}


CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


## RULES ##
###########


${ALL}: ${NAME}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
#
# "|" the pipe syntax indicates that the ${OBJECTS_PATH} is 
#     an Order-Only Prerequisite of the "${OBJECTS_PATH}%.o" target.
#     Order-Only Prerequisites are required, but don't trigger a rebuild.
#     This means that if an Order-Only Prerequisite changes, its target 
#     is not built again
#
#     note: the pipe "|" has been replaced with the create path instruction 
#           in the recipe.
${OBJECTS_PATH}%.o: ${SOURCES_PATH}%.c
	@${CREATE_PATH} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME}
	@echo "The program \"${NAME}\" has been compiled."


${CLEAN}: ${LIB_CLEAN}
	@${DELETE_FILE} ${OBJECT_FILES}
	@${DELETE_PATH} ${OBJECTS_PATH}
	@echo "The objects of program \"${NAME}\" have been deleted."


${FCLEAN}: ${LIB_CLEAN} ${LIB_DELETE} ${CLEAN}
	@${DELETE_FILE} ${LIBFT_NAME}
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


${BONUS}: ${LIBFT_NAME} ${BONUS_OBJECTS}
	@if [ ! -e ${NAME} ]; then \
		${CC} ${CFLAGS} ${BONUS_OBJECTS} ${LIBFT_NAME} -o ${NAME}; \
		echo "The program \"${NAME}\" has been compiled including bonus."; \
	else \
		echo "The program \"${NAME}\" already exists. Skipping compilation."; \
	fi


${HELP}:
	@echo "Available targets:"
	@echo "    all            - Build the project (default)"
	@echo "    clean          - Remove object files"
	@echo "    fclean         - Remove object files and the executable"
	@echo "    re             - Rebuild the project"
	@echo "    bonus          - Build the project with bonus features"
	@echo "    sanitize       - Build with address sanitizer for debugging"
	@echo "    sanitize_bonus - Build the bonus version with address sanitizer for debugging"
	@echo "    valgrind       - Run the program with valgrind"
	@echo "    gdb            - Run the program with gdb"


${CC_SANITIZER}: ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME}


${B_CC_SANITIZER}: ${LIBFT_NAME} ${BONUS_OBJECTS}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${BONUS_OBJECTS} ${LIBFT_NAME} -o ${NAME}
	@echo "C compiler's sanitizer has been added to debug memory issues."


${VALGRIND}: ${NAME}
	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME}


${GDB}: ${NAME}
	@${GDB} ./${NAME}


# library rules
# #############


${LIBFT_NAME}:
	@${MAKE_LIBFT}


${LIB_DELETE}:
	@${DELETE_LIBFT}


${LIB_CLEAN}:
	@${CLEAN_LIBFT}


${LIB_FCLEAN}:
	@${FCLEAN_LIBFT}


${LIB_RE}:
	@${RE_LIBFT}


${PHONY}: ${STD_PHONY} ${DEBUG_PHONY} ${LIB_PHONY}
