# Name of the executable
TARGET = main

# C++ compiler
CXX = g++

# Source files
SRCS = main.cpp \
       Employee.cpp \
       Manager.cpp \
       Assistant.cpp \
       Operator.cpp \
       Product.cpp \
       Clothes.cpp \
       Disk.cpp \
       Order.cpp \
       Implementation.cpp

# Rule for compiling all .cpp files into the final executable
$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS)

# Clean the executable
clean:
	rm -f $(TARGET)
