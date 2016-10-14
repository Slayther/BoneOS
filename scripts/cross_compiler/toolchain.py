'''
  This file is part of BoneOS.
 
    BoneOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BoneOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
'''

import os
import subprocess
from subprocess import call

print("You need Python Compiler (Which you probably have if you are running this) , and git for this installaton");


def run_command(cmd):
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    return subprocess.Popen(cmd,
                            stdout=subprocess.PIPE, 
                            stderr=subprocess.PIPE, 
                            stdin=subprocess.PIPE, 
                            startupinfo=startupinfo).communicate()


if(os.path.isdir("cross/")) :
	print("Seems Like You Already Have The Cross Compiler");
else:
	print("Installing the CROSS COMPILER (x86,x86_64,MIPS,ARMV7)");
	os.system("git clone https://github.com/rm-hull/barebones-toolchain cross");

#print(os.path.exists("/home/el/myfile.txt"))