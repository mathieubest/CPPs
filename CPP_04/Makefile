# This Makefile has for single use case to call the fclean of each other Makefile
# And then push this directory (that is the parent) to GitHub


SUBDIRS = ex00 \
			ex01 \
			ex02 \
			ex03

all:
	@echo "Use 'make fclean' to clean all subdirectories" > /dev/null
	@echo "Use 'make push' to clean all subdirectories and push to GitHub" > /dev/null

fclean:
	@for dir in $(SUBDIRS); do \
	echo "Cleaning $$dir..." > /dev/null;\
		$(MAKE) -C $$dir fclean; \
	done

push: fclean
	@git add . > /dev/null
	@git commit -m "Cleaned and prepared for push" > /dev/null
	@git push origin main > /dev/null