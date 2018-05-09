CC = clang++
CFLAGS = -g -Wall -std=c++11 -Qunused-arguments
DEPS = imgMgr.h myUsage.h myString.cpp
OPENCV = `pkg-config --cflags --libs opencv` 
#-lopencv_imgcodecs
OBJS = main.o imgMgr.o
TARGET = myImg
##############
# Executable #
##############
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(OPENCV)
	strip $@
##############
# Obj files  #
##############
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(OPENCV)
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
	rm -rf *.dSYM
