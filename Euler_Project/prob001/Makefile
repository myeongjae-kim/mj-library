.SUFFIXES : .cpp .o

OBJECTS = main.o

SRCS = $(OBJECTS:.o=.cpp)

CXXFLAGS = -g -c -std=c++11

TARGET = a.out

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS); ./$(TARGET)

.cpp.o :
	$(CXX) $(CXXFLAGS) $<

clean : 
	rm $(OBJECTS); rm $(TARGET)

# Dependency example
#
# CMyString.o : CMyString.h CMyString.cpp
# StringCtrlSample.o : CMyString.h StringCtrlSample.cpp

dep : 
	g++ -M $(SRCS)
