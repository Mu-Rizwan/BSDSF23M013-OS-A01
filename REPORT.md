1. What is Position-Independent Code (-fPIC) and why is it required?

Position-Independent Code (PIC) means the compiled code does not assume it will always be loaded at a fixed memory address. Instead, all addresses are calculated relative to the current instruction pointer. This is essential for shared libraries because the OS can load them at different addresses in different programs. Without -fPIC, the library might fail to load or cause relocation errors.

2. Explain the difference in file size between static and dynamic clients.

Static client: contains the actual machine code of all the linked functions from the library. That’s why the executable is larger.

Dynamic client: only contains references to the .so. At runtime, the code is loaded separately into memory, so the executable is much smaller.

3. What is LD_LIBRARY_PATH and why was it necessary?

LD_LIBRARY_PATH is an environment variable that tells the dynamic loader (ld.so) where to search for shared libraries before looking in the system directories.
When I built client_dynamic, the loader didn’t know where to find libmyutils.so. By exporting LD_LIBRARY_PATH=./lib, I told the OS to also search in my project’s lib/ folder. This shows how the dynamic loader resolves shared libraries at runtime.
