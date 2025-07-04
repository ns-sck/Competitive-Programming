import subprocess
import os

# Compile the C++ file
cpp_file = "sol.cpp"  # Replace with your C++ file name
executable = "program"

# Compile the C++ program
compile_command = f"g++ -o {executable} {cpp_file}"
compilation = subprocess.run(compile_command, shell=True, capture_output=True, text=True)

if compilation.returncode != 0:
    print("Compilation failed!")
    print(compilation.stderr)
    exit(1)

# Loop through all input files
for i in range(35, 36):
    inp = "input"
    out = "output"
    if (i < 10):
        inp += '0'
        out += '0'
    inp += f"{i}.txt"
    out += f'{i}.txt'
    input_file = inp
    output_file = out
    
    # Check if input file exists
    if not os.path.exists(input_file):
        print(f"{input_file} not found, skipping.")
        continue
    
    # Run the program with input and write output
    with open(input_file, "r") as infile, open(output_file, "w") as outfile:
        process = subprocess.run(f"./{executable}", stdin=infile, stdout=outfile, text=True)
        
        if process.returncode != 0:
            print(f"Error occurred while processing {input_file}.")

print("Processing completed!")
