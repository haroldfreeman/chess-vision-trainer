ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = chess-vision-trainer
chess_vision_trainer_SOURCES = \
	src/main.c

# Manual file
man_MANS = doc/chess-vision-trainer.1
EXTRA_DIST = doc/chess-vision-trainer.1

# Format code
.PHONY: format
format:
	find ./ -type f -name '*.[ch]' -exec $(INDENT) '{}' \
		-kr -ci4 -cli4 -i4 -l79 -nut \;

# Remove all the autotools files
.PHONY: git-clean
git-clean:
	git clean -xdf
