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
NNN  := \033[0m
RED := \033[31m
GRN := \033[32m
YEL := \033[33m
BLU := \033[34m
MGN := \033[35m
CYN := \033[36m
GRA := \033[37m

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

\t\t\t\t\t\t${GRA} - Created By ${BLU}The-Intruder${NNN}
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
SRCS_DIR := srcs/
SRCS_LST := 
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re intro title

all: title ${NAME}

${NAME}: intro ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${ARCHIVE} ${OBJS}
	@echo "${BLU}Archive file ${GRA}${ARCHIVE}${BLU} created successfully${NNN}\n"
	@${CC} ${CC_FLAGS} ${CC_OPTS} -o ${NAME}
	@echo "${BLU}Executable ${GRA}${NAME}${BLU} created successfully${NNN} :)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NNN}"

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${GRA}${NAME}${RED}\tobject files have been deleted${NNN}"
	@echo "\n"

fclean: clean
	@rm -f ${ARCHIVE}
	@echo "${GRA}${ARCHIVE}${RED}\tarchive file ${GRA}${NAME}${RED}\t\thas been deleted${NNN}\n"
	@rm -f ${NAME}
	@echo "${GRA}${NAME}${RED}\texecutable file has been deleted${NNN}"

re: fclean all

intro:
	@echo "\n${YEL}Entering ${GRA}${NAME}${YEL}'s makefile"
	@echo "----------------------------${NNN}"

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- #