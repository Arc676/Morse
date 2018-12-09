CC=gcc
FLAGS=-std=c11

LIBOUT=libmorse.a
EXECOUT=morse

ifdef DEBUG
FLAGS+=-g -O0
endif

INCLUDE=-I src -L .
CFLAGS=$(FLAGS) $(INCLUDE)
LIB=-l morse

ODIR=obj
SDIR=src
FDIR=frontend

OBJS=morse.o
_OBJS=$(patsubst %, $(ODIR)/%, $(OBJS))

morse: lib
	$(CC) $(CFLAGS) $(FDIR)/morsecode.c $(LIB) -o $(FDIR)/$(EXECOUT)

lib: makeodir $(_OBJS)
	ar rcs $(LIBOUT) $(_OBJS)

makeodir:
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	rm -f $(LIBOUT) $(EXECOUT) $(ODIR)/*.o
