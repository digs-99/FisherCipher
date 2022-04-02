# FisherCipher

This project was written to take an char, input-file, output-file, keyfile, mode as command line argument inputs.

Below is a description of how each command line argument is used:
  - Char: either B or S This is used to specify either Block or Stream Cipher
  - inputFile: this could either be an unencrypted or encrypted file depending on mode selection.
  - outputFile: this should be an empty file that you would like to write the output of the program too. (unsure if this overwrites or appends)
  - keyfile: this is the keyfile used. For block encryption/decryption it should be 64 bits.
  - mode: either char E or D for the modes encrypt and decrypt respectively. 
