#export CROSS_COMPILE := aarch64-linux-gnu-
#export ARCH := arm64
MYCC := gcc

DRIVER := xilinx_xvc_driver
XVCSERVER := xvcServer
TEST := verify_$(DRIVER)
IOCTL_HDR_DIR := ../driver

.PHONY: ioctl
ioctl: $(XVCSERVER)_ioctl

.PHONY: mmap
mmap: $(XVCSERVER)_mmap

.PHONY: test
test: $(TEST)

.PHONY: all
all: ioctl mmap test

$(XVCSERVER)_ioctl: $(XVCSERVER).c semaphore.c
	$(MYCC) -Wall -I$(IOCTL_HDR_DIR) -DUSE_IOCTL -g -o $@ $^

$(XVCSERVER)_mmap: $(XVCSERVER).c
	$(MYCC) -Wall -g -o $@ $^

$(TEST): $(TEST).c
	$(MYCC) -I$(IOCTL_HDR_DIR) -g -o $@ $^

.PHONY: clean
clean:
	rm -f $(XVCSERVER)_mmap
	rm -f $(XVCSERVER)_ioctl
	rm -f $(TEST)
