BUILD_DIR = build
EXEC_PROG = matrixProject
EXEC_TESTS = matrixTests

.PHOPY: all build test clean run rebuild

all: build

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cmake --build $(BUILD_DIR)

test: build
		cd $(BUILD_DIR) && ./$(EXEC_TESTS) && ./vectorTests

clean:
	rm -rf $(BUILD_DIR)

run: build
		cd $(BUILD_DIR) && ./$(EXEC_PROG)

rebuild: clean build
