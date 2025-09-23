# Macros

DIR = src

all: $(DIR)

$(DIR):
	make -C $@

install:
	make -C $(DIR) install

uninstall:
	make -C $(DIR) uninstall

clean:
	
	make -C $(DIR) clean
	@echo "Project cleaned."

.PHONY: all clean $(DIR)
