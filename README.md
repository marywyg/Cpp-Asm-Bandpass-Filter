# Bandpass filter using the FIR algorithm for sound files in WAV format
This project is being made for Assembly Languages course on my 5th semester of Informatics.

The program accepts a WAV file as input and processes it through functions in dynamic linked libraries written in C++ and Assembly. This is done in threads (max. 64, optimised based on an individual file) for faster processing. The program then creates a new file called "processed_sample.wav" where it saves results. **This program only runs on a x64 platform.**

## What has been done
- Link between main application and DLLs
- Providing pointers to data for assembly function
- Multiple threads
- The FIR algorithm in C++ for applying bandpass filter
- The FIR algorithm in assembly for applying bandpass filter
- GUI interface made using Windows Forms

## To-do
- Clean up of code
- Removal of old console project
