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
NNN  := \033[5;0m
RED := \033[5;31m
GRN := \033[5;32m
YEL := \033[5;33m
BLU := \033[5;34m
MGN := \033[5;35m
CYN := \033[5;36m
GRA := \033[5;37m

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
+ ---------------------------------------------------------------------------- +
${NNN}
\t\t\t\t\t\t${GRA} - Created By ${BLU}The-Intruder${NNN}\n
endef
export TITLE

# ---------------------------------------------------------------------------- #
CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror -pthread
CC_OPTS		:= -L. -lphilo

NAME		:= philo
MAIN		:= philo_main.c
HEADER		:= philo_head.h
ARCHIVE		:= libphilo.a

# ---------------------------------------------------------------------------- #
UTLS_DIR := ft_utils/

SRCS_DIR := srcs/
SRCS_LST := args_pars.c err_utils.c philo_actvts.c table_utils.c \
	ft_utils/ft_free.c ft_utils/ft_isalnum.c ft_utils/ft_isalpha.c ft_utils/ft_isspace.c ft_utils/ft_split.c \
	ft_utils/ft_tolower.c ft_utils/ft_toupper.c ft_utils/ft_custom_atoll.c ft_utils/ft_bzero.c ft_utils/ft_calloc.c \
	ft_utils/ft_strcpy.c ft_utils/ft_strdup.c ft_utils/ft_strjoin.c ft_utils/ft_strlen.c ft_utils/ft_strtrim.c \
	ft_utils/ft_isascii.c ft_utils/ft_isdigit.c ft_utils/ft_isprint.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title

all: clear title ${NAME}

${NAME}: ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${ARCHIVE} ${OBJS}
	@echo "${BLU}Archive file ${GRA}${ARCHIVE}${BLU} created successfully${NNN}\n"
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${NAME}
	@echo "${GRN}Executable ${GRA}${NAME}${GRN} created successfully${NNN} :)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NNN}"

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}${UTLS_DIR}

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${GRA}${NAME}${RED}\t\tobject files have been deleted${NNN}"

fclean: clean
	@rm -f ${ARCHIVE}
	@echo "${GRA}${ARCHIVE}${RED}\tarchive file ${GRA}${NAME}${RED}\thas been deleted${NNN}"
	@rm -f ${NAME}
	@echo "${GRA}${NAME}${RED}\t\texecutable file has been deleted${NNN}"

re: fclean all

clear:
	@echo -e "\033[2J\033[3J\033[1:1H"

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- # 
