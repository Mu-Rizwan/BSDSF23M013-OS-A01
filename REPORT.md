(Feature-3 Questions)1. Compare the Makefile from Part 2 and Part 3. What are the key differences?

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

Yes, you see the symbols directly inside the executable. This means the functions were copied from the library into the program at build time. That’s how static linking works: the code from the library becomes part of the final executable, which is why the file size is larger than when using a dynamic library
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
