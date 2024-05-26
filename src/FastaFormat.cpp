#include "FastaFormat.h"

void FastaHeader::setHeader(const std::string &header) {
    this->header = header;
}

std::string FastaHeader::getHeader() const {
    return header;
}

FastaFormatDNA::FastaFormatDNA(int id) : id(id), header(nullptr), sequence(nullptr) {}

void FastaFormatDNA::setFastaHeader(FastaHeader *header) {
    this->header = header;
}

void FastaFormatDNA::setFastaSequence(NucleotideSequence *sequence) {
    this->sequence = sequence;
}

FastaHeader* FastaFormatDNA::getFastaHeader() const {
    return header;
}

NucleotideSequence* FastaFormatDNA::getFastaSequence() const {
    return sequence;
}
