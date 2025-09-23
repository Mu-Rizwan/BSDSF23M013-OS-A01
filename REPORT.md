### 1. Explain the linking rule in this part's Makefile:

`$(TARGET): $(OBJECTS)`

In this Makefile, the executable target (e.g., `bin/client`) depends on all the compiled object files (`main.o`, `mystrfunctions.o`, `myfilefunctions.o`).
When I run `make`, if any `.o` file is newer than the executable (or the executable does not exist yet), `make` will re-link all the objects into the final binary.

This is different from linking against a library, because here the linker directly takes every `.o` file and copies the code into the executable. In later parts, when I use a static or dynamic library, the linker will instead just connect to the library as a whole, rather than each individual `.o`.

---

### 2. What is a git tag and why is it useful? Difference between simple and annotated tags.

A **git tag** is like a permanent label on a specific commit. It marks a snapshot of the project as important (for example, version 1.0). Tags are useful because they let me easily go back to a stable version, publish releases, or share exact versions of my project with others.

* **Simple tag:** just a lightweight pointer to a commit (basically like a named bookmark).
* **Annotated tag:** stores extra information like the tagger’s name, date, and a message. Annotated tags are preferred for releases because they carry history and documentation.

---

### 3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?

A GitHub Release is a formal way to package a version of the project for others. It shows which tag/version this release corresponds to and provides release notes.

Attaching binaries (like `client`) is important because it lets users download and run the program directly without compiling the source code themselves. This is closer to how real software is distributed: end-users usually want the program ready-to-use, not just the source.

