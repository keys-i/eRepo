"""FOR TESTING PURPOSES ONLY"""
import os
import re
import subprocess
import sys
import time
import hashlib

def extract_and_run_code(markdown_folder, output_base_folder):
    """
    Extracts C and Bash code blocks from Markdown files in the specified folder,
    writes them to temporary files, monitors them for changes, and if any change occurs,
    logs the execution status of each code block to a Q<number>.log file.

    Args:
        markdown_folder (str): The folder containing Markdown files to process.
        output_base_folder (str): The base folder where extracted code files will be stored.
    """
    # Ensure the base output folder exists
    os.makedirs(output_base_folder, exist_ok=True)
    os.makedirs(markdown_folder, exist_ok=True)

    # Regular expression to match code blocks
    code_block_pattern = re.compile(r'```(c|bash)\n(.*?)\n```', re.DOTALL)
    question_pattern = re.compile(r'##\s*(Q\d+)\.?\s*(.*)')

    # Cache to store the hash of the previous extracted code blocks
    code_cache = {}

    while True:
        # Walk through the markdown folder to find all .md files
        for root, _, files in os.walk(markdown_folder):
            for file in files:
                if file.endswith('.md'):
                    markdown_file = os.path.join(root, file)

                    with open(markdown_file, 'r', encoding='utf-8') as md_file:
                        content = md_file.read()

                    matches = code_block_pattern.finditer(content)
                    questions = question_pattern.findall(content)

                    question_number = None
                    question_idx = 0

                    for idx, match in enumerate(matches):
                        language = match.group(1)
                        code = match.group(2)

                        # Find the closest preceding question header for the code block
                        while question_idx < len(questions):
                            question_start = content.find(questions[question_idx][1])
                            code_start = match.start()

                            if code_start > question_start:
                                question_number = questions[question_idx][0]
                                question_idx += 1
                            else:
                                break

                        if not question_number:
                            question_number = f'Q{idx+1}'

                        # Determine output folder based on md file location and name
                        relative_path = os.path.relpath(root, markdown_folder)
                        file_name_without_ext = os.path.splitext(file)[0]
                        output_folder = os.path.join(output_base_folder, relative_path,
                                                     file_name_without_ext, question_number)
                        os.makedirs(output_folder, exist_ok=True)

                        file_extension = 'sh' if language == 'bash' else 'c'
                        filename = os.path.join(output_folder,
                                                f'{question_number}_code{idx+1}.{file_extension}')

                        log_filename = os.path.join(output_folder, f'{question_number}.log')

                        # Calculate the hash of the current code block
                        current_code_hash = hashlib.md5(code.encode('utf-8')).hexdigest()

                        # Check if the code block has changed
                        if filename in code_cache:
                            if code_cache[filename] == current_code_hash:
                                continue  # No changes detected, skip execution
                            else:
                                print(f"Detected change in {filename}, executing again...")
                        else:
                            print(f"Executing {filename} for the first time...")

                        code_cache[filename] = current_code_hash  # Update cache

                        # Write the extracted code to a file
                        with open(filename, 'w', encoding='utf-8') as code_file:
                            code_file.write(code)

                        # Determine appropriate dummy arguments
                        if language == 'bash':
                            dummy_args = ['arg1', 'arg2', 'arg3']
                        elif language == 'c':
                            dummy_args = []
                            if 'argc' in code and 'argv' in code:
                                if 'fopen' in code or '<filename>' in code:
                                    # Assume the program requires a filename;
                                    # use the current C file as input
                                    dummy_args.append(filename)
                                dummy_args.extend(['dummy1', 'dummy2'])

                        # Execute the file with dummy arguments and log status
                        try:
                            if language == 'bash':
                                subprocess.run(['bash', filename] + dummy_args, check=True)
                                status_message = f'Successfully executed {filename}'
                            elif language == 'c':
                                # Compile and run the C code with dummy arguments
                                compiled_filename = os.path.join(output_folder,
                                                                 f'{question_number}_code{idx+1}')
                                subprocess.run(['gcc', filename, '-o',
                                                compiled_filename], check=True)

                                subprocess.run([compiled_filename] + dummy_args, check=True)

                                # Delete the compiled file after execution
                                os.remove(compiled_filename)

                                status_message = f'Successfully compiled and executed {filename}'

                        except subprocess.CalledProcessError as e:
                            status_message = f'Error executing {filename}: {e}'

                        # Log the status message
                        with open(log_filename, 'a', encoding='utf-8') as log_file:
                            log_file.write(status_message + '\n')

        # Wait for a while before checking again
        time.sleep(5)  # Check every 5 seconds

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 tester.py <markdown_folder>")
        sys.exit(1)

    MARKDOWN_FOLDER = sys.argv[1]
    OUTPUT_BASE_FOLDER = 'codes'
    extract_and_run_code(MARKDOWN_FOLDER, OUTPUT_BASE_FOLDER)
