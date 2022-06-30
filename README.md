## Everything that you need to know to configure this project

This project works fine in Visual Studio Code with clangd, CMake and git.

### [Clang Format hook](https://github.com/barisione/clang-format-hooks)

To configure clangd you need to pull clang-format-hooks submodule and register it:

```sh
git submodule update --init
cd clang-format-hooks && ./git-pre-commit-format install
```

### [Clangd](https://clangd.llvm.org/installation)

To clangd understand your source code you need to have `compile_commands.json` in root of your project. You can generate this file by building project:

```sh
mkdir build && cd build
cmake ..
cmake --build . -j
cd ..
ln -s build/compile_commands.json .
```

If you have PostgreSQL installed in non-default directory as I have, you need to specify it e.g. `-DPostgreSQL_INCLUDE_DIR=/usr/pgsql-14/include` key:

```sh
...
cmake -DPostgreSQL_INCLUDE_DIR=/usr/pgsql-14/include ..
...
```

### clang

To build project with Clang export CC and CXX variables

```sh
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
```
