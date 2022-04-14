#include <iostream>
#include <vector>
#include <map>

class Base
{
    public:
        Base(char input_letter) : base_letter{input_letter}{}
        ~Base(){}

        char get_base_letter()
        {
            return base_letter;
        }

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

        friend std::ostream& operator<<(std::ostream& os, const Base base)
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
        Codon(std::vector<Base> input_codon): three_bases{input_codon} {}
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

        std::string string_form()
        {
            char_bases = char_form();
            std::string ret_string_bases(char_bases.begin(), char_bases.end());
            string_bases = ret_string_bases;
            return string_bases;
        }

        bool is_stop_codon()
        {
            if (string_form() ==  "UGA" || string_form() == "UAA" || string_form() == "UAG") {
                return true;
            }
            return false;
        }

        std::vector<char> char_form()
        {
            int i = 0;
            for(i = 0; i < three_bases.size(); ++i)
            {
                char_bases[i] = three_bases[i].get_base_letter();
            }
            return char_bases;
        }

    private:
        std::vector<Base> three_bases;
        std::vector<char> char_bases;
        std::string string_bases;
};

class Genome
{
    public:
        Genome(std::vector<Codon> input_sequence): sequence{input_sequence}{}
        ~Genome(){}

        friend std::ostream& operator<<(std::ostream& os, Genome genome)
        {
            int i = 0;
            for(i = 0; i < genome.sequence.size(); ++i)
            {
                os << genome.sequence[i];
            }
            return os;
        }

    //private:
        std::vector<Codon> sequence;
};

int main()
{
    Base U = Base('U');
    Base G = Base('G');
    Base A = Base('A');

    std::cout << U << G << A << std::endl;

    /*
    Codon stop = Codon(std::vector<Base>{U, G, A});

    Genome gen = Genome(std::vector<Codon>{stop, stop, stop});

     if(gen.sequence[0].is_stop_codon() == true)
     {
          std:: cout << "Is Codon 0 a Stop Codon? --> True";
     }
    else
    {
        std:: cout << "Is Codon 0 a Stop Codon?  --> False";
    }
   */
    return 0;
}