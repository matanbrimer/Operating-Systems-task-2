Part A: Implementing for us 2 programs: cmp and copy - that function as regular CMD tools. 
The cmp tool will compare two files and return an integer value of 0 if they are equal and 1 if not, and it will support the -v flag for verbose output. 
The copy tool will copy a file to another place and/or name and will return an integer value of 0 on success and 1 on failure. It will support the -v flag, which will output "success" if the file is copied, "target file exist" if the file already exists, or "general failure" on some other problem, in addition to the integer value returned. The tool will also support the -f flag, which allows the target file to be overwritten.

Part B: 2 coding methods: codecA and codecB - and two methods - encode and decode. 
The codecA method converts all lowercase characters to uppercase and all uppercase characters to lowercase, while leaving all other characters unchanged. 
The codecB method converts all characters to the 3rd next character. The library should be "reversible", meaning that encoding and then decoding the same string should result in the original string.

Part C: shell program named stshell that can run CMD tools that exist on the system using fork, exec, and wait. It stop running tools by pressing Ctrl+c using a signal handler. It also allow output redirection with ">" and ">>" and piping with "|" and able to stop the shell using the "exit" command.

