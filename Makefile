#* TARGET *#
TARGET = breakout

#*SOURCE FILES *#
FILES = main.cpp Game.cpp TextureManager.cpp Player.cpp \
	GameObject.cpp InputHandling.cpp MainMenu.cpp PlayState.cpp \
	StateControl.cpp Ball.cpp
		
SRC = $(addprefix src/, $(FILES))

#* OBJECT DIRECTORY *#
OBJ_DIR = obj

#* OBJECT FILES *#
OBJS = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

#* FLAGS *#
FLAGS = -Wall -Wextra -Werror
SDL = -lmingw32 -lSDL2main -lSDL2 
TTF = -lSDL2_ttf 
IMG = -lSDL2_image

#* HEADER FILES *#
SDL_INCLUDE = include/
INCLUDE = headers/
#* LIBRARY *#
LIB = lib/

#* DELETE *#
DEL = rm -f

all: $(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	g++ $(FLAGS) -c -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(IMG) $(TTF) $(SDL) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	g++ $(FLAGS) -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(OBJS) $(IMG) $(TTF) $(SDL) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all