MODULES = minMax
EXTENSION = minMax
DATA = minMax--0.0.1.sql
PGXS := $(shell pg_config --pgxs)
include $(PGXS)
