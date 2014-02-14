ROOT := $(abspath .)
SRC := src
BUILD := build

GLFW := glfw
LIBGLFW := $(GLFW)/src/libglfw3.a
GLFWOBJS := $(BUILD)/glfwobjs

LIB := $(BUILD)/libsge.a
SRCS := $(wildcard $(SRC)/*.cpp)
OBJS := $(notdir $(SRCS:.cpp=.o))
BUILDOBJS := $(addprefix $(BUILD)/, $(OBJS))

CXXFLAGS := -Wall \
	-Wextra \
	-Wwrite-strings \
	-Winit-self \
	-Wcast-align \
	-Wcast-qual \
	-Wpointer-arith \
	-Wstrict-aliasing \
	-Wformat=2 \
	-Wmissing-declarations \
	-Wmissing-include-dirs \
	-Wno-unused-parameter \
	-Wuninitialized \
	-Wno-reorder

override CXXFLAGS += -std=c++11 -I./include -I./$(GLFW)/include -I/opt/local/include

DOC_CONFIG := doxygen_config


all: $(LIB)

$(BUILD):
	mkdir -p $(BUILD)

$(GLFW):
	git submodule update --init

$(LIBGLFW): $(GLFW)
	cmake $<
	cmake --build $<

glfwobjs: $(LIBGLFW) | $(BUILD)
	$(eval ARCHIVED := $(filter %.o, $(shell $(AR) -t $<)))
	$(AR) -x $< $(ARCHIVED)
	$(AR) -cruS $(LIB) $(ARCHIVED)
	$(RM) $(ARCHIVED)

$(LIB)(%o): $(BUILD)/%o
	$(AR) -cruS $@ $<

$(LIB): glfwobjs $(LIB)($(OBJS))
	-ranlib $@

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

doc: $(DOC_CONFIG)
	mkdir -p $(BUILD)/doc
	doxygen $<

update: gitupdate all

gitupdate:
	git pull
	git submodule update --init

clean:
	rm -rf $(BUILD)

.PHONY: all clean doc gitupdate glfwobjs update
