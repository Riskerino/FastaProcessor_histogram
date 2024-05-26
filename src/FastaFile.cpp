#include "FastaFile.h"
#include <fstream>
#include <sstream>
#include <iostream>

FastaFileDNA::~FastaFileDNA() {
    for (auto entry : fastaEntries) {
        delete entry->getFastaHeader();
        delete entry->getFastaSequence();
        delete entry;
    }
}

void FastaFileDNA::addFastaFormatEntryDNA(FastaFormatDNA *fastaEntry) {
    fastaEntries.push_back(fastaEntry);
}

void FastaFileDNA::readFromFile(const std::string &fileName) {
    std::ifstream fFasta(fileName);
    char separator = '>';
    if (fFasta.is_open()) {
        std::string strLine;
        std::string currentSequence;
        std::string currentHeader;

        while (getline(fFasta, strLine)) {
            if (strLine[0] == separator) {
                if (!currentSequence.empty() && !currentHeader.empty()) {
                    auto *fasta = new FastaFormatDNA(0);
                    auto *head = new FastaHeader();
                    auto *seq = new NucleotideSequence();
                    parseStringToNucleotideSequence(currentSequence, seq);

                    head->setHeader(currentHeader);
                    fasta->setFastaHeader(head);
                    fasta->setFastaSequence(seq);
                    addFastaFormatEntryDNA(fasta);

                    currentSequence.clear();
                }

                currentHeader = strLine;
            } else {
                currentSequence += strLine;
            }
        }

        if (!currentSequence.empty() && !currentHeader.empty()) {
            auto *fasta = new FastaFormatDNA(0);
            auto *head = new FastaHeader();
            auto *seq = new NucleotideSequence();
            parseStringToNucleotideSequence(currentSequence, seq);

            head->setHeader(currentHeader);
            fasta->setFastaHeader(head);
            fasta->setFastaSequence(seq);
            addFastaFormatEntryDNA(fasta);
        }

        fFasta.close();
    } else {
        std::cout << "Could not find file: " << fileName << std::endl;
    }
}

void FastaFileDNA::writeToFile(const std::string &fileName) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const auto &entry : fastaEntries) {
            outFile << entry->getFastaHeader()->getHeader() << "\n";
            outFile << entry->getFastaSequence()->getSequenceAsString() << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Could not open file: " << fileName << std::endl;
    }
}

void FastaFileDNA::printToTerminal() const {
    for (const auto &entry : fastaEntries) {
        std::cout << entry->getFastaHeader()->getHeader() << "\n";
        entry->getFastaSequence()->printSequence();
    }
}

const std::vector<FastaFormatDNA*>& FastaFileDNA::getFastaEntries() const {
    return fastaEntries;
}

void FastaFileDNA::parseStringToNucleotideSequence(const std::string &seqLineAsString, NucleotideSequence *subseq) {
    for (auto n : seqLineAsString) {
        if (n == 'A') { 
            auto adenin = new Adenin("0");
            subseq->addNucleotideToSequence(adenin);
        }
        if (n == 'T') { 
            auto thymin = new Thymin("0");
            subseq->addNucleotideToSequence(thymin);
        }
        if (n == 'G') { 
            auto guanin = new Guanin("0");
            subseq->addNucleotideToSequence(guanin);
        }
        if (n == 'C') { 
            auto cytosin = new Cytosin("0");
            subseq->addNucleotideToSequence(cytosin);
        }
    }
}
