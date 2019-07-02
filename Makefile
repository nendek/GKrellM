NAME = ft_gkrellm

SRCDIR = srcs

SRC_NAME =	MonitorModule.cpp \
			NcursesView.cpp \
			SfmlView.cpp \
			Monitor.cpp \
			main.cpp

LIBS = -l ncurses -L ~/.brew/lib -l sfml-graphics -l sfml-window -l sfml-system
RPATH = -Wl,-rpath,$$HOME/.brew/lib

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -o $(NAME) $(OBJ) $(LIBS) $(RPATH)

$(OBJ_PATH)/%.o: $(SRCDIR)/%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	clang++ -c $< $(FLAGS) -I includes/ -I ~/.brew/Cellar/sfml/2.5.1/include -o $@

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
