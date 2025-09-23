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
