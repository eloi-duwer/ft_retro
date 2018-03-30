NAME = ft_retro

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

debug: fclean
debug: CXXFLAGS = -DDEBUG -g -Wall -Wextra
debug: all


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

re: fclean all
