NAME = ft_retro

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

SRCS =	main.cpp \
		AObject.cpp \
		Enemy.cpp \
		Map.cpp \
		Player.cpp \
		Missile.cpp

OBJS = $(SRCS:.cpp=.o)

LIB = ncurses

all: $(NAME)

debug: fclean
debug: CXXFLAGS = -DDEBUG -g -Wall -Wextra
debug: all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS) -l$(LIB)

re: fclean all
