import os
import subprocess

def get_uname() -> str:
    r, w = os.pipe()
    pid = os.fork()

    ret = ""

    if pid == 0:
        os.close(r)

        os.execvp("/usr/bin/whoami", ["/usr/bin/whoami"])
    else:
        if pid > 0:
            os.close(w)
            
            for i in os.read(r, 1024 * 1024 * 1024):
                ret = ret + i
    return ret

uname = subprocess.check_output("whoami").decode("utf-8").strip()

print(uname)

print("Running in home dir")
os.chdir("/home/" + uname + "/")

print("Looking for and deleting old program file...")
os.system("rm -rf Monopocli")

print("Creating new program file...")
os.system("mkdir Monopocli")

os.chdir("/home/" + uname + "/Monopocli")

print("Downloading source files...")
os.system("git clone https://github.com/YendisFish/Monopocli .")

print("Building...")
os.system("make")

inp = str(input("Would you like to run the program > "))

if inp.lower() == "yes":
    os.system("make run")
else:
    exit(0)