import subprocess
import argparse
from pathlib import Path

def check_tests(tests_results, tests_answers):
    for i, (test_result, test_answer) in enumerate(zip(tests_results, tests_answers)):
        print('Test {}: {}'.format(i, 'OK' if test_result == test_answer else 'WA'))

def listdir_nohidden(d):
    for f in d.iterdir():
        if not f.stem.startswith('.'):
            yield f

def run():
    parser = argparse.ArgumentParser()
    parser.add_argument('--root')
    parser.add_argument('--subject')
    parser.add_argument('--mode')
    args = parser.parse_args()
    root = Path(args.root)
    subject = args.subject
    mode = args.mode
    
    print('=' * 100)

    for ex_dir in root.glob('ex*'):
        if mode == 'check':
            print(f'Working with {ex_dir.name}')
        if len(list(listdir_nohidden(ex_dir))) == 0:
            print(f'Wrong file number, skipped\n')
            continue
        
        func = ''
        for f_func_name in listdir_nohidden(ex_dir):
            with f_func_name.open('r') as f_func:
                func += '\n' + f_func.read()
        
        tests_dir = Path(f'./{subject}/{ex_dir.name}')

        if not (tests_dir / 'tests.c').exists():
            if mode == 'check':
                print('No tests, skipped\n')
            continue
        with Path(tests_dir / 'tests.c').open('r') as f_test:
            tests = f_test.read()

        with (tests_dir /  'to_compile.c').open('w') as f:
            f.write(func + '\n' + tests)
        
        try:
            tests_results = invoke(tests_dir).rstrip('\n').split('\n')
        except FileNotFoundError:
            print('Compilation error, skipped\n')
            continue

        with (tests_dir / 'answers.txt').open('r') as f:
            tests_answers = f.read().rstrip('\n').split('\n')

        if mode == 'test':
            check_tests(tests_results, tests_answers)
        if mode == 'compile':
            print('\n' + '\n'.join(tests_results))
        print('=' * 100)

def invoke(ex_dir):
    print(f'Compile {ex_dir.name} with tests')
    result = subprocess.run(f'gcc -Wall -Wextra -Werror -o exec to_compile.c'.split(' '), cwd=str(ex_dir), stdout=subprocess.PIPE)
    result = subprocess.run('./exec', cwd=str(ex_dir), stdout=subprocess.PIPE)
    return result.stdout.decode('utf-8')

if __name__ == '__main__':
    run()
