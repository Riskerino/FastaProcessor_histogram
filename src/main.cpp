#include "FastaFile.h"
#include <iostream>

void printHistogram(const std::map<char, int>& histogram) {
    std::cout << "Histogram of nucleotide frequencies:" << std::endl;
    for (const auto &pair : histogram) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_fasta_file> <output_fasta_file>\n";
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];

    FastaFileDNA fastaFile;
    fastaFile.readFromFile(inputFileName);
    fastaFile.printToTerminal();
    fastaFile.writeToFile(outputFileName);

    // Calculate and print histogram for each sequence
    for (const auto &entry : fastaFile.getFastaEntries()) {
        auto histogram = entry->getFastaSequence()->calculateHistogram();
        printHistogram(histogram);
    }

    return 0;
}
