## Configuration
To set required i2c bus number and i2c chips please 
correct corresponding '[I2C_BUS]' and '[I2C_CHIPS]' tables in CONFIG.toml file or create new 'custom_config.toml' file.


## Compilation
In case of new source files added or first time of compilation please follow the next steps

* Correct source files set in CMakeLists.txt file
* cmake .
* make

In case of NO new source files added please follow the next step
* make

## Executing
Run './clock_sync [path/to/config.toml]'
