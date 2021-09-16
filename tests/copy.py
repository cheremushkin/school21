import subprocess
import argparse
from pathlib import Path
import pathlib
import shutil


def run():
    parser = argparse.ArgumentParser()
    parser.add_argument('--root')
    parser.add_argument('--filename')
    args = parser.parse_args()
    root = Path(args.root)
    filename = args.filename

    filepath = Path('./') / filename
    
    for ex_dir in root.glob('ex*'):
        shutil.copy(filename, ex_dir / filename)

if __name__ == '__main__':
    run()
