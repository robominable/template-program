# template-program
 
This file (or folder as it were) contains all the source code needed to have a working drive train. The current supported types of drive trains are: linear drive (just 4 wheels with motors), X-Drive, and mechanum drive. 
Here's the link: https://github.com/robominable/template-program
Click the "Clone or Download" button to get a copy. Then open the .v5code file in VEXcode 0.9 or later to edit the files.
Drive motors are in ports 1-4 and there is a vision sensor in port 20.
To activate the code for a type of drive train, look to lines 22-24, and remove the // in front of the line with the type of drive train you want to program. That will activate that section of code. 
Don't remove the `#ifdef`s or `#endif`s, since that will cause compilation errors.

If anything is wrong with this program, make sure to let Winston or I know as we can update it easily.
