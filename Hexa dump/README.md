
# Hexa To Ascii (Decoder)

This is simple Hexa decimal to Ascii converter .
It converts take hexa decimal text file which should be piped through xxd(tool to create hexa dump) into text file




This script processes a hex dump file (e.g., generated using xxd), extracts relevant hexadecimal values, converts them into decimal numbers, and decodes them into ASCII characters.

📄 Description
The tool is designed to:

Read a hex dump file (in standard xxd format).

Trim each line to extract the raw hexadecimal content.

Convert hex to decimal values.

Decode decimal values into readable ASCII characters.

🔄 How It Works
1. Input File
The input is a file containing lines in hex dump format. For example:

yaml
Copy
Edit
00000000: 4865 6c6c 6f2c 2057 6f72 6c64 210a  Hello, World!.
2. Line Trimming
Each line is trimmed to isolate the hexadecimal part. Specifically:

python
Copy
Edit
hex_section = line[10:43]
This removes the memory address and the ASCII preview from the line.

3. Hex to Decimal
The trimmed hex string is split into 2-character segments (1 byte each), and each is converted to decimal:

python
Copy
Edit
decimal_values = [int(hex_pair, 16) for hex_pair in hex_pairs]
4. Decimal to ASCII
Each decimal value is then converted into an ASCII character:

python
Copy
Edit
ascii_string = ''.join(chr(value) for value in decimal_values)
✅ Example
Input Line:
yaml
Copy
Edit
00000000: 4865 6c6c 6f2c 2057 6f72 6c64 210a  Hello, World!.
Processing:
Hex Section: 48656c6c6f2c20576f726c64210a

Hex Pairs: ['48', '65', '6c', '6c', '6f', '2c', '20', '57', '6f', '72', '6c', '64', '21', '0a']

Decimal Values: [72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, 10]

ASCII Output: Hello, World!\n

🚀 Usage
Generate Hex Dump
To generate a compatible hex dump file using xxd:

bash
Copy
Edit
xxd yourfile.txt > dump.hex
Run the Script
Assuming the script is saved as hex_processor.py:

bash
Copy
Edit
python hex_processor.py dump.hex
📦 Requirements
Python 3.x

📁 Example Output
bash
Copy
Edit
$ python hex_processor.py dump.hex
Hello, World!