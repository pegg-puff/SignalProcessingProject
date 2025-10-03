CXX = g++
CXXFLAGS = -std=c++17 -O2
LIBS = -lfftw3f

TARGET = signal_proc
SRC = src/main.cpp src/signal_utils.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
