PREFIX = /usr/local
CFLAGS = -O3 -flto -DNDEBUG
CPPFLAGS = -O3 -flto -DNDEBUG
SHARED = -shared -Wl,-soname,libcadet -o libcadet.so -fPIC 
TARGET = cadet
SRCDIR = ./src
LIBS = -lm -lstdc++
CC = cc
CFLAGS += -std=c11 
CPPFLAGS += -std=c++11 

.PHONY: default clean test

default: $(TARGET)

OBJECTS = $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/*.c))
HEADERS = $(wildcard $(SRCDIR)/*.h)

LGL_OBJECTS = $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/lingeling/*.c))
LGL_HEADERS = $(wildcard $(SRCDIR)/lingeling/*.h)

MINISAT_OBJECTS = $(patsubst %.cc, %.o, $(wildcard $(SRCDIR)/minisat/*.cc))
MINISAT_OBJECTS += $(SRCDIR)/satsolver_minisat.o

%.o: %.c $(HEADERS) $(LGL_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS) $(LGL_OBJECTS) $(MINISAT_OBJECTS)

$(TARGET): $(OBJECTS) $(LGL_OBJECTS) $(MINISAT_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LGL_OBJECTS) $(MINISAT_OBJECTS) $(LIBS) -o $@

test: default
	python3 scripts/tester.py --test -f

shared: default
	$(CC) $(CFLAGS) $(OBJECTS) $(LGL_OBJECTS) $(MINISAT_OBJECTS) $(LIBS) $(SHARED)

profile: default
	$(CC) $(CFLAGS) -pg $(OBJECTS) $(MINISAT_OBJECTS) $(LIBS) -o $(TARGET) 

clean:
	cd $(SRCDIR) && rm -f *.o *.so *.h.gch *.plist minisat/*.o lingeling/*.o
	-rm -f $(TARGET) libcadet.so

