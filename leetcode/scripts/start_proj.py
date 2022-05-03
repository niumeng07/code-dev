import sys
import os

args = sys.argv[1:]
args = [item.lower() for item in args]
args[0] = args[0].strip('.').zfill(4)
src_path = "src/" + "_".join(args)
if not os.path.exists(src_path):
    os.mkdir(src_path)

block_name = "_".join(args[1:])
src_file_name = "_".join(args[1:]) + ".h"
src_file = src_path + "/" + src_file_name
if not os.path.exists(src_file):
    f = open(src_file, 'w')
    lines = [
        "#include <iostream>\n"
        "using namespace std;\n"
    ]
    f.writelines(lines)
    f.close()

test_binary = "ut_" + args[0] + "_" + "_".join(args[1:])
test_file = "test/{}.cpp".format(test_binary)
if not os.path.exists(test_file):
    f = open(test_file, 'w')
    lines = [
        "#include <string>\n",
        "#include <vector>\n",
        "#include \"gtest/gtest.h\"\n",
        "#include \"{}/".format("_".join(args)) + "_".join(args[1:]) + ".h" + "\"\n",
        "\n",
        "TEST(%s0, test0) {\n" % (block_name),
        "    EXPECT_EQ(Solution().(), );\n",
        "}\n",
        "\n",
        "int main(int argc, char **argv) {\n",
        "    testing::InitGoogleTest(&argc, argv);\n",
        "    return RUN_ALL_TESTS();\n",
        "}\n"
    ]
    f.writelines(lines)
    f.close()

with open("test/CMakeLists.txt", "a+") as f:
    origin_lines = f.readlines()
    lines = [
        "\n",
        "add_executable({} {}.cpp)\n".format(test_binary, test_binary),
        "target_link_libraries({} ${{GTEST_BOTH_LIBRARIES}} pthread )\n".format(test_binary),
        "gtest_discover_tests({})\n".format(test_binary)
    ]
    f.writelines(lines)


print(' '.join([test_file, src_file]))
