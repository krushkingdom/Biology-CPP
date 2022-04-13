#include <iostream>
#include <vector>


class Base
{
    public:
        Base(char input_letter){}
        ~Base(){}

        bool verify_base(char input_letter)
        {
            switch(input_letter){
                case 'A':
                    return true;
                case 'T':
                    return true;
                case 'G':
                    return true;
                case 'C':
                    return true;
                case 'a':
                    return true;
                case 't':
                    return true;
                case 'g':
                    return true;
                case 'c':
                    return true;
                default:
                    return false;
            }
            
        }

        friend std::ostream& operator<<(std::ostream& os, const Base& base)
        {
            os << base.base_letter;
            return os;
        }

    private:
        char base_letter;
};

class Codon
{
    public:
        Codon(){}
        ~Codon(){}

        std::vector<Base> get_codon()
        {
            return three_bases;
        }

        void print_codon()
        {
            int i = 0;
            for(i = 0; i < three_bases.size(); ++i)
            {
                std::cout << three_bases[i];
            }
        }

        friend std::ostream& operator<<(std::ostream& os, Codon codon)
        {
            int i = 0;
            for(i = 0; i < codon.three_bases.size(); ++i)
            {
                os << codon.three_bases[i];
            }
            return os;
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