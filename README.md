# X2O Power board ZYNQ software repository

### Bash scripts in the top directory:
| Script name | Description |
|-------------|-------------|
|`fw_program_*.sh`| Programs top or bottom FPGA via JTAG. Give BIT file name as an argument to this script |
|`c2c_reset.sh` | Chip2Chip link reset. Run this after initializing clocks and programming FPGA on the FPGA module(s) |
|`retimer.sh`| 10.24G retimer configuration on the Power module. Must be done after power up in order to use TCDS link |
|`xvc_jtag_*.sh`| start XVC server connected to the JTAG chain on the TOP or BOTTOM FPGA module. These scripts will report which port to use for connection by Vivado |

### The scripts listed below are specific to KU15P FPGA module, but can be used as reference for other FPGA modules
| Script name | Description |
|-------------|-------------|
|`exp_reg_config_*.sh`| I2C expansion register configuration, must be done immediately after payload power is enabled |
|`payload_seq_on_*.sh` `payload_seq_off_*.sh`| Run payload power sequencer on or off sequence on the KU15P module |
|`pok_status.sh`| check Power OK bits on KU15P module |

### Clock configuration scripts are located in `clock` directory. These scripts are also specific to KU15P FPGA module, but can be used as reference for other modules. 
|Directory| Description |
|---------|-------------|
|`clock_async`| Asynchronous clock synthesizer configuration, partnumber: SI5332E-D-GM1 |
|`clock_sync` | Synchronous clock synthesizer configuration, partnumber: SI5345A-D-GM |

### Debugging scripts, should not be used during normal operation
| Script name | Description |
|-------------|-------------|
|`xvc_zynq.sh`| start XVC server connected to debug bridge in ZYNQ firmware. Normally should not be needed by users |
|`payload_on.sh` `payload_off.sh`| Turn on or off payload 12V power supply. This should normally be done using IPMC, these scripts are for debugging purposes when IPMC is not used |
|`devreg.sh` | Script for manually accessing and changing ZYNQ firmware registers. Run without agruments to see the list of registers. `devreg.sh reg_name` will read `reg_name` register. `devreg reg_name value` will write `value` into `reg_name` register. |
