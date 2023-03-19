```bash
Usage: ./hdump [OPTIONS] FILE

Description:
  Display the contents of a file in hexadecimal format.

Options:
  --color         Enable color output
  --size=SIZE     Maximum number of bytes to read from the file (default: unlimited).
  --start=OFFSET  Starting byte offset to read from (default: 0).
  --string=SIZE   Display strings longer than SIZE.
  --raw           Output raw bytes in hexadecimal format, without formatting.

Arguments:
  FILE            The path to the file to be read.
```
