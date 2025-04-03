Sahithya Namani
SN807
RUID- 219004323
Assignment-2

Steps to run the code:
1. Go to command prompt to open the file where it has been saved.
2. Type command g++ "filename".cpp and press enter to complie the code.
3. Now type ./a.out command to run the code.

Flow of instructions:

1. First we define the function "double compdInterestCcltr(double principle, float period, float itrstRate, int periodNum)"
			and also "void debugPrint(int dL, string statement)"
2. The main function take sin the input values for all four fields.
3. The four conditions being implemented for debugPrint() are:
	    a. if(principle < 0 || period < 0 || itrstRate < 0 || periodNum < 0) {
		string statement = "Calculation needs positive values only\n";
		debugPrint(3, statement);
	    } 
	    
	    b. else if(period == 0.0) {
		string statement = "The time span cannot be 0!\n";
		debugPrint(5, statement); 
	    } 
	    
	    c. else if(itrstRate == 0.0) {
		string statement = "The Interest Rate cannot be 0!\n";
		debugPrint(4, statement); 
	    } 
	    
	    d. else if(period == 0.0) {
		string statement = "The time span cannot be 0!\n";
		debugPrint(5, statement); 
	    } 
	    
	    e. else {
		double compoundInterest = compdInterestCcltr(principle, period, itrstRate, periodNum);
		string statement = "Compound Interest";
		debugPrint(1, statement);
		

		cout<< compoundInterest << "\n";
	    }
				
				

