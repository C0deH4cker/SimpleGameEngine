SRC := src
BUILD := build

LIB := $(BUILD)/libsge.a

GLFW := glfw
LIBGLFW := $(GLFW)/src/libglfw3.a

SOIL := SOIL
SOILBUILD := $(BUILD)/SOIL
SOILSRCS := $(wildcard $(SOIL)/*.c)
SOILOBJS := $(notdir $(SOILSRCS:.c=.o))
SOILBUILT := $(addprefix $(SOILBUILD)/, $(SOILOBJS))

SRCS := $(wildcard $(SRC)/*.cpp)
OBJS := $(notdir $(SRCS:.cpp=.o))
BUILT := $(addprefix $(BUILD)/, $(OBJS))

OBJS += $(SOILOBJS)
BUILT += $(SOILBUILT)

DIRS := $(BUILD) $(SOILBUILD)

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

override CXXFLAGS += -std=c++11 -I. -I./include -I./$(GLFW)/include

DOC_CONFIG := doxygen_config


all: $(LIB)

$(DIRS):
	mkdir -p $@

$(LIBGLFW):
	cmake $(GLFW)
	cmake --build $(GLFW) -- glfw

glfwobjs: $(LIBGLFW) | $(BUILD)
	$(eval ARCHIVED := $(filter %.o, $(shell $(AR) -t $<)))
	$(AR) -x $< $(ARCHIVED)
	$(AR) -cruS $(LIB) $(ARCHIVED)
	$(RM) $(ARCHIVED)

$(LIB): $(BUILT) | glfwobjs
	$(AR) -crus $@ $?

$(SOILBUILD)/%.o: $(SOIL)/%.c | $(SOILBUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

doc: $(DOC_CONFIG)
	mkdir -p $(BUILD)/doc
	doxygen $<

clean:
	rm -rf $(BUILD)

.PHONY: all clean doc glfw glfwobjs

