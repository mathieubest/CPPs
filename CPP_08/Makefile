# This Makefile has for single use case to call the fclean of each other Makefile
# And then push this directory (that is the parent) to GitHub

MAKEFLAGS += -s

SUBDIRS = ex00 \
            ex01 \
            ex02

all:
	@echo "Use 'make fclean' to clean all subdirectories" > /dev/null
	@echo "Use 'make push' to clean all subdirectories and push to GitHub" > /dev/null

fclean:
	@for dir in $(SUBDIRS); do \
        echo "Cleaning $$dir"; \
        $(MAKE) -C $$dir fclean > /dev/null; \
    done

push: fclean
	@set -e; \
    git add .; \
    if [ -z "$(MSG)" ]; then \
        read -p "Enter commit message: " MSG; \
        if [ -z "$$MSG" ]; then \
            echo "No commit message provided. Exiting."; \
            exit 1; \
        fi; \
    fi; \
    git commit -m "$$MSG"; \
    git push