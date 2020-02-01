import os
import sys
import glob

projects = glob.glob("src/*")
UT_Files = glob.glob("test/*")
ProjectsWithSRC = [[item, glob.glob(item + "/*.h"), item.replace("src/", "test/ut_") + ".cpp"] for item in projects]

for item in ProjectsWithSRC:
    if len(item[1]) == 0:
        continue
    src_dir, header_file, ut_file = item[0], item[1][0], item[2]
    print(src_dir, header_file, ut_file)
    class_name = src_dir.split('_', 1)[1]
    class_name = class_name.split('_')
    class_name = [name.capitalize() for name in class_name]
    class_name = "".join(class_name)

    header_lines = open(header_file).readlines()
    for index in range(len(header_lines)):
        if 'Solution' in header_lines[index]:
            header_lines[index] = header_lines[index].replace('Solution', class_name)

    with open(header_file, 'w') as f:
        f.writelines(header_lines)

    ut_lines = open(ut_file).readlines()
    for index in range(len(ut_lines)):
        if 'Solution' in ut_lines[index]:
            ut_lines[index] = ut_lines[index].replace('Solution', class_name)
    with open(ut_file, 'w') as f:
        f.writelines(ut_lines)
