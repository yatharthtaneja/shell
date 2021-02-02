# shell
How to run
Just run make all command in the directory Assignment1/1.2 and ignore the warnings.
All the internal commands can be implemented without the fork option , description of fork and
wait is provided in the previous assignment.
The execv() command takes the address of child and the command array as input and runs the
separate .c file
Internal commands

echo :
Options : 1. -n : do not output the trailing newline
2. -e : enable interpretation of backslash escapes
Errors and corner cases
For the default command without the inverted commas \ is not printed
Input: echo “hello \n world”
Output: hello \n world
Input: echo hello \n world
Output: hello n world
Cases handled for -e \n , \ ,\t , \b
Prints new line when only echo w/o arguments is called
All inverted quotes are eliminated
cd:
Options : 1. ~ : do not output the trailing newline
.. : redirect to previous
Errors and corner cases
Only cd without arguments redirects to the home directory.
Error reporting if directory doesn’t exist
More than 1 directory provided
history:
Options : 1. -c : to clear all history
-d : to delete a history with offset
Errors and corner cases
When provided with number as option , prints only those many entries
from the bottom
If in option -d offset is greater than the number of history it throws an error
Error if more than 3 inputs are given
pwd :
Options : 1. -L : Use pwd from environment even if it contains symlinks
-P : avoid all symlinks
Errors and corner cases
The function getcwd() and getenv() handle all the errors in c and
return null if there are any errors
exit :
Options: No options as it is a system call.
External commands
ls:
Options : 1. -1 : prints all entries in new line
-a : shows all hidden files and. , .. files
Errors and corner cases
Alpha sorting is done
Works with an absolute path
ls works when a directory is provided as argument
Multiple arguments (1 option and directory as argument is allowed)
cat:
Options : 1. -n : number all output lines
-b : number all non empty lines, overrides -n
Errors and corner cases
When cat is called without arguments , it goes into infinite loop and prints
whatever is given as input.
Multiple files are handled
If file 1 ends at line x the next file starts printing from same line without
even a space
Numbering is handled for the same.
Error if file doesn't exist
date:
Options : 1. -I : prints in yyyy/mm/dd format
-u : displays GMT instead of local time of machine.
+%b: abbreviated month name
+%a: abbreviated weekday name
Errors and corner cases
Error if more than 1 operand provided
Error if other than 4 options mention above provided
mkdir:
Options : 1. -v : print a message for each created directory
-p : no error if existing, make parent directories as needed
Errors and corner cases
Report error if already exists
Create multiple directories
Give error if directory already exists
makes directory within another directory if that is not the present working
directory
Error for missing operands
Error if other than above options are provided
rm :
Options : 1. -i : prompts for yes or no before deleting
-d : number all non empty lines, overrides -n
Errors and corner cases
Cannot delete non empty directory
Can delete multiple directories at once
Error if no argument is passed
Error if file not found
Assumption : you do not delete the shell files.
