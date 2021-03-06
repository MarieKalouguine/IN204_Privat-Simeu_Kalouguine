FLAGS = -Wall -std=c++11

SRCPATH=./src/
OBJPATH=./obj/
TESTPATH=./tests/
OBJFILES = $(addprefix $(OBJPATH), raytracing.o math_objects.o shape.o color.o light_source.o camera.o environment.o initialization.o tinyxml2.o)
HEADERS = $(addprefix $(SRCPATH), math_objects.hpp shape.hpp light_source.hpp environment.hpp camera.hpp color.hpp tinyxml2.hpp)

default: raytracing

all: raytracing test_xml test_display

raytracing : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

test_xml : $(OBJPATH)tinyxml2.o $(OBJPATH)test_xml.o
	g++ $(FLAGS) -o $@ $^

test_display : $(TESTPATH)test_display.cpp
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)test_%.o : $(TESTPATH)test_%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) $(SRCPATH)*.ppm *.ppm core raytracing test_*
