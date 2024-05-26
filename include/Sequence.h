#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <vector>
#include <map>
#include "Nucleotide.h"

// Class representing a sequence of nucleotides
class NucleotideSequence
{
public:
    ~NucleotideSequence();
    void addNucleotideToSequence(Nucleotide *nucleotide);
    void printSequence() const;
    std::string getSequenceAsString() const;
    std::map<char, int> calculateHistogram() const; // Method to calculate the histogram

private:
    std::vector<Nucleotide *> sequence;
};

#endif // SEQUENCE_H
