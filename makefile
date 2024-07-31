all: build run

build:
	gcc `pkg-config --cflags gtk4`  ${SOURCE} -o ${OUTPUT} `pkg-config --libs gtk4`

run:
	./bin/app.out

SOURCE = ./src/*.c

OUTPUT = ./bin/app.out