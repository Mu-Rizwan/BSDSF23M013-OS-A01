📑 REPORT.md (Feature-2 answers)
1. Explain the linking rule in this part's Makefile:

$(TARGET): $(OBJECTS)

In this Makefile, the executable target (e.g., bin/client) depends on all the compiled object files (main.o, mystrfunctions.o, myfilefunctions.o).
When I run make, if any .o file is newer than the executable (or the executable does not exist yet), make will re-link all the objects into the final binary.

This is different from linking against a library, because here the linker directly takes every .o file and copies the code into the executable. In later parts, when I use a static or dynamic library, the linker will instead just connect to the library as a whole, rather than each individual .o.

2. What is a git tag and why is it useful? Difference between simple and annotated tags.

A git tag is like a permanent label on a specific commit. It marks a snapshot of the project as important (for example, version 1.0). Tags are useful because they let me easily go back to a stable version, publish releases, or share exact versions of my project with others.

Simple tag: just a lightweight pointer to a commit (basically like a named bookmark).

Annotated tag: stores extra information like the tagger’s name, date, and a message. Annotated tags are preferred for releases because they carry history and documentation.

3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?

A GitHub Release is a formal way to package a version of the project for others. It shows which tag/version this release corresponds to and provides release notes.

📑 REPORT.md (Feature-3 Questions)
1. Compare the Makefile from Part 2 and Part 3. What are the key differences?

In Part 2, the linking rule was:

$(TARGET): $(OBJECTS)
    gcc … -o $(TARGET) $(OBJECTS)


This compiled and linked all .o files directly.

In Part 3, I first created a static library:

ar rcs libmyutils.a $(OBJS)


and then linked main.o against -lmyutils with -L../lib.
So the difference is: instead of passing every .o to the linker, we grouped them into a reusable library, which makes the project more scalable.

2. What is the purpose of the ar command? Why is ranlib often used?

ar (archiver) bundles multiple .o files into a single .a archive (static library).

ranlib generates or updates the index of the archive, so the linker can quickly find symbols. On Linux, ar rcs already does this, so ranlib is often not needed explicitly, but on some systems it’s still used.

3. When you run nm on client_static, are the symbols for mystrlen, etc., present? What does this tell you?

Yes, you see the symbols directly inside the executable. This means the functions were copied from the library into the program at build time. That’s how static linking works: the code from the library becomes part of the final executable, which is why the file size is larger than when using a dynamic library.

📑 REPORT.md (Feature-4 Questions)
1. What is Position-Independent Code (-fPIC) and why is it required?

Position-Independent Code (PIC) means the compiled code does not assume it will always be loaded at a fixed memory address. Instead, all addresses are calculated relative to the current instruction pointer. This is essential for shared libraries because the OS can load them at different addresses in different programs. Without -fPIC, the library might fail to load or cause relocation errors.

2. Explain the difference in file size between static and dynamic clients.

Static client: contains the actual machine code of all the linked functions from the library. That’s why the executable is larger.

Dynamic client: only contains references to the .so. At runtime, the code is loaded separately into memory, so the executable is much smaller.

3. What is LD_LIBRARY_PATH and why was it necessary?

LD_LIBRARY_PATH is an environment variable that tells the dynamic loader (ld.so) where to search for shared libraries before looking in the system directories.
When I built client_dynamic, the loader didn’t know where to find libmyutils.so. By exporting LD_LIBRARY_PATH=./lib, I told the OS to also search in my project’s lib/ folder. This shows how the dynamic loader resolves shared libraries at runtime.

📑 REPORT.md (Feature-5 Questions)
1. Man Page Content

The man page must include at least the following sections:

NAME: program name + one-line description.

SYNOPSIS: how to run it.

DESCRIPTION: details of what the program does.

AUTHOR: your name and email.

2. Purpose of the install target

The install target simulates how Linux software is typically installed system-wide. It copies the compiled binary into /usr/local/bin (so it’s available on the PATH) and installs the man page into /usr/local/share/man/man1/.

3. Verifying Installation

Run client from any directory → proves the binary is on the PATH.

Run man client → proves the documentation is correctly installed.

Attaching binaries (like client) is important because it lets users download and run the program directly without compiling the source code themselves. This is closer to how real software is distributed: end-users usually want the program ready-to-use, not just the source.
