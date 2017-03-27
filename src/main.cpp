/*

  The project is developed as part of Computer Architecture class
  Project Name: Functional/Pipeline Simulator for SimpleRISC Processor

  Developer's Name: PRATHAM GUPTA , PRATIK CHHAJER
  Developer's Email id: 2015csb1024@iitrpr.ac.in , 2015csb1025@iitrpr.ac.in
  Date: 6th NOVEMBER 2K16

*/

/* main.cpp
   Purpose of this file: The file handles the input and output, and
   invokes the simulator
*/

#include "mySimpleSim.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

  if(argc < 2) {
    cout<<"Incorrect number of arguments. Please invoke the simulator \n\t./mySimpleSim <input mem file> \n";
    exit(1);
  }

  //reset the processor
  reset_proc();
  
  //load the program memory
  load_program_memory(argv[1]);

  cout<<"To run the code using FUNCTIONAL Simulator press 1"<<endl;
cout<<"To run the code using PIPELINE Simulator PRESS 2"<<endl;
int l;
cin>>l;  

if(l==1)
run_simplesim();
else if(l==2)
run_pipeline();

  // Write Programs memory
  write_data_memory();
   
  return 1;
}
