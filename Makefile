TARGET=sge
OBJS= Color.o \
	Content.o \
	Game.o \
	Rectangle.o \
	Texture2D.o \
	Timer.o \
	Vector2.o \
	Vector3.o \
	Window.o \
	Camera.o \
	Matrix4.o \
	Vector4.o \
	SOIL/image_helper.o \
	SOIL/stb_image_aug.o  \
	SOIL/image_DXT.o \
	SOIL/SOIL.o

BUILD=build
CXXFLAGS= -std=c++11 -Wall \
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
	-Wdouble-promotion


CFLAGS=

HEADERS=$(shell find . -not -path "./$(BUILD)/*" -name '*.h')
DOC_CONFIG=doxygen_config

all:
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/SOIL
	$(MAKE) $(TARGET)

dist: all
	rm -f $(patsubst %, $(BUILD)/%, $(OBJS))
	rm -rf $(BUILD)/SOIL
	mkdir -p $(BUILD)/include
	mkdir -p $(BUILD)/include/SOIL
	$(MAKE) headers


$(TARGET): $(patsubst %, $(BUILD)/%, $(OBJS))
	$(AR) rvs $(BUILD)/lib$@.a $^

$(BUILD)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

headers: $(patsubst %, $(BUILD)/include/%, $(HEADERS))

$(BUILD)/include/%.h: %.h
	cp $< $@

doc:
	mkdir -p $(BUILD)/doc
	doxygen $(DOC_CONFIG)


clean:
	rm -rf $(BUILD)

