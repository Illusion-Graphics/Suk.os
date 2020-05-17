SRC		:= $(wildcard gpio/*.cpp) $(wildcard uart/*.cpp) $(wildcard dma/*.cpp)
OBJ		:= $(SRC:.cpp=.o)

all: $(OBJ)

%.o: %.cpp
	$(CPPCLANG) --target=$(ARCH) $(CPPFLAGS) -c $< -o $(BUILD_DIR)$(notdir $@)