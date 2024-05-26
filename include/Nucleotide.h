#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include <iostream>
#include <string>

class Nucleotide
{
public:
    virtual std::string getType() const = 0;
    virtual ~Nucleotide() = default;
};

class Adenin : public Nucleotide
{
public:
    Adenin(const std::string &id) : id(id) {}
    std::string getType() const override { return "A"; }

private:
    std::string id;
};

class Thymin : public Nucleotide
{
public:
    Thymin(const std::string &id) : id(id) {}
    std::string getType() const override { return "T"; }

private:
    std::string id;
};

class Guanin : public Nucleotide
{
public:
    Guanin(const std::string &id) : id(id) {}
    std::string getType() const override { return "G"; }

private:
    std::string id;
};

class Cytosin : public Nucleotide
{
public:
    Cytosin(const std::string &id) : id(id) {}
    std::string getType() const override { return "C"; }

private:
    std::string id;
};

#endif // NUCLEOTIDE_H
