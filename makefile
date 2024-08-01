build:
	gcc -g `pkg-config --cflags gtk4` ${SOURCE} -o ${OUTPUT} `pkg-config --libs gtk4`

SOURCE = ./src/*.c

OUTPUT = ./bin/app.out