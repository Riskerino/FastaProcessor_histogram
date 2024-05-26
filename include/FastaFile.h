#ifndef FASTA_FILE_H
#define FASTA_FILE_H

#include "FastaFormat.h"
#include <vector>
#include <string>

class FastaFileDNA
{
public:
    FastaFileDNA() {}
    ~FastaFileDNA();
    void addFastaFormatEntryDNA(FastaFormatDNA *fastaEntry);
    void readFromFile(const std::string &fileName);
    void writeToFile(const std::string &fileName);
    void printToTerminal() const;
    const std::vector<FastaFormatDNA*>& getFastaEntries() const; // Getter for fastaEntries

private:
    std::vector<FastaFormatDNA *> fastaEntries;
    void parseStringToNucleotideSequence(const std::string &seqLineAsString, NucleotideSequence *subseq);
};

#endif // FASTA_FILE_H
