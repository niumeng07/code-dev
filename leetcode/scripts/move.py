import os
import sys
import shutil
import glob

include_dirs = glob.glob('include/*')

for include_dir in include_dirs:
    # print(include_dir)
    include_file = glob.glob(include_dir + '/*.h')
    new_include_file = [item.replace('include', 'src') for item in include_file]

    if len(include_file) == 0:
        shutil.rmtree(include_dir)
        # shutil.rmtree(include_dir.replace('include/', 'src/'))
        continue
    if "Node" in include_dir:
        continue

    for item in include_file:
        print(include_file, new_include_file)
        shutil.move(item, item.replace('include/', 'src/'))
