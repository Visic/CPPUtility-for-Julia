This is a utility library so that I can easily call C (and C++) functions from julia.

To Use-
-Build the solution
-Copy the CPPUtility.dll and CPPUtility.jl files to whereever you are going to use them
-then just use (below) in the .jl file where you want to use this lib
    push!(LOAD_PATH, pwd())
    using CPPUtility

KeyCodes--
https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx