import subprocess, sys

if len(sys.argv) >= 2:
    commands = []

    build_folder_path = "../"
    build_type = sys.argv[1]
    bin_file = f"primality_test"

    cmake_command = f"cmake ../ -DCMAKE_BUILD_TYPE={build_type} -Bbuild/{build_type}"
    commands.append(cmake_command)

    run_build = f"cmake --build ./build/{build_type}"
    commands.append(run_build)

    copy_binaries = f"cp build/{build_type}/{bin_file} ./bin"
    commands.append(copy_binaries)

    for c in commands:
        print(f"about to run '{c}'")
        process = subprocess.Popen(c, shell=True)
        process.wait()

else:
    print("a valid use is: python3.8 setup.py <Release | Debug>")