import sys, os, pathlib, subprocess, ctypes

libvlc_def_path = pathlib.Path("libvlc.def")
libvlc_dll_path = pathlib.Path("libvlc.dll")



data = subprocess.check_output(
    [
        "dumpbin",
        "/exports",
        str(libvlc_dll_path)
    ]
).decode("utf-8")


# vlc_dll = ctypes.windll(libvlc_dll_path)
defs = "EXPORTS\n"

for i in data.split("\n"):
    potential_symbol = i.split(" ")[-1].strip()
    if potential_symbol.startswith("libvlc_"):
        defs += potential_symbol + "\n"
    
    # print(potential_symbol)

# inf = open("libvlc.def")

print (defs)
libvlc_def_path.write_text(defs)

subprocess.run([
    "lib",
    f"/def:{libvlc_def_path}",
    "/out:libvlc.lib",
    "/machine:x64"
])
