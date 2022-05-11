# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# #                                                                          # #
# #       ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗     # #
# #       ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝     # #
# #       ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗       # #
# #       ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝       # #
# #       ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗     # #
# #       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝     # #
# #                                                                          # #
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #

# --------------------------- Terminal Color Codes --------------------------- #
NNN  := \033[1;0m
RED := \033[1;31m
GRN := \033[1;32m
YEL := \033[1;33m
BLU := \033[1;34m
MGN := \033[1;35m
CYN := \033[1;36m
GRA := \033[1;37m

# ---------------------------------------------------------------------------- #

define TITLE
${RED}
+ ---------------------------------------------------------------------------- +
|                                                                              |
|  8""""8 8   8 8  8     8"""88 8""""8 8"""88 8""""8 8   8 8"""" 8""8  8""""8  |
|  8    8 8   8 8  8     8    8 8      8    8 8    8 8   8 8     8  8  8       |
|  8eeee8 8eee8 8e 8e    8    8 8eeeee 8    8 8eeee8 8eee8 8eeee 8ee8e 8eeeee  |
|  88     88  8 88 88    8    8     88 8    8 88     88  8 88    88  8     88  |
|  88     88  8 88 88    8    8 e   88 8    8 88     88  8 88    88  8 e   88  |
|  88     88  8 88 88eee 8eeee8 8eee88 8eeee8 88     88  8 88eee 88  8 8eee88  |
|                                                                              |
+ --------------------------------------------------------------${YEL} BONUS \
${RED}------- +
${NNN}${GRA}
                                        - Created By ${BLU}The-Intruder${NNN}\n
endef
export TITLE

# ---------------------------------------------------------------------------- #
CC		:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror -pthread
CC_OPTS		:= -L. -lphilo

NAME		:= philo
MAIN		:= philo_main.c
HEADER		:= philo_head.h
ARCHIVE		:= libphilo.a

# ---------------------------------------------------------------------------- #
UTLS_DIR := ft_utils/

SRCS_DIR := srcs/
SRCS_LST := ft_utils/ft_calloc.c ft_utils/ft_strcpy.c ft_utils/ft_isdigit.c \
	ft_utils/ft_atoi.c ft_utils/ft_bzero.c ft_utils/ft_strdup.c \
	ft_utils/ft_free.c ft_utils/ft_isspace.c ft_utils/ft_split.c  \
	ft_utils/ft_strjoin.c ft_utils/ft_strlen.c ft_utils/ft_strtrim.c \
	args_parsing.c philo_utilities.c table_utilities.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title

all: title ${NAME}

${NAME}: ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${ARCHIVE} ${OBJS}
	@echo "${BLU}Archive file ${GRA}${ARCHIVE}${BLU} created" \
		"successfully${NNN}\n"
	@${CC} ${CC_FLAGS} ${MAIN} -o ${NAME} ${CC_OPTS} 
	@echo "${GRN}Executable ${GRA}${NAME}${GRN} created" \
		"successfully${NNN} :)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "${MGN}Object file ${GRA}$@${MGN} created from" \
		"${GRA}$<${MGN}${NNN}"

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}${UTLS_DIR}

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${GRA}${NAME}${RED} object files have been deleted${NNN}"

fclean: clean
	@rm -f ${ARCHIVE}
	@echo "${GRA}${ARCHIVE}${RED} archive file ${GRA}${NAME}${RED} has" \
		"been deleted${NNN}"
	@rm -f ${NAME}
	@echo "${GRA}${NAME}${RED} executable file has been deleted${NNN}"

re: fclean all

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- # 
