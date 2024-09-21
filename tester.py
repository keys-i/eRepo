import os
import subprocess
import shutil
from concurrent.futures import ThreadPoolExecutor
import atexit

def execute_code(language, code_filename, working_dir):
    """
    Execute the given code file based on its programming language.
    All operations (compilation, execution) happen inside the `working_dir`.
    """
    original_cwd = os.getcwd()  # Save the current working directory
    try:
        # Ensure that the file exists
        if not os.path.exists(code_filename):
            print(f"Error: {code_filename} does not exist.")
            return

        # Change to the working directory where the code file is stored
        os.chdir(working_dir)

        if language == 'bash':
            # Ensure the bash script has a shebang line
            with open(code_filename, 'r+', encoding='utf-8') as file:
                content = file.read()
                if not content.startswith('#!/bin/bash'):
                    file.seek(0, 0)
                    file.write('#!/bin/bash\n' + content)
            
            # Make sure the bash script is executable
            subprocess.run(['chmod', '+x', os.path.basename(code_filename)], check=True)
            
            # Run the Bash script
            result = subprocess.run([f'./{os.path.basename(code_filename)}'], check=True, capture_output=True, text=True)
            print(f"Output of Bash script {code_filename}:\n{result.stdout}")
        
        elif language == 'c':
            # Compile and run the C code in the same folder
            executable_filename = os.path.basename(code_filename[:-2])  # Remove the .c extension
            compile_command = ['gcc', os.path.basename(code_filename), '-o', executable_filename]
            print(f"Compiling C file: {' '.join(compile_command)}")
            
            compile_result = subprocess.run(compile_command, check=True, capture_output=True, text=True)
            print(f"Compilation output: {compile_result.stdout}")

            # Execute the compiled C program
            run_command = [f'./{executable_filename}']
            print(f"Running C executable: {' '.join(run_command)}")
            
            run_result = subprocess.run(run_command, check=True, capture_output=True, text=True)
            print(f"Output of C program {executable_filename}:\n{run_result.stdout}")
            
            # Clean up the executable after running
            os.remove(executable_filename)

        print(f'Successfully executed {code_filename}')
    except subprocess.CalledProcessError as e:
        print(f'Error executing {code_filename}: {e}')
        print(f"Output: {e.output.decode() if e.output else 'No output available'}")
    except FileNotFoundError as e:
        print(f'FileNotFoundError: {e}')
    except OSError as e:
        print(f'OSError: {e}')
    finally:
        os.chdir(original_cwd)  # Restore the original working directory


def cleanup(working_dir):
    """Delete the working directory upon script termination or error."""
    if os.path.exists(working_dir):
        try:
            shutil.rmtree(working_dir)
            print(f"Successfully cleaned up {working_dir}.")
        except Exception as e:
            print(f"Error during cleanup: {e}")


def execute_in_threads(tasks):
    """
    Execute a list of tasks in parallel using threads.
    Each task is a tuple: (language, code_filename, working_dir)
    """
    with ThreadPoolExecutor() as executor:
        futures = []
        for task in tasks:
            language, code_filename, working_dir = task
            future = executor.submit(execute_code, language, code_filename, working_dir)
            futures.append(future)

        # Wait for all threads to complete
        for future in futures:
            try:
                future.result()  # This will raise any exceptions from the thread
            except Exception as e:
                print(f"Error in thread: {e}")


# Register the cleanup function to be called when the script terminates
atexit.register(cleanup, working_dir='codes')

# Example usage
tasks = [
    ('bash', 'script.sh', '/path/to/working_dir1'),
    ('c', 'program.c', '/path/to/working_dir2')
]

# Execute tasks in parallel
execute_in_threads(tasks)
