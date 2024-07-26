# ----------------------------
# Makefile Options
# ----------------------------

NAME = PATIENCE
# ICON = icon.png
DESCRIPTION = "a collection of solitaire games"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)

group::
	convbin -j 8x -i src/gfx/PATCEGFX.8xv -i bin/PATIENCE.8xp -k 8xg-auto-extract -o bin/PATIENCE.8xg -n PATIENCE
