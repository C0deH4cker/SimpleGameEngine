SRC := src
BUILD := build

LIBNAME := libsge.a
LIB := $(BUILD)/$(LIBNAME)
TARNAME := sge.tgz
TARBALL := $(BUILD)/$(TARNAME)
TARCONTENTS := $(TARNAME) $(LIBNAME) include

GLFW := glfw
LIBGLFW := $(BUILD)/$(GLFW)/src/libglfw3.a

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

DIRS := $(BUILD) $(SOILBUILD) $(BUILD)/include
HEADERS := $(wildcard include/*.h) $(GLFW)/include/GLFW

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
	-Wno-reorder \
	-Wno-unknown-pragmas

override CXXFLAGS += -std=c++11 -I. -I./include -I./$(GLFW)/include

DOC_CONFIG := doxygen_config


all: $(LIB) headers

dist: $(TARBALL)

docdist: $(LIB) headers doc
	cd $(BUILD) && tar czf $(TARCONTENTS) doc

$(TARBALL): $(LIB) headers
	cd $(BUILD) && tar czf $(TARCONTENTS)

headers: $(HEADERS) | $(BUILD) $(BUILD)/include
	cp -r $^ $(BUILD)/include
	mkdir -p $(BUILD)/include/SOIL
	cp $(wildcard $(SOIL)/*.h) $(BUILD)/include/SOIL

$(DIRS):
	mkdir -p $@

$(LIBGLFW):
	mkdir -p $(BUILD)/$(GLFW)
	cd $(BUILD)/$(GLFW); cmake $(CMAKEFLAGS) ../../$(GLFW); make glfw

glfwobjs: $(LIBGLFW) | $(BUILD)
	$(eval ARCHIVED := $(filter %.o %.obj, $(shell $(AR) -t $<)))
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

.PHONY: all clean dist doc docdist glfwobjs headers

