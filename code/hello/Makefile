BUILD_DIR := ./bin

hello.build:
	gcc ./hello.c -o $(BUILD_DIR)/hello

hello.run:
	@$(BUILD_DIR)/hello

input.build:
	gcc ./input.c -o $(BUILD_DIR)/input

input.run:
	@$(BUILD_DIR)/input

clean:
	rm ./bin/*

.PHONY: clean hello.build hello.run input.build input.run
