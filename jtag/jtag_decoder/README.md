## Overview
"jtag_decoder.cc" - Zynq compatible jtag decoder tool to produce bitstream.dat binary for JTAG DMA transfer from on Zynq board

## Compilation
To compile jtag_decoder on Zynq run './cmake_build_clean_up.sh', then ‘cmake .’, then 'make'

## Executing
Run 'jtag_decoder bitfile’
    (NOTE: Header in bitfile should be removed. In this case please apply 'python2 fpga-bit-to-bin.py <.bit file name> <.bin file name>'.)
