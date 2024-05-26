#ifndef FASTA_FORMAT_H
#define FASTA_FORMAT_H

#include "Sequence.h"
#include <string>

class FastaHeader
{
public:
    void setHeader(const std::string &header);
    std::string getHeader() const;

private:
    std::string header;
};

class FastaFormatDNA
{
public:
    FastaFormatDNA(int id);
    void setFastaHeader(FastaHeader *header);
    void setFastaSequence(NucleotideSequence *sequence);
    FastaHeader *getFastaHeader() const;
    NucleotideSequence *getFastaSequence() const;

private:
    int id;
    FastaHeader *header;
    NucleotideSequence *sequence;
};

#endif // FASTA_FORMAT_H
