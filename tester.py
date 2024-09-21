import os
import re
import subprocess
import sys
import hashlib

def extract_code_blocks(markdown_content):
    code_block_pattern = re.compile(r'```(c|bash)\n(.*?)\n```', re.DOTALL)
    return code_block_pattern.findall(markdown_content)

def extract_question_numbers(markdown_content):
    question_pattern = re.compile(r'##\s*(Q\d+|Assignment \d+)')
    return question_pattern.findall(markdown_content)

def generate_output_paths(markdown_file, question_number, sub_question_letter, language):
    file_base = os.path.splitext(os.path.basename(markdown_file))[0]
    output_folder = os.path.join("codes", file_base, question_number)
    os.makedirs(output_folder, exist_ok=True)
    file_extension = 'sh' if language == 'bash' else 'c'
    code_filename = os.path.join(output_folder, f'{sub_question_letter}_code.{file_extension}')
    return code_filename

def execute_code(language, code_filename):
    try:
        if language == 'bash':
            # Add shebang line to Bash script
            with open(code_filename, 'r+', encoding='utf-8') as file:
                content = file.read()
                if not content.startswith('#!/bin/bash'):
                    file.seek(0, 0)
                    file.write('#!/bin/bash\n' + content)
            
            # Make the bash script executable
            subprocess.run(['chmod', '+x', code_filename], check=True)
            # Run the bash script
            subprocess.run([code_filename], check=True, capture_output=True, text=True)
        elif language == 'c':
            # Compile the C code
            executable_filename = code_filename[:-2]  # Remove the .c extension
            subprocess.run(['gcc', code_filename, '-o', executable_filename], check=True)
            # Run the compiled executable
            subprocess.run([executable_filename], check=True, capture_output=True, text=True)
            os.remove(executable_filename)  # Clean up the executable after running

        # Print success message
        print(f'Successfully executed {code_filename}')
    except subprocess.CalledProcessError as e:
        # Print error message
        print(f'Error executing {code_filename}: {e}')

def process_markdown_file(markdown_file):
    try:
        with open(markdown_file, 'r', encoding='utf-8') as file:
            content = file.read()
    except OSError as e:
        print(f"Error reading file {markdown_file}: {e}")
        return

    questions = extract_question_numbers(content)
    code_blocks = extract_code_blocks(content)

    current_question = None
    sub_question_letter = 'a'

    for idx, (language, code) in enumerate(code_blocks):
        # Determine which question this code block belongs to
        while len(questions) > 0 and content.find(questions[0]) < content.find(code):
            current_question = questions.pop(0)
            sub_question_letter = 'a'

        if current_question:
            question_number = current_question.split('.')[0]  # Get "Q4" from "Q4."
            code_filename = generate_output_paths(markdown_file, question_number, sub_question_letter, language)

            # Check if the code block has changed using a hash
            code_hash = hashlib.md5(code.encode('utf-8')).hexdigest()
            if os.path.exists(code_filename):
                with open(code_filename, 'r', encoding='utf-8') as existing_code_file:
                    existing_code = existing_code_file.read()
                existing_code_hash = hashlib.md5(existing_code.encode('utf-8')).hexdigest()

                if code_hash == existing_code_hash:
                    print(f"No changes in {code_filename}, skipping execution.")
                    continue

            with open(code_filename, 'w', encoding='utf-8') as code_file:
                code_file.write(code)

            execute_code(language, code_filename)

            # Increment sub_question_letter for the next block within the same question
            sub_question_letter = chr(ord(sub_question_letter) + 1)

def scan_markdown_folder(markdown_folder):
    for root, _, files in os.walk(markdown_folder):
        for file in files:
            if file.endswith('.md'):
                process_markdown_file(os.path.join(root, file))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 script.py <markdown_folder>")
        sys.exit(1)

    MARKDOWN_FOLDER = sys.argv[1]
    scan_markdown_folder(MARKDOWN_FOLDER)
