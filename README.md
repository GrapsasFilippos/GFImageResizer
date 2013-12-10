(My new toy). GFImageResizer resizes an image file to various resolutions.

## Linux

### Compile

`cd path/to/GFImageResizer/`  
`make`

Other compile commands:

* `make`, `make build`, `make build-release` : for release build,
* `make build-debug` : for debug build,
* `make build-all` : for release and debug builds.

### Run

Double click `GFImageResizer/bin/*/GFImageResizer`.

### Install

(Need permission to copy file `GFImageResizer/bin/release/GFImageResizer` to `/usr/bin/`).  
`make install`

### Uninstall

(Need permission to remove `/usr/bin/GFImageResizer`).  
`make uninstall`

## Windows

### Compile

`cd path\to\GFImageResizer\`  
`qmake`  
`make release`

From `qt\installation\dir\Qt5.1.1\5.1.1\mingw48_32\bin` copy the following files to `GFImageResizer\bin\release\`:

* `icudt51.dll`
* `icuin51.dll`
* `icuuc51.dll`
* `libgcc_s_dw2-1.dll`
* `libstdc++-6.dll`
* `libwinpthread-1.dll`
* `Qt5Core.dll`
* `Qt5Gui.dll`
* `Qt5Widgets.dll`

From `qt\installation\dir\Qt5.1.1\5.1.1\mingw48_32\plugins` copy the following directories to `GFImageResizer\bin\release\`:

* `imageformats\`
* `platforms\`

### Run

Double click `GFImageResizer\bin\release\GFImageResizer.exe`.

### Compile Windows installer

(After compiled successfully).

`cd GFImageResizer\NSIS`  
`makensis.exe GFImageResizer.nsis`