CIS 340
Project 2

Description: 
This program allows users to access a Minix disk locally mounted on a computer. 
There are a number of functions that the user can access, such as help, mounting/unmounting the disk, 
traversing the disk, viewing the super block, show content of zones and target files, and quitting.

Member Contributions: 
Utkarsh Patel - 55% 
DeQuane Wallace - 45%

Compilation Instructions:
1. Type make 
2. type ./main 
3. mount floppy disk: minimount 
4. use commands showsuper, traverse, showzone, and showfile to access data on the floppy disk. 
5. to get help with the commands, type help on the command line. 
6. to unmount the image file before quitting, type miniumount. 
7. to exit the program, type quit in the command line.

Sample Run: 
$ ./main
Welcome to the minix console

minix>>help
1. help: Display available commands.
2. minimount (absolute path of image file): Mount image file.
3. miniumount: Unmount the mounted floppy disk.
4. showsuper: List information of super block.
5. traverse [-l]: Show the contents in the root directory. Optional -l flag gives detailed information of the root directory.
6. showzone (zone_number): Show ASCII content of zone (zone_number).
7. showfile (file name): Show content of target file.
8. quit: Quit the minix shell.

minix>>minimount imagefile.img
Disk mounted.

minix>>showsuper
number of inodes: 	3424
number of zones: 	1024
number of imap_blocks: 	1
number of zmap_blocks: 	2
first data zone: 	112
log zone size: 	        0
max size: 	        2689
magic: 	                5007
state: 	                0
zones: 	                0

minix>>traverse
A.cla
Aloop1.cla
Aloop1.jav
Aloop2.cla
Aloop2.jav
Aloop3.cla
Aloop3.jav
B.cla
Condit.cla
Condit.jav
D.cla
Demo.cla
Demo.jav
dir1
PolyTest.cla
PolyTest.jav
some.cla
some.java

minix>>traverse -l
-rw-rw-r-- 1000 670 Sep 20 2012  A.cla
-rw-r--r-- 1000 763 Dec 14 2010  Aloop1.cla
-rw-r--r-- 1000 333 Dec 14 2010  Aloop1.jav
-rw-r--r-- 1000 786 Dec 14 2010  Aloop2.cla
-rw-r--r-- 1000 404 Dec 14 2010  Aloop2.jav
-rw-r--r-- 1000 786 Dec 14 2010  Aloop3.cla
-rw-r--r-- 1000 408 Dec 14 2010  Aloop3.jav
-rw-rw-r-- 1000 358 Sep 20 2012  B.cla
-rw-r--r-- 1000 1067 Dec 14 2010  Condit.cla
-rw-r--r-- 1000 444 Dec 14 2010  Condit.jav
-rw-rw-r-- 1000 508 Sep 20 2012  D.cla
-rw-r--r-- 1000 967 Dec 14 2010  Demo.cla
-rw-r--r-- 1000 648 Dec 14 2010  Demo.jav
drwx------ 1000 128 Oct 27 2014  dir1
-rw-rw-r-- 1000 630 Sep 20 2012  PolyTest.cla
-rw-rw-r-- 1000 1063 Sep 20 2012  PolyTest.jav
-rw-r--r-- 1000 226 Dec 14 2010  some.cla
-rw-r--r-- 1000 278 Dec 14 2010  some.java

minix>>showzone 5
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f 
 0      A                             X        p    
10                                                  
20                              7  [  P        q    
30                                                  
40                                    M        r    
50                                                  
60               M                    M        s    
70                                                  
80                                    M        t    
90                                                  
a0                                    M        u    
b0                                                  
c0                                    M        v    
d0                                                  
e0                                    M        w    
f0                                                  
100              f              7  [  P        x    
110                                                 
120              +                    M        y    
130  z                                              
140                                   M        {    
150                                                 
160                             7  [  P        |    
170                                                 
180                          f        M        }    
190                                                 
1a0                          d        M        ~    
1b0                                                 
1c0     A                       u  N  T             
1d0                                                 
1e0     A        `           V        N             
1f0                                                 
200                          <        N             
210                                                 
220                             7  [  P             
230                                                 
240              v              7  [  P             
250                                                 
260              '              6  [  P             
270                                                 
280                          =        M             
290                                                 
2a0                          9        M             
2b0                                                 
2c0                                                 
2d0                                                 
2e0                                                 
2f0                                                 
300                                                 
310                                                 
320                                                 
330                                                 
340                                                 
350                                                 
360                                                 
370                                                 
380                                                 
390                                                 
3a0                                                 
3b0                                                 
3c0                                                 
3d0                                                 
3e0                                                 
3f0                       

minix>>showfile Aloop1.jav
70 75 62 6c 69 63 20 63 6c 61 73 73 20 41 6c 6f 
6f 70 31 20 7b 0a 20 20 20 20 70 75 62 6c 69 63 
20 73 74 61 74 69 63 20 76 6f 69 64 20 6d 61 69 
6e 28 53 74 72 69 6e 67 5b 5d 20 61 72 67 73 29 
20 7b 0a 09 0a 09 53 74 72 69 6e 67 5b 5d 20 72 
61 6e 6b 20 3d 20 7b 22 44 45 55 43 45 22 2c 20 
22 54 48 52 45 45 22 2c 20 22 46 4f 55 52 22 2c 
20 22 46 49 56 45 22 2c 20 22 53 49 58 22 2c 20 
22 53 45 56 45 4e 22 2c 0a 09 09 09 20 22 45 49 
47 48 54 22 2c 20 22 4e 49 4e 45 22 2c 20 22 54 
45 4e 22 2c 20 22 4a 41 43 4b 22 2c 20 22 51 55 
45 45 4e 22 2c 20 22 4b 49 4e 47 22 2c 20 22 41 
43 45 22 7d 3b 0a 09 0a 09 69 6e 74 20 69 20 3d 
20 30 3b 0a 09 69 6e 74 20 63 6f 75 6e 74 65 72 
20 3d 20 30 3b 0a 09 77 68 69 6c 65 20 28 21 72 
61 6e 6b 5b 69 5d 2e 65 71 75 61 6c 73 28 22 53 
49 58 22 29 29 20 7b 0a 09 20 20 20 20 69 2b 2b 
3b 0a 09 20 20 20 20 63 6f 75 6e 74 65 72 2b 2b 
3b 0a 09 7d 0a 09 53 79 73 74 65 6d 2e 6f 75 74 
2e 70 72 69 6e 74 6c 6e 28 63 6f 75 6e 74 65 72 
29 3b 0a 0a 20 20 20 20 7d 0a 7d 0a 0a 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 

minix>>miniumount
Disk unmounted.

minix>>quit

You will now quit out of the minix shell.
