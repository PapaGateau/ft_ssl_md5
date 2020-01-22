# ft_ssl_md5
C implementation of ```md5``` and ```sha256``` hashing algorithms, based on the **OpenSSL** library.  
An introduction to cryptographic hashing algorithms.

## Commands
### Build
```bash
make
make clean # remove object files
make fclean # remove ft_ssl executable, remove object files
```

### Usage
```bash
usage: ft_ssl command [-pqr] [-s string] [files ...]

# command: md5, sha256
    # -p: echo STDIN to STDOUT and append the checksum to STDOUT
    # -a: quiet mode
    # -r: reverse the format of the output
    # -s <string>: hash input string
```

## Implementation
### Process
These hashing algorithms can take an input **message** of any size and produce a **digest** of fixed size. ```md5``` digest is **128-bit** or 16 characters long, and ```sha256```**digest** is as the name entails **256-bit** or 32 characters long.  

Step 1 - First off the message has to be formated:
- Divide message into chunks of **512-bits**
- Append ```1``` bit to the end
- Fill with ```0``` padding in the last chunk to reach **512 - 64 bits**
- The last **64-bits** will store the size of the original message

Step 2 - Based on the number of chunks and predetermined seeds (see ```md5.h``` and ```sha256.h```, the data in each **512-bit** chunk of the message is processed and shuffled for  using **32-bit buffers** (see ```md5_algo.c``` and ```sha256_algo.c```).  

Step 3 - Once the final round of processing has occured, all that is left is to print the hash. We can do so by concatenating each buffer and printing the hexadecimal representation (```md5``` uses **little-endian buffers** so the bits must be inverted).

## Useful links
[MD5 pseudocode](https://en.wikipedia.org/wiki/MD5#Pseudocode)  
[SHA256 pseudocode](https://en.wikipedia.org/wiki/SHA-2#Pseudocode)  
[detailed SHA256 steps](https://docs.google.com/spreadsheets/d/1mOTrqckdetCoRxY5QkVcyQ7Z0gcYIH-Dc0tu7t9f7tw/edit#gid=2107569783)  
