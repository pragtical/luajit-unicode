# LuaJIT Unicode for Windows

This is an adaptation of https://github.com/Lekensteyn/lua-unicode to work
under LuaJIT and for the purpose of **Pragtical Code Editor**.

## Changes

1. Copy `src/utf8_wrappers.h` and  `src/utf8_wrappers.c` to LuaJIT `src` dir.
2. Patch `src/luaconf.h` to add the following in the *Local configuration* part:

```c
#if defined(LUA_LIB) && (defined(lib_aux_c) || defined(lib_io_c) || \
     defined(lib_package_c) || defined(lib_os_c))
#include "utf8_wrappers.h"
#endif
```

3. Patch `src/Makefile` to compile `src/utf8_wrappers.c`:

```diff
-	 lib_buffer.o
+	 lib_buffer.o utf8_wrappers.o
```
