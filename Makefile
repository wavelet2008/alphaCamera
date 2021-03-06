# Hisilicon Hi3519 sample Makefile

include ../Makefile.param

# target source
INC := -I./tracker/ \
   -I./ \
   -I./sender/ \
   -I./protocol/
HEADS:=$(wildcard *.h)
SRC  := $(wildcard *.c) 
MODULE_SRC := $(wildcard tracker/*.c) \
   $(wildcard sender/*.c) \
   $(wildcard protocol/*.c)

OBJ  := $(SRC:%.c=%.o) 
MODULE_OBJ  := $(MODULE_SRC:%.c=%.o)
TARGET := $(OBJ:%.o=%)
.PHONY : clean all

CFLAGS += $(INC)

all: $(TARGET)

MPI_LIBS += $(REL_LIB)/libtde.a

$(TARGET):%:%.o $(COMM_OBJ) $(MODULE_OBJ) $(HEADS)
	$(CC) $(CFLAGS) -lpthread -lm -g -o $@ $^ $(MPI_LIBS) $(AUDIO_LIBA) $(SENSOR_LIBS) $(HVD_LIBS)

# compile linux or HuaweiLite
#include $(PWD)/../Make.$(OSTYPE)

clean:
	@echo "$(CFLAGS)"
	@echo "$(MODULE_OBJ)"
	@rm -f $(TARGET)
	@echo $(OBJ)
	@rm -f $(OBJ)
	@rm -f $(COMM_OBJ)
	@rm -f $(MODULE_OBJ)

