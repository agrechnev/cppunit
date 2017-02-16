CXX = g++
CXXFLAGS = -g
LIBS = -lcppunit
SRCS = CBasicMath.cpp TestBasicMath.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = test1

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

.cpp.o: 
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJS)