#include "pin.H"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

/* =========================== NOTE ================================= */
/* ================================================================== */
INT64 instrCount = 0;
/* ================================================================== */



/* ================================================================== */
// Global variables 
/* ================================================================== */

FILE* out;
bool output_file_closed = false;


/* ===================================================================== */
// Utilities
/* ===================================================================== */

/*!
 *  Print out help message.
 */
INT32 Usage()
{
	cerr << "This tool creates helps instrument instructions" << endl;
	cerr << KNOB_BASE::StringKnobSummary() << endl;
	return -1;
}


/* ===================================================================== */
// Analysis routines
/* ===================================================================== */
/* ++++++++++++++++ ADD YOUR FUNCTION (IF ANY) BELOW ++++++++++++++++++++ */


/* ++++++++++++++++ ADD YOUR FUNCTION (IF ANY) ABOVE ++++++++++++++++++++ */

void docount(){

	instrCount++;
}
void EndInstruction()
{

}

/* ===================================================================== */
// Instrumentation callbacks
/* ===================================================================== */

// Is called for every instruction
VOID Instruction(INS ins, VOID *v)
{
	 
	//+++++++++++++++++ CHANGE YOUR CODE BELOW THIS POINT ++++++++++++++++++++++++++//
	INS_InsertCall(ins,IPOINT_BEFORE,(AFUNPTR)docount,IARG_END);
	
	//+++++++++++++++++ CHANGE YOUR CODE ABOVE THIS POINT ++++++++++++++++++++++++++//
}

VOID Fini(INT32 code, VOID *v)
{

	//+++++++++++++++++ ADD YOUR CODE BELOW THIS POINT ++++++++++++++++++++++++++//
	
        fprintf(out, ":%ld\n", instrCount);
	
	//+++++++++++++++++ ADD YOUR CODE ABOVE THIS POINT ++++++++++++++++++++++++++//

	// close the file if it hasn't already been closed
	if(!output_file_closed) 
	{
		fclose(out);
		output_file_closed = true;
	}
}

int main(int argc, char *argv[]){
	// Initialize PIN library. Print help message if -h(elp) is specified
	// in the command line or the command line is invalid 
	if( PIN_Init(argc,argv) )
		return Usage();

	const char* fileName = "../output/example.out";

	out = fopen(fileName, "w+");

	if (out == NULL){
		cout << "Couldn't open output file. Exiting." << endl;
		exit(1);
	}
	
	// Register function to be called to instrument instructions
	INS_AddInstrumentFunction(Instruction, 0);

	// Register function to be called when the application exits
	PIN_AddFiniFunction(Fini, 0);

	// Start the program, never returns
	PIN_StartProgram();

	return 0;
}
