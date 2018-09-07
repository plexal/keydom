MAKEFLAGS += --warn-undefined-variables
SHELL := /bin/sh
.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.SUFFIXES:

ifeq ($(HOME),)
$(error HOME environment variable not set.)
endif

NAME   := keydom
SDIR   := src
ODIR   := obj
IDIR   := inc
BDIR   := bin
CC     := gcc
CFLAGS := -Wall -g

INC    := -I$(IDIR)
OUT    := $(BDIR)/$(NAME)
SRCS   := $(shell find $(SDIR)/ -type f -name "*.c")
OBJS   := $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRCS))

.PHONY: all
all: $(OUT)

$(OUT): $(OBJS)
	@cd /tmp
	@mkdir -p $(@D)
	@$(CC) $^ -o $@

$(OBJS): $(ODIR)/%.o: $(SDIR)/%.c
	@cd /tmp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -c $(INC) $< -o $@

.PHONY: run
run: $(OUT)
	@$(OUT)

.PHONY: test
test: $(OUT)
	@sudo -v
	-@sudo systemctl stop udevmon; true
	@sudo cp ./bin/keydom /usr/local/bin/keydom
	@sudo chmod a+x /usr/local/bin/keydom
	@sudo mkdir -p /etc/keydom
	@sudo cp ./doc/examples/keydom.conf /etc/keydom/keydom.conf
	@sudo cp ./doc/examples/udevmon.yaml /etc/udevmon.yaml
	@sudo cp ./doc/examples/udevmon.service /etc/systemd/system/udevmon.service
	@sudo systemctl start udevmon
	@sleep 2
	@echo ""
	@sudo ./src/.stop-udevmon.sh &

.PHONY: install
install: $(OUT)
	@sudo -v
	-@sudo systemctl stop udevmon; true
	@sudo cp ./bin/keydom /usr/local/bin/keydom
	@sudo chmod a+x /usr/local/bin/keydom
	@sudo mkdir -p /etc/keydom
	@sudo cp ./doc/examples/keydom.conf /etc/keydom/keydom.conf
	@sudo cp ./doc/examples/udevmon.yaml /etc/udevmon.yaml
	@sudo cp ./doc/examples/udevmon.service /etc/systemd/system/udevmon.service
	@sudo systemctl enable udevmon
	@sudo systemctl start udevmon

.PHONY: clean
clean:
	@rm -f $(ODIR)/*.o $(ODIR)/*.d $(OUT)
