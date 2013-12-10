.PHONY: build build-all build-release build-debug install uninstall

build: build-release

build-release:
	cd ./src/ && qmake && make release

build-debug:
	cd ./src/ && qmake && make debug

build-all:
	cd ./src/ && qmake && make all

install:
	cp ./bin/release/GFImageResizer /usr/bin

uninstall:
	rm -f /usr/bin/GFImageResizer

