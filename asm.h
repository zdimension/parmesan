#define MAX_LINE_SIZE 20
#define FILE_IN "calculator.s"
#define FILE_OUT "out.txt"

enum instruction {
  lsls, lsrs, asrs,
  adds, subs, movs,
  ands, eors, adcs = 11,sbcs,rors,tst,rsbs,cmp,cmn,orrs,muls,bics,mvns,
  str, ldr,
  add, sub,
  beq, bne,bcs,bcc,bmi,bpl,bvs,bvc,bhi,bls,bge,blt,bgt,ble,b,bal
};

enum instruction s2e(char *);

typedef struct instruction_LLA
{
  unsigned int rd    :3;
  unsigned int rm    :3;
  unsigned int imm5  :5; 
  unsigned int opcode:3;
  unsigned int idcode:2;
} Inst_shift;

typedef struct
{
  unsigned int rd    :3;
  unsigned int rn    :3;
  unsigned int rm_imm  :3; 
  unsigned int opcode:5;
  unsigned int idcode:2;
} Inst_ASA;

typedef struct
{
  unsigned int imm8  :8;
  unsigned int rd    :3; 
  unsigned int opcode:3;
  unsigned int idcode:2;
} Inst_Movs;


typedef struct
{
  unsigned int rdn   :3;
  unsigned int rm    :3; 
  unsigned int opcode:4;
  unsigned int idcode:6;
} Inst_data;


typedef struct
{
  unsigned int imm8  :8;
  unsigned int rt    :3;  
  unsigned int opcode:1;
  unsigned int idcode:4;
} Inst_load;


typedef struct
{
  unsigned int imm7  :7;
  unsigned int opcode:5;
  unsigned int idcode:4;
} Inst_stack;


typedef struct
{
  signed int imm8  :8;
  unsigned int cond  :4;
  unsigned int idcode:4;
} Inst_branch;
