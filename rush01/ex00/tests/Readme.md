# Rush-01 Tester

This repository contains a tester executable for the Rush-01 rush project in the 42 piscine. The tester executable helps automate the process of testing the rush-01 program by providing a set of test cases and comparing the program's output with the expected output.

## Usage

1. Unzip the `.tar` file provided for the Rush-01 project, or clone the repository containing the Rush-01 project to your local machine.

2. Move the `tester` folder to the `ex00` folder of the rush01 project. Ensure that the rush-01 program is compiled and located in the same directory as the tester script. If not, please compile the program before proceeding.

3. Open a terminal and navigate to the directory where the tester executable is located.
```
cd path/to/tester
```

4. Give the tester script execute permissions by running the following command:

```
chmod +x ./rush-01_tester_[PLATFORM]
```
The folderstructure should look like this
```
Project Folder
├── README.md
├── rush-01
└── tester
    └── rush_01_[PLATFORM]
```
5. Run the tester script by executing the following command:

```
./rush-01_tester_[PLATFORM]
```


This will run the test cases.

5. The program will display the results of each failed test case, indicating whether it passed or failed. At the end, a summary will be provided indicating the total number of test cases passed or failed.

## Test Cases

The test cases are defined in the `tester/cases` file. Each test case consists of two lines: the input and the expected output, separated by a newline. The script reads the test cases from this file and compares the actual output of the rush-01 program with the expected output.

## Additional Notes

- The program checks for the existence and execute permissions of the rush-01 program before running the test cases. If the program does not exist or does not have the necessary permissions, an error message will be displayed.
- If there is a "Error\n" case that fails and [Got:] is empty. Maybe the evalue prints the error in stderr which is write(2, ptr, n). 
## Contributing

If you encounter any issues or have suggestions for improving the tester script, feel free to reach out to me on Slack with the username "fbruggem". Contributions and feedback are always welcome!

If you require further assistance or have questions regarding the Rush-01 project or the testing process, don't hesitate to message me on Slack.

Happy testing!


##### Todo's
- "" bei execution
- x/y bestanden
- formating
- readme into folder mit example
- if 1 empty read 2
- add note to check manually with copying the execution if it looks the same
