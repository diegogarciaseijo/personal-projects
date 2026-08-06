# File Copy Utility

A simple command-line file copy utility written in C.

This project was created as a personal exercise after learning about file I/O, memory, and buffers in C. Instead of loading an entire file into memory, it copies the file in fixed-size blocks of 1024 bytes, making it efficient and able to handle both text and binary files.

## Features

* Copies any file (text or binary).
* Uses a fixed-size buffer (1024 bytes).
* Reports the total number of bytes copied.
* Includes basic error handling for invalid arguments and file opening failures.

## Compilation

Compile the program with GCC:

```bash
gcc copy.c -o copy
```

## Usage

```bash
./copy <source> <destination>
```

### Example

```bash
./copy image.png image_copy.png
```

or

```bash
./copy document.pdf backup.pdf
```

## Concepts Practiced

* Command-line arguments (`argc` and `argv`)
* File handling (`fopen`, `fread`, `fwrite`, `fclose`)
* Binary file processing
* Fixed-size buffers
* Error handling
* Basic memory management concepts

## License

This project is intended for learning purposes and is free to use and modify.
