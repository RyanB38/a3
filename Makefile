CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = build
TARGET = TestDriverParkingMeter

# Build all sources except the alternate test driver with its own main
SOURCES = $(filter-out $(SRC_DIR)/TestDriverParkingMeter1.cc, $(wildcard $(SRC_DIR)/*.cc))
BUILDS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SOURCES))

$(TARGET): $(BUILDS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

