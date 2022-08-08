####################################
#
#		GLOBAL INFORMATIONS
#
####################################

NAME		= release/openlibft.a
CC			= gcc
FASM		= fasm
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Isrc/includes -O3 -fPIE 
SRC_C	 	= $(wildcard src/**/*.c)
SRC_S		= $(wildcard src/**/*.asm)
OBJ_C	 	= $(SRC_C:.c=.o)
OBJ_S		= $(SRC_S:.asm=.o)
NUM_CF		= $(shell ls -l src/**/*.c 	 | wc -l)
NUM_SF		= $(shell ls -l src/**/*.asm | wc -l)
ISA			= $(shell $(FASM) ISA/check.asm > /dev/null && ISA/check | rev | cut -c 2- | rev && rm ISA/check)
CFLAGS		+= -D$(subst /, -D , $(ISA))
cnt			= 1

##################################
#
#			COLOR
#
##################################

GREEN 	= \033[38;5;82m
RED   	= \033[38;5;196m
YELLOW 	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;207m
LBLUE	= \033[38;5;45m
BLUE	= \033[38;5;26m
RESET 	= \033[00m

##################################
#
#			DEBUG MODE
#
##################################

ifdef DEBUG
CFLAGS += -g3
endif

define ascii_art

 ██████╗ ██████╗ ███████╗███╗   ██╗██╗     ██╗██████╗ ███████╗████████╗
██╔═══██╗██╔══██╗██╔════╝████╗  ██║██║     ██║██╔══██╗██╔════╝╚══██╔══╝
██║   ██║██████╔╝█████╗  ██╔██╗ ██║██║     ██║██████╔╝█████╗     ██║
██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║     ██║██╔══██╗██╔══╝     ██║
╚██████╔╝██║     ███████╗██║ ╚████║███████╗██║██████╔╝██║        ██║
 ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
               OpenLibft Created by 42 Angouleme
                  [ Version : 0.0.1 (alpha) ] 


endef
export ascii_art

all: BANNER $(NAME)

BANNER:
	@printf "$(LBLUE)$$ascii_art$(RESET)"

%.o: %.c
	@printf "$(LBLUE)[$(PURPLE)+$(LBLUE)] compile... $(GREEN)$<$(LBLUE) [$(GREEN)$(cnt)$(YELLOW)/$(NUM_CF)$(LBLUE)]                             		\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	$(eval cnt=$(shell echo $$(($(cnt)+1))))

%.o: %.asm
	@printf "$(LBLUE)[$(PURPLE)+$(LBLUE)] compile Assembly... $(GREEN)$<$(LBLUE) [$(GREEN)$(cnt)$(YELLOW)/$(NUM_SF)$(LBLUE)]                             \r"
	@$(FASM) $< $@ > /dev/null
	$(eval cnt=$(shell echo $$(($(cnt)+1))))

$(NAME): $(OBJ_C) $(OBJ_S)
	@printf "\n"
	@mkdir -p release
	@ar rcs $(NAME) $(OBJ_C) $(OBJ_S)
	@printf "$(LBLUE)[$(PURPLE)+$(LBLUE)] Release has been builded release/openlibft.a !$(RESET)"

clean:
	@rm -rf $(OBJ_C) $(OBJ_S)

fclean: clean
	@rm -rf $(NAME)

re: BANNER fclean $(NAME)

.PHONY: all shared clean fclean re
