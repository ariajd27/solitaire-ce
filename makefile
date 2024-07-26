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
