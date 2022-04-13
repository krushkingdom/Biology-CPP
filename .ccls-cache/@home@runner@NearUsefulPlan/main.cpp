#include <iostream>
#include <vector>


class Base
{
    public:
        Base(char input_letter){}
        ~Base(){}

        bool verify_base()
        {
            
        }

    private:
        char base_letter;
};

class Codon
{
    public:
        Codon(){}
        ~Codon(){}

        Codon get_codon()
        {
            
        }

    private:
        std::vector<Base> three_bases;
};

class Genome
{
    public:
        Genome(std::vector<Codon> input_sequence): sequence{input_sequence}{}
        ~Genome(){}

    private:
        std::vector<Codon> sequence;
};

int main()
{
    std::cout << "Hello World!\n";
}