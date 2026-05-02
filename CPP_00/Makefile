# This Makefile has for singul use case to call the fclean of each other Makefile
# And then push this directory (that is the parent) to GitHub

SUBDIRS = ex00 \
			ex01 \
			ex02

all:
	@echo "Use 'make fclean' to clean all subdirectories and then \
	'make push' from the parent directory to push to GitHub"

fclean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir fclean; \
	done

push: fclean
	@git add .
	@git commit -m "Cleaned and prepared for push"
	@git push origin main