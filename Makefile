###---------------------------------MAKEFILE------------------------------###
###-----------------------------------------------------------------------###
###              #       #######     				     /\               ###
###             ###      ##    ##  				       _(  )_             ###
###            ## ##     ##    ## 					 (`_\\//_`)           ###
###           #######    #######     				  `={==}=`            ###
###          ###   ###   ##        					  .->/\<-.            ###
###         ###     ###  ##           				   "`\/`"             ###
###-----------------------------------------------------------------------###
###Made by André-Paul Grenon--#useraddress: agrenon@student.42quebec.com--###
#-------------------------------------------------------------------------###
###THIS PROJECT: SO_LONG 
NAME = so_long#(Nom de L'exécutable)

###----------------####1.  VARIABLES####----------------------------------###

### Fichiers .c
SRCS_C	= so_long.c \
		  ft_image_put.c \

#Place bonus files:
SRCS_BONUS_C	=

#Place header:
INCLUDE_H	= so_long.h 

#Crée les fichiers objets à partir des fichiers .c:
OBJS_O	= $(SRCS:.c=.o)

###Préfixes:
DIR			= 
OBJS_DIR	= objs/
B_DIR		= bonus/ 
INCLUDE_DIR = include/
LIBFT		= libft/

### Répertoires:
SRCS		= $(addprefix $(DIR), $(SRCS_C))
B_SRCS		= $(addprefix $(B_DIR), $(SRCS_BONUS_C))
OBJS		= $(addprefix $(OBJS_DIR),$(OBJS_O))
INCLUDE		= $(addprefix $(INCLUDE_DIR), $(INCLUDE_H))

### Compilation, archivage et autres fonctions
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit 
OEXEC		= -o $(NAME)

RM			= rm -rf
NORM		= norminette

### Couleurs et fonctionnalités texte:

END         = \033[0m
BOLD        = \033[1m
ITALIC      = \033[3m
URL         = \033[4m
BLINK       = \033[5m
BLINK2      = \033[6m
SELECTED    = \033[7m

BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
VIOLET      = \033[35m
BEIGE       = \033[36m
WHITE       = \033[37m

###-----------------###-2. REGLES ##-------------------------------------###

all:	$(INCLUDE) obj $(OBJS) $(NAME)

$(OBJS_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -Imlx -o $@ -c $<

$(NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(OEXEC) 
			@echo "\n$(BOLD)$(GREEN)Compilation de l'exécutable $(NAME) effectuée avec succès!\n" 
		@echo "$(BLUE)$(BOLD)             8" && echo "           .d8b." && echo "       _.d8888888b._" && echo "     .88888888888888b." && echo "    d88888888888888888b" && echo "    8888888888888888888" && echo "    Y88888888888888888P" && echo "     'Y8888888888888P'" && echo "   _..._ 'Y88888P' _..._" && echo " .d88888b. Y888P .d88888b." && echo "d888888888b 888 d88888888b" && echo "888P  'Y8888888888P'  Y888" && echo " b8b    Y88888888P    d8Y" && echo "   \   #############  /" && echo "         dP d8b Yb" && echo "     Ob=dP d888b Yb=dO" && echo "       ¨  O88888O  ¨" && echo "           'Y8P'" &&echo "             '"

obj:
	@mkdir -p $(OBJS_DIR)
#	@echo "$(GREEN)$(BOLD)\nRépertoire pour objets créé avec succès!\n$(END)"

libft:
	@make -sC $(LIBFT)
## @echo "$(GREEN)$(BOLD)\nLibrairie de la Libft créée avec succès ! "

clean:
		$(RM) $(OBJS) $(OBJS_DIR)
		@echo "\n $(RED)$(ITALIC)Les fichiers .o sont correctement supprimés\n $(END)"

fclean: clean 
		$(RM) ${NAME}
		#@make fclean -sC $(LIBFT)
		@echo "$(BOLD)$(RED)\nATTENTION! Purge effectuée.\n$(END)"

re : 	fclean 
		@make

.PHONY: fclean all make clean libft obj

spliff:
		@whoami | awk '{print "${VIOLET}${BOLD}\n"$$0"${END} veut se défoncer la gueule ?\n"}'
		@echo "                      ("
		@echo "                     (  ) ("
		@echo "                      )    )"
		@echo "         |||||||     (  ( ("
		@echo "        ( O   O )        )"
		@echo " ____oOO___(_)___OOo___${RED}_(${END}"
		@echo "(______________________${RED}${BOLD}_)\n${GREEN} ${BOLD}"
		@date +"%T" | awk -F ":" ' BEGIN {TIM=980}{POT=$$1*60+$$2} {if(TIM > POT) {print (TIM-(POT))/60 "${END} heures restantes\n"} if(TIM >= POT+60){print "${YELLOW}PATIENCE....\n"} if(TIM < POT+60 && TIM > POT){print "${RED}${BOLD}ALLUMAGE IMMINENT\n" }if (TIM < POT){print "${RED}4:20 MANQUÉ !\n " } }END{}'

jr: 
	@echo "   ,;;;;;;;;;;;."
	@echo " ,;;;;;;;;;'''')"
	@echo ",;;;;;;;;'    (${RED}@${END})               ,',"
	@echo ";;;;;;;;')       \               ,"
	@echo ";;;;;;;;_}       _)            ',"
	@echo ";;;;;;'        _;_______________"
	@echo "';;;;;        ;_.---------------${RED}'${END}"
	@echo "  ';;;        )"
	@echo "    ';.      l"
