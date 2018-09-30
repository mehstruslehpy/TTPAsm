# WHAT THIS IS:
* This is an assembler for the TTP architecture.
  * TTP stands for "Taks Toy Processor" it is a processor design used for an intro to assembly language class that I took.
# TIPS AND USAGE:
* To run do: ./asm &lt;myasmfile&gt;
  * the output will be placed in the file output.ram.
  * if you have access to the Taks logisim files for his ttp processor then you can run your assembly on those.
  * if you do not then don't worry you can run them just as easily on the emulator I created which you can find at https://github.com/mehstruslehpy/TTPSim
* As an example try running the code under ./TestingPrograms
  type: ./asm TestingPrograms/Add.asm
# TODO:
* clean up the source code and make it look pretty.
* doxygen docs?.
* test more thorougly.
* nicer error handling.
* clean up debug/logging output.
* fix very minor label/comment bugs.
* fix minor single char instruction matching bugs.
![link to demo gif goes here](https://raw.githubusercontent.com/mehstruslehpy/Documents/master/C%2B%2B/TTPAsm/TTPSimAndAsmDemo.gif)
