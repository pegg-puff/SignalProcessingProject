CXX = g++
CXXFLAGS = -std=c++17 -O2

TARGET = signal_proc
SRC = src/main.cpp src/signal_utils.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
