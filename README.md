Summary of the Code

The provided C++ program reads a DNA sequence in FASTA format from an input file, processes the sequence, prints it to the terminal, writes the output to another FASTA file, and calculates a histogram of nucleotide frequencies. Below is a detailed explanation of each class and method, along with how to use the program.
Key Components

    FastaFile.h & FastaFile.cpp: Manages the reading, processing, and writing of FASTA files.
    Nucleotide.h: Defines classes for different types of nucleotides (Adenine, Thymine, Guanine, Cytosine).
    Sequence.h & Sequence.cpp: Represents a sequence of nucleotides and provides functionality to add nucleotides to a sequence, print the sequence, and calculate a histogram of nucleotide frequencies.
    FastaFormat.h & FastaFormat.cpp: Handles the format of FASTA entries, including the header and the sequence.

Detailed Breakdown
Nucleotide Classes

    Nucleotide.h: Defines an abstract base class Nucleotide and four derived classes (Adenin, Thymin, Guanin, Cytosin) representing the nucleotides A, T, G, and C respectively. Each class has a constructor and a getType method.

Sequence Class

    Sequence.h: Defines the NucleotideSequence class, which stores a vector of Nucleotide pointers and provides methods to add nucleotides to the sequence, print the sequence, get the sequence as a string, and calculate a histogram of nucleotide frequencies.
    Sequence.cpp: Implements the destructor to manage memory and methods for adding, printing, and calculating the histogram of nucleotides.

FastaFormat Classes

    FastaFormat.h: Defines FastaHeader for storing the header and FastaFormatDNA for storing the header and the nucleotide sequence.
    FastaFormat.cpp: Implements methods for setting and getting the header and sequence.

FastaFile Class

    FastaFile.h: Declares the FastaFileDNA class, which manages a collection of FastaFormatDNA entries and provides methods for reading from a file, writing to a file, printing to the terminal, and calculating a histogram.
    FastaFile.cpp: Implements methods for reading a FASTA file (handling multi-line sequences), writing to a FASTA file, printing sequences to the terminal, and a helper method to parse sequence strings into NucleotideSequence objects.

Main Program

    main.cpp: The main entry point of the program. It reads input and output file names from command-line arguments, reads the input FASTA file, prints the sequence to the terminal, writes the processed sequence to the output FASTA file, and calculates and prints the histogram of nucleotide frequencies.
    Summary of Key Methods

    Constructors: Present in Adenin, Thymin, Guanin, Cytosin, FastaFormatDNA classes.
    Destructors: Present in Nucleotide (virtual destructor), NucleotideSequence, and FastaFileDNA.
    Getters: Present in Nucleotide (pure virtual getType), FastaHeader (getHeader), FastaFormatDNA (getFastaHeader, getFastaSequence), and NucleotideSequence (getSequenceAsString).
    Setters: Present in FastaHeader (setHeader) and FastaFormatDNA (setFastaHeader, setFastaSequence).

Histogram Calculation

    calculateHistogram Method: This method in the NucleotideSequence class calculates the frequency of each nucleotide in the sequence.
    printHistogram Function: This function, defined in the main program, prints the histogram of nucleotide frequencies.

By following these instructions, you can compile and run the program to analyze DNA sequences in FASTA format, print the sequences, and calculate and display nucleotide frequency histograms.

Run the Program in /build folder:
./FastaProcessor ../input.fasta ../output.fasta

