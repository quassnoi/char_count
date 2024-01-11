MODULES = char_count_c
EXTENSION = char_count_c
DATA = char_count_c--1.0.sql
PGFILEDESC = "char_count_c - count number of specified character"
REGRESS = char_count_c

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/char_count_c
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif

