# Huffman File Compressor


This project is a file compressor that utilizes Huffman coding to achieve efficient compression of various types of files.

## Introduction

The Huffman File Compressor is a command-line tool designed to reduce the size of different types of files using Huffman coding, a variable-length prefix coding algorithm. This technique assigns shorter codes to more frequent symbols, resulting in optimal compression.

## Features

- Compression of various file types (text, binary, etc.).
- Efficient Huffman coding for optimal compression ratios.
- Command-line interface for easy usage.

## How It Works

The compressor operates by:

1. Analyzing the input file to determine the frequency of each symbol.
2. Building a Huffman tree based on symbol frequencies.
3. Generating a mapping of symbols to Huffman codes.
4. Compressing the input file using the generated Huffman codes.
5. Writing the compressed data to an output file.

## Usage

To compress a file, run the following command:

```bash
$ ./Compressor input_file
```

To decompress a file, run:

```bash
$ ./Decompressor input.huff input.table out_file
```

Note: Ensure that you have both `Compressor.cpp` and `Decompressor.cpp` compiled into the executable `a.out` before running the commands. You can do this using the following:

```bash
$ g++ Compressor.cpp -o Compressor
$ g++ Decompressor.cpp -o Decompressor
```

### Example

To compress a file named `example.txt`:

```bash
$ ./Compressor example.txt
```

This will generate two additional files: `test.table` and `test.huff`.

To decompress the compressed file:

```bash
$ ./Decompressor test.huff test.table out.txt
```

This will create a file named `out.txt` containing the original content.



## Contributing

Contributions to the Huffman File Compressor project are highly appreciated. If you have any ideas, bug fixes, or improvements, feel free to contribute!


