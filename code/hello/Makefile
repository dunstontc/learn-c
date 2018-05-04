BUILD_DIR := ./bin
MAIN := hello

build:
	gcc ./$(MAIN).c -o $(BUILD_DIR)/$(MAIN)

run:
	@$(BUILD_DIR)/$(MAIN)

clean:
	rm ./bin/*

.PHONY: clean build run
