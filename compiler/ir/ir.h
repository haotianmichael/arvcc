#include <vector>
#include <queue>

/*
   [opcode] [operand1] [operand2] [res] 
 */
namespace  IR{

    enum opCode{

        ASS,

        JMP,
        LABEL,


    };

    class irGenerator
    {
    public:
        irGenerator ();
        virtual ~irGenerator ();
    
    private:

    };
    
};
