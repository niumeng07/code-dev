#!coding:utf-8

import os
import sys
import glob
import shutil

def new_dir_file_name(path):
    dirname = path.split('/')[-1]
    files = glob.glob(path + "/*")

    try:
        index, names = dirname.split('.')
    except:
        # print(dirname, 'split error.')
        return '-1', '-1', '-1'

    start = 0
    name_list = []
    for i in range(len(names)):
        if names[i].isupper():
            name_list.append(names[start:i])
            start = i
    name_list.append(names[start:i+1])
    index = "{:>4d}".format(int(index)).replace(' ', '0')
    name_list[0] = index
    name_list = [name.lower() for name in name_list]
    dir_name = '_'.join(name_list)
    file_name = '_'.join(name_list[1:])
    file_with_index = '_'.join(name_list[:])
    return dir_name, file_name, file_with_index

def reMkDir(path):
    if os.path.isdir(path):
        shutil.rmtree(path)
    os.mkdir(path)

def copyFile(old_path, new_path):
    if os.path.isfile(new_path):
        os.remove(new_path)
    shutil.copyfile(old_path, new_path)

def process_header_file(header_file):
    header_lines = open(header_file).readlines()
    # print(header_lines)
    pass

def process_gtest_file(gtest_file, header_file):
    gtest_lines = open(gtest_file).readlines()
    gtest_lines.insert(0, '#include "gtest/gtest.h"\n')
    for index in range(len(gtest_lines)):
        if 'Solution.h' in gtest_lines[index]:
            gtest_lines[index] = '#include "' + header_file.replace('include/', '') + '"\n'
    open(gtest_file, 'w').writelines(gtest_lines)
    pass

def process_test_cmake_file(gtest_file, header_file):
    print(gtest_file, header_file)
    cmake_lines = open('test/CMakeLists.txt').readlines()
    bin_name = gtest_file.split('/')[-1].split('.')[0]
    for line in cmake_lines:
        if bin_name in line:
            return
    with open('test/CMakeLists.txt', 'a+') as f:
        f.writelines('\n')
        f.writelines('add_executable(' + bin_name + ' ' + gtest_file.split('/')[-1] + ')\n')
        f.writelines('target_link_libraries(' + bin_name + ' ${GTEST_BOTH_LIBRARIES} pthread )' + '\n')
        f.writelines('gtest_discover_tests(' + bin_name + ')\n')
        pass
    pass


def process(path):
    dir_name, file_name, file_with_index = new_dir_file_name(path)
    if dir_name == '-1' or dir_name.endswith('001'):
        return

    reMkDir('include/' + dir_name)
    reMkDir('src/' + dir_name)
    if len(glob.glob(path + '/Solution.h')) == 0 or len(glob.glob(path + '/main.cpp')) == 0:
        # print(path)
        return
    header_file = 'include/' + dir_name + '/' + file_name + '.h'
    gtest_file = 'test/' + 'gtest_' + file_with_index + '.cpp'
    copyFile(path + '/Solution.h', header_file)
    copyFile(path + '/main.cpp', gtest_file)

    process_header_file(header_file)
    process_gtest_file(gtest_file, header_file)
    process_test_cmake_file(gtest_file, header_file)


if '__main__' == __name__:
    codes_list = glob.glob('/Users/liuda/Local/code/code-dev/leetcode/*')

    for path in codes_list:
        if not os.path.isdir(path):
            print(path, ' is not directory.')
            continue
        process(path)
