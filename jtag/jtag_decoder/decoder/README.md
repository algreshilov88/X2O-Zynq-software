## Overview
"jtag_decoder.cc" - Zynq compatible jtag decoder tool for producing bitstream.dat binary for JTAG-DMA transfer from Linux userspace

## Compilation
To compile jtag_decoder on Zynq run './cmake_build_clean_up.sh', then ‘cmake .’, then 'make'

## Executing
Run 'jtag_decoder /path/to/bitfile’
    (NOTE: Header in .bit file should be removed. In this case please apply 'python2 fpga-bit-to-bin.py <.bit file name> <.bin file name>'.)
