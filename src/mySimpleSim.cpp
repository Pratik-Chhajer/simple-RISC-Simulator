
/*

  The project is developed as part of Computer Architecture class
  Project Name: Functional/Pipeline Simulator for simpleRISC Processor

  Developer's Name: PRATHAM GUPTA , PRATIK CHHAJER
  Developer's Email id: 2015csb1024@iitrpr.ac.in , 2015csb1025@iitrpr.ac.in

*/

/* 
   mySimpleSim.cpp
   Purpose of this file: implementation file for mySimpleSim
*/

#include "mySimpleSim.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//Register file
static unsigned int R[16];

//registers source and destination
unsigned int rs1,rs2,rd;

//memory
static char MEM[16000];

//////////////////////////Check Data Conflict\\\\\\\\\\\\\\\\\\\\\\\\\

bool conflict(latch P,latch Q){
  unsigned int A=P.instruction;
  unsigned int B=Q.instruction;

  if(A==B)
    return false;

  if(isNop(A) || isBeq(A) || isB(A) || isBgt(A) || isCall(A) || A==0xff){
    return false;
  }
  if(isNop(B) || isBeq(B) || isB(B) || isBgt(B) || isRet(A) || isCmp(B) || isSt(B) || B==0xff){
    return false;
  }

  unsigned int src1,src2;
  src1=(A<<10)>>28;
  src2=(A<<14)>>28;

  if(isSt(A)){
    src2=(A<<6)>>28;
  }
  if(isRet(A)){
    src1=R[15];
  }
	
  unsigned int dest=(B<<6)>>28;

  if(isCall(B)){
    dest=R[15];
  }

  bool hassrc2=1;

  if(!isSt(A)){
    if(isImmediate(A)){
      hassrc2=0;
    }
  }

  if(src1==dest)
    return true;
  else if (hassrc2 && src2==dest)
    return true;
  return false;

}

//////////////////////////////////////


/* To insert or change an instruction to NOP */
latch insertnop(latch A){
  cout<<"NOP   NOP  -------------"<<endl;
  A.instruction=0x68000000;
  A.isBranchTaken = 0;
  return A;
}

//////////////////Check Branch Conflict\\\\\\\\\\\\\\\\\\\\\\\\

bool branch_conflict(latch A){
  cout<< "A.isBranchTaken :  "<<A.isBranchTaken<<endl; 
  return A.isBranchTaken;
}


bool branch_instruct(unsigned int instruction){
return (isBeq(instruction) || isB(instruction) || isBgt(instruction) || isCall(instruction) || isRet(instruction));
}

/////////////////////PIPELINE SIMULATOR\\\\\\\\\\\\\\\\\\\\\\\\\\

void run_pipeline(){
  latch B;// IF-OF pipeline register
  latch C;// OF-EX pipeline register
  latch D;// EX-MA pipeline register
  latch E;// MA-RW pipeline register
  latch F;
  latch A;
  int cycles=0;
cout<<"********************************************"<<endl;
  B=fetch(A);
cout<<"PC : "<<B.PC<<endl;
  cycles++; 
cout<<hex<<"Instruction in IF-OF : "<<B.instruction<<endl;
 cout<<"Instruction in OF-EX : "<<C.instruction<<endl;
cout<<"Instruction in EX-MA : "<<D.instruction<<endl;
cout<<"Instruction in MA-RW : "<<E.instruction<<endl;
for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
cout<<"********************************************"<<endl;

  while(1){
cout<<"********************************************"<<endl;
    F=write_back(E);
    E=mem(D);
    C.eq = E.eq;
    C.gt = E.gt;
    D=execute(C);
    A.isBranchTaken=D.isBranchTaken;
    A.branchPC=D.branchPC;
/* Branch conflict is present */
    if(branch_conflict(D)==1){
      C=insertnop(C);
      B=insertnop(B);
      A.PC = D.branchPC - 8;
    }
    else{
	/* Data Conflict is present */
      if(conflict(B,C) || conflict(B,D) || conflict(B,E)|| conflict(B,F)){
	C = insertnop(C);
      }
      else{
	C=decode(B);
	A.PC+=4;
	if(fetch(A).instruction==0xff  && branch_instruct(C.instruction)){
	  B=insertnop(B);
	}
	else{
	  B=fetch(A);
	}
      }
    }
cout<<"PC : "<<A.PC+4<<endl;
cycles++;
cout<<hex<<"Instruction in IF-OF : "<<B.instruction<<endl;
 cout<<"Instruction in OF-EX : "<<C.instruction<<endl;
cout<<"Instruction in EX-MA : "<<D.instruction<<endl;
cout<<"Instruction in MA-RW : "<<E.instruction<<endl;
for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
cout<<"********************************************"<<endl;

    if(B.instruction==0xff){
      break;
    }
  }

cout<<"********************************************"<<endl;
cout<<"PC : "<<A.PC+4<<endl;
  F=write_back(E);
  E=mem(D);
  D=execute(C);
cout<<hex<<"Instruction in IF-OF : "<<B.instruction<<endl;
 cout<<"Instruction in OF-EX : "<<C.instruction<<endl;
cout<<"Instruction in EX-MA : "<<D.instruction<<endl;
cout<<"Instruction in MA-RW : "<<E.instruction<<endl;
for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
cout<<"********************************************"<<endl;
cycles++;
  //
cout<<"********************************************"<<endl;
cout<<"PC : "<<A.PC+4<<endl;
  F=write_back(E);
  E=mem(D);
cout<<hex<<"Instruction in IF-OF : "<<B.instruction<<endl;
cout<<"Instruction in OF-EX : "<<C.instruction<<endl;
cout<<"Instruction in EX-MA : "<<D.instruction<<endl;
cout<<"Instruction in MA-RW : "<<E.instruction<<endl;
for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
cout<<"********************************************"<<endl;
cycles++;
  //
cout<<"********************************************"<<endl;
cout<<"PC : "<<A.PC+4<<endl;
  F=write_back(E);
cout<<hex<<"Instruction in IF-OF : "<<B.instruction<<endl;
 cout<<"Instruction in OF-EX : "<<C.instruction<<endl;
cout<<"Instruction in EX-MA : "<<D.instruction<<endl;
cout<<"Instruction in MA-RW : "<<E.instruction<<endl;
for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
cout<<"********************************************"<<endl;
cycles++;

  cout<<"PROGRAM TERMINATED\n";
cout<<"Total simulation took "<<cycles<<" cycles"<<endl;
}

///////////////////////////////////////////////////////////////////////////

/////////////////////////FUNCTIONAL SIMULATOR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void run_simplesim() {
  latch A;
  latch B;// IF-OF pipeline register
  latch C;// OF-EX pipeline register
  latch D;// EX-MA pipeline register
  latch E;// MA-RW pipeline register



  while(1) {
    int cycles=0;
    B=fetch(A);
    cout<<"PC : "<<B.PC<<endl;
    cout<<"Instruction  :  "<<hex<<B.instruction<<endl;
    // Breaking condition to exit
    if(B.instruction==0xff){
      cout<<"PROGRAM TERMINATED\n";
	cout<<"Total simulation took "<<cycles<<" cycles"<<endl;
      break;
    }
    C=decode(B);
    D=execute(C);
    E=mem(D);
    A=write_back(E);
    for(int i=0;i<16;i++){
       cout<<dec<<"R["<<i<<"]= "<<(int)R[i]<<endl;
    }
    cout<<endl<<"***************************************************************\n";
 
    cycles++;
  }
}

///////////////////////////////////////////////////////////////////////////


// It is used to set the reset values
// Reset all registers and memory content to 0
void reset_proc() {

  for(int i=0;i<16;i++)
    R[i] = 0;

  // Stack pointer pointing to last memory address
  R[14] = (unsigned long int)(MEM + 16000);

  for(int i=0;i<4000;i+=4)
    write_word(MEM,i,0xff);
}

// Reading Instructions from memory
int read_word(char *mem, unsigned int address) {
  int *data;
  data =  (int*)(mem + address);
  return *data;
}

// Writing instructions to memory
void write_word(char *mem, unsigned int address, unsigned int data) {
  int *data_p;
  data_p = (int*) (mem + address);
  *data_p = data;
}


//load_program_memory reads the input memory, and pupulates the instruction
// memory
void load_program_memory(char *file_name) {
  ifstream fp(file_name);
  unsigned int address, instruction;
    
  if(!fp.is_open()) {
    cout<<"Error opening input mem file\n";
    exit(1);
  }
    
  while((fp>>hex>>address>>instruction)) {
    write_word(MEM, address, instruction);
  }

  fp.close();
}

//writes the data memory in "data_out.mem" file
void write_data_memory() {
  ofstream fp;
  unsigned int i;
  fp.open("data_out.mem");
  if(!fp.is_open()) {
    cout<<"Error opening dataout.mem file for writing\n";
    return;
  }
  
  for(i=0; i < 16000; i = i+4){
    fp<<hex<<i<<" "<<hex<<read_word(MEM,i)<<endl;
  }
  fp.close();
}

//reads from the instruction memory and updates the instruction register
latch fetch(latch A) {
  unsigned int instruction;
  unsigned int isBranchTaken = A.isBranchTaken;
  unsigned int branchPC = A.branchPC;
  int PC=A.PC;
  latch B;
  if(isBranchTaken==1){
    PC=branchPC;
  }
  else {
    PC=PC+4;
  }
  instruction=read_word(MEM,PC);
  B.instruction=instruction;
  B.PC=PC;
  B.eq = A.eq;
  B.gt = A.gt;
  return B;
}

//reads the instruction register, reads operand1, operand2 fromo register file, decides the operation to be performed in execute stage
latch decode(latch B) {
  /* IMMEDIATE AND BRANCHTARGET */
  unsigned int instruction=B.instruction;
  int PC=B.PC;

  latch C;

  unsigned int a=(instruction<<5);
  unsigned int c=(signed)a>>5;
  C.branchTarget=PC+(c<<2);
    
  unsigned int immtemp;
  immtemp=(instruction<<16);
  unsigned int mod;
  mod=(instruction<<14)>>30;
  if(mod==0){
    C.immx=(signed)immtemp>>16;
  }
  else if(mod==1){
    C.immx=immtemp>>16;
  }
  else if(mod==2){
    C.immx=immtemp;
  }
    
  /* READING THE SOURCE REGISTERS */
    
  rs1=(instruction<<10)>>28;
  rd=(instruction<<6)>>28;
  rs2=(instruction<<14)>>28;

  if(isRet(instruction)==1){
    C.op1=R[15];
  }
  else if(isRet(instruction)==0){
    C.op1=R[rs1];
  }
  if(isSt(instruction)==1){
    C.op2=R[rd];
  }
  else if(isSt(instruction)==0){
    C.op2=R[rs2];
  }
  C.instruction=instruction;
  C.PC=PC;
  C.eq = B.eq;
  C.gt = B.gt;
  return C;
}

//executes the ALU operation based on ALUop
latch execute(latch C) {
  /* ALU */
  latch D;
  unsigned int instruction=C.instruction;
  unsigned int op1 = C.op1;
  unsigned int op2 = C.op2;
  unsigned int immx = C.immx;
  unsigned int branchTarget = C.branchTarget;
  int PC = C.PC;
  unsigned int A,B;
  D.eq = C.eq;
  D.gt = C.gt;
  A=op1;
  if(isImmediate(instruction)==1){
    B=immx;
  }
  else if(isImmediate(instruction)==0){
    B=op2;
  }
    
  if(isMov(instruction)==1){
    D.aluResult=B;
  }
  else if(isOr(instruction)==1){
    D.aluResult=A|B;
  }
  else if(isAnd(instruction)==1){
    D.aluResult=A&B;
  }
  else if(isOr(instruction)==1){
    D.aluResult=A|B;
  }
  else if(isNot(instruction)==1){
    D.aluResult= ~B+1;
  }
  else if(isMod(instruction)==1){
    D.aluResult=A%B;
  }
  else if(isDiv(instruction)==1){
    D.aluResult=A/B;
  }
  else if(isMul(instruction)==1){
    D.aluResult=A*B;
  }
  else if(isAdd(instruction)==1){
    D.aluResult=A+B;
  }
  else if(isSub(instruction)==1){
    D.aluResult=A-B;
  }
  else if(isCmp(instruction)==1){
    D.aluResult=(signed int)(A-B);

    if((signed int)(D.aluResult)==0){
      D.eq=1;
      D.gt=0;
    }
    else if((signed int)(D.aluResult)>0){
      D.gt=1;
      D.eq=0;
    }
    else{
      D.eq=0;
      D.gt=0;
    }
  }
  else if(isLsl(instruction)==1){
    D.aluResult=A<<B;
  }
  else if(isLsr(instruction)==1){
    D.aluResult=A>>B;
  }
  else if(isAsr(instruction)==1){
    D.aluResult=(signed)A>>B;
  }
    
  /* BRANCH UNIT */
  if(isRet(instruction)==1){
    D.branchPC=op1;
  }
  else if(isRet(instruction)==0){
    D.branchPC=branchTarget;
  }
    
  bool a=0,b=0;
  if(isBeq(instruction)==1 && D.eq==1){
    a=1;
  }
  if(isBgt(instruction)==1 && D.gt==1){
    b=1;
  }
  if(a==1 || b==1 || isUBranch(instruction)==1){
    D.isBranchTaken=1;
  }
  else{
    D.isBranchTaken = 0;
  }
  D.op2=op2;
  D.instruction=instruction;
  D.PC = PC;

  return D;
}

//perform the memory operation
latch mem(latch D) {
  unsigned int instruction = D.instruction;
  unsigned int aluResult = D.aluResult;
  unsigned int op2 = D.op2;
  int PC = D.PC;
  latch E;
  rs1=(instruction<<10)>>28;

  if(isLd(instruction)==1){
    // Case I Not using stack pointer		
    if(rs1!=14)
      E.ldResult=*((int *)(aluResult+ (unsigned int)(MEM + 4000)));
    // Case II Using stack pointer
    else
      E.ldResult=*((int *)(aluResult));
  }
  else if(isSt(instruction)==1){
    aluResult=op2;
    // Case I Not using stack pointer		
    if(rs1!=14)
      *((int *)(R[rs1]+ (unsigned int)(MEM + 4000)))=aluResult;
    // Case II Using stack pointer
    else
      *((int *)(R[rs1]))=aluResult;
  }
  E.instruction = instruction;
  E.aluResult = aluResult;
  E.PC =PC;
  E.branchPC = D.branchPC;
  E.isBranchTaken = D.isBranchTaken;
  E.eq = D.eq;
  E.gt = D.gt;
  return E;
}

//writes the results back to register file
latch write_back(latch E) {
  latch F;
  unsigned int instruction = E.instruction;
  unsigned int ldResult = E.ldResult;
  unsigned int aluResult = E.aluResult;
  int PC = E.PC;
  unsigned int result;
  if(isLd(instruction)==0 && isCall(instruction)==0){
    result=aluResult;
  }
  else if(isLd(instruction)==1 && isCall(instruction)==0){
    result=ldResult;
  }
  else if(isLd(instruction)==0 && isCall(instruction)==1){
    result=PC+4;
  }
    
  unsigned int reg,rd;
  rd=(instruction<<6)>>28;
    
  if(isCall(instruction)==1){
    reg=15;
  }
  else if(isCall(instruction)==0){
    reg=rd;
  }
    
  if(isWb(instruction)==1){
    R[reg]=result;
  }
  F.PC = PC;
  F.instruction=E.instruction;
  F.branchPC = E.branchPC;
  F.isBranchTaken = E.isBranchTaken;
  F.eq = E.eq;
  F.gt = E.gt;
  return F; 
}

bool isAdd(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 0 || isLd(instruction)==1 || isSt(instruction)==1)
    return true;
  return false;
}

bool isSub(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 1)
    return true;
  return false;
}

bool isMul(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 2)
    return true;
  return false;
}

bool isDiv(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 3)
    return true;
  return false;
}

bool isMod(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 4)
    return true;
  return false;
}

bool isCmp(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 5)
    return true;
  return false;
}

bool isAnd(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 6)
    return true;
  return false;
}

bool isOr(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 7)
    return true;
  return false;
}

bool isNot(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 8)
    return true;
  return false;
}

bool isMov(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 9)
    return true;
  return false;
}

bool isLsl(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 10)
    return true;
  return false;
}

bool isLsr(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 11)
    return true;
  return false;
}

bool isAsr(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 12)
    return true;
  return false;
}

bool isNop(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 13)
    return true;
  return false;
}

bool isLd(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 14)
    return true;
  return false;
}

bool isSt(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 15)
    return true;
  return false;
}


bool isBeq(unsigned int instruction){
  // First extracing opcode
  int opcode = instruction>>27;
  if(opcode == 16)
    return true;
  return false;
}

bool isBgt(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 17)
    return true;
  return false;
}

bool isB(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 18)
    return true;
  return false;
}

bool isCall(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 19)
    return true;
  return false;
}

bool isRet(unsigned int instruction){
  // First extracting opcode
  int opcode = instruction>>27;
  if(opcode == 20)
    return true;
  return false;
}

bool isImmediate(unsigned int instruction){
  // First extracting imediate bit
  unsigned int immediateBit = (instruction<<5)>>31;
  //cout<<"immbit  "<<immediateBit<<endl;
  if(immediateBit == 1)
    return true;
  return false;
}

bool isUBranch(unsigned int instruction){
  // isUbranch is true if instruction is b,call,return
  return ( isB(instruction) || isCall(instruction) || isRet(instruction) );
}

bool isWb(unsigned int instruction){
  // add sub mul div mod and or not mov ld lsl lsr asr call
  return (isAdd(instruction)||isSub(instruction)||isMul(instruction)||isDiv(instruction)||isMod(instruction)||isAnd(instruction)||isOr(instruction)||isNot(instruction)||isMov(instruction)||isLd(instruction)||isLsl(instruction)||isLsr(instruction)||isAsr(instruction)||isCall(instruction));
}

