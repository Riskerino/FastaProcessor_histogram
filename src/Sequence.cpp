#include "Sequence.h"

NucleotideSequence::~NucleotideSequence() {
    for (auto nucleotide : sequence) {
        delete nucleotide;
    }
}

void NucleotideSequence::addNucleotideToSequence(Nucleotide *nucleotide) {
    sequence.push_back(nucleotide);
}

void NucleotideSequence::printSequence() const {
    for (const auto &nucleotide : sequence) {
        std::cout << nucleotide->getType();
    }
    std::cout << std::endl;
}

std::string NucleotideSequence::getSequenceAsString() const {
    std::string result;
    for (const auto &nucleotide : sequence) {
        result += nucleotide->getType();
    }
    return result;
}

std::map<char, int> NucleotideSequence::calculateHistogram() const {
    std::map<char, int> histogram = {{'A', 0}, {'T', 0}, {'G', 0}, {'C', 0}};
    for (const auto &nucleotide : sequence) {
        histogram[nucleotide->getType()[0]]++;
    }
    return histogram;
}
