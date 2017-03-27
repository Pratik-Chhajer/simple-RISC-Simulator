/*

The project is developed as part of Computer Architecture class
Project Name: Functional/Pipeline Simulator for simpleRISC Processor

Developer's Name: PRATHAM GUPTA , PRATIK CHHAJER
Developer's Email id: 2015csb1024@iitrpr.ac.in , 2015csb1025@iitrpr.ac.in
Date: 5th OCTOBER 2K16

*/

/* 
	mySimpleSim.h
	Purpose of this file: header file for mySimpleSim
*/

////////////PIPELINE REGISTER CLASS//////////////
class latch{
public:
int PC;
int gt,eq;
unsigned int op1,op2,immx,branchTarget,aluResult,ldResult;
bool isBranchTaken;
unsigned int branchPC;
unsigned int instruction;

latch(){
  PC = -4;
  gt = 0;
  eq = 0;
  op1 = 0;
  op2 = 0;
  immx = 0;
  branchTarget = 0;
  aluResult = 0;
  ldResult = 0;
  branchPC = 0;
  isBranchTaken = 0;
  instruction = 0xff;
}
};
////////////////////////////////////////


/////////PIPELINE SIMULATOR//////////
void run_pipeline();
/////////////////////////////////////


/////////FUNCTIONAL SIMULATOR//////////
void run_simplesim();
//////////////////////////////////////


//To Check for Data Conlflict
bool conflict(latch,latch);

// To insert or change an instruction to NOP 
latch insertnop(latch A);

// To Check for Branch Conflict
bool branch_conflict(latch A);

// To reset the processor
void reset_proc();

// To load the instruction from memory
void load_program_memory(char* file_name);

//To write memory to mem file
void write_data_memory();

//reads from the instruction memory and updates the instruction register
latch fetch(latch);

//reads the instruction register, reads operand1, operand2 from register file, decides the operation to be performed in execute stage
latch decode(latch);

//executes the ALU operation based on ALUop
latch execute(latch);

//perform the memory operation
latch mem(latch);

//writes the results back to register file
latch write_back(latch);

int read_word(char *mem, unsigned int address);
void write_word(char *mem, unsigned int address, unsigned int data);

// ControlUnit
bool isAdd(unsigned int instruction);
bool isSub(unsigned int instruction);
bool isMul(unsigned int instruction);
bool isDiv(unsigned int instruction);
bool isMod(unsigned int instruction);
bool isCmp(unsigned int instruction);
bool isAnd(unsigned int instruction);
bool isOr(unsigned int instruction);
bool isNot(unsigned int instruction);
bool isMov(unsigned int instruction);
bool isLsl(unsigned int instruction);
bool isLsr(unsigned int instruction);
bool isAsr(unsigned int instruction);
bool isNop(unsigned int instruction);
bool isLd(unsigned int instruction);
bool isSt(unsigned int instruction);
bool isBeq(unsigned int instruction);
bool isBgt(unsigned int instruction);
bool isB(unsigned int instruction);
bool isCall(unsigned int instruction);
bool isRet(unsigned int instruction);
bool isImmediate(unsigned int instruction);
bool isUBranch(unsigned int instruction);
bool isWb(unsigned int instruction);
