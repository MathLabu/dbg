# dbg

Opt-In style header-only library to use print debug macro.

## Compilation

```
mkdir build
cd build
cmake ..
make install
```

## Use

In your `CMakeList.txt` application:

```
find_package(dbg REQUIRED)

add_executable(application
	main.cpp 
)

target_link_libraries(application
	dbg::on #or dbg::off to disable print
)
```


