CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I.
TARGET = contact_book.exe
BUILDDIR = object

SRCS = \
	app/contact_manage.c \
	console/console_io.c \
	storage/contact_storage.c \
	user/main.c

OBJS = $(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c app console storage user

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(BUILDDIR)/%.o: %.c
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

ifdef OS
RM = del /Q
else
RM = rm -f
endif

clean:
	-$(RM) $(subst /,\,$(OBJS)) $(TARGET)
	-rmdir $(BUILDDIR)