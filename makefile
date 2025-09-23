# Macros

DIR = src

all: $(DIR)

$(DIR):
	make -C $@

clean:
	
	make -C $(DIR) clean
	@echo "Project cleaned."

.PHONY: all clean $(DIR)
