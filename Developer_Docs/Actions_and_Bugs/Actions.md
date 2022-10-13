DOCUMENTATION
1.	(9/2022) Demonstrate (or develop a new procedure) for how to create the user manual with bookmarks. The prior versions had bookmarks (Bill used his procedure), but the updated user docs do no have bookmarks. This needs to be addressed. See “MYSTRAN-Users-Manual-how to create a PDF.doc” for Bill’s procedure (which may be out of date for a newer version of Acrobat).
2.	(9/2022) The Install and Run manual may need a TOC update.
3.	(9/2022) Investigate the Craig-Bampton Demo (See the Preface for further discussion). It is not clear what other problems may be used. This example is relatively specific so it is put in the developer side for now.
4.	(9/2022) The “Source_Code_Structure” folder is a data dump for now. It seems there are 2 versions, but neither one may be up to date (though one may be closer than the other).
5.  (9/2022) Update the change log here: https://github.com/MYSTRANsolver/MYSTRAN_Documentation/blob/main/Developer_Docs/ChangeLog.md
6.  (9/2022) Need OP2 general documentation and documentation that needs to go in the user manual. There is some preliminary information in the following link, but we also need something more formal for the user manual.
https://github.com/MYSTRANsolver/MYSTRAN_Documentation/tree/main/User_Docs/OP2_Preliminary
7.  (10/2022) Create a user document with some tips that can help users (things that may not be common). For example, SKIPMGG may be considered for problems where a mass matrix is not needed.
8.  (10/2022) Create a user document with sample BDF/DAT files that shows the setup for a MYSTRAN/NASTRAN deck in a simple way, including comments.
Also, within the sample, show how some common flags that may be not be obvious are used (for example, PARAM, SOLLIB, BANDED and PARAM, SOLLIB, SPARSE).

BENCHMARKS
1.	(9/2022) Add CSHEAR models to the benchmarks
2.  (9/2022) Add in the BUSH, BAR, etc. benchmarks that Toto was working on with Bill

GENERAL 
1.  (9/2022) Long-term modularization effort for Sparse Solvers
2.  (9/2022) Look into adding a CSV output. For starters, this could be a default output that is hard coded (no BDF input required).
The user would make changes at the Fortran level and then rebuild to create a "custom" CSV. After that, it could be adjusted to accept customization via BDF.
3.  (9/2022) Investigate and document the MYSTRAN.INI file furhter. This is discussed in the Install and Run User Manual and there may be some examples in archive versions of MYSTRAN.
4.  (9/2022) Need a list of differences between MYSTRAN and NASTRAN PARAMS and reconcile them so they are in sycn and as compatible as possible.

ELEMENTS
1.  (9/2022) For the elements that Harry is working on, get documentation (as best we can) as to what those formulations are.

BUGS
1.  (9/2022) Look further into the "Bug_Issues.doc" file in this folder. This document contains images so it is stored in a Word file for now.
2.  (9/2022) There was a falilure of a run (I forget now, but something to do with 3 material properties?) The change seemed to have occurred between 13.2 and 13.3 as I remember.
If you run "large_shelled_beam_test.dat", in version 13.3 or after, this error will appear.


PERFORMANCE
1.  (9/2022) A shell element study with different number of elements demonstrated that MYSTRAN was very slow for large models. See further information here:
https://github.com/MYSTRANsolver/MYSTRAN_Documentation/tree/main/Developer_Docs/Shell_Convergence_RunTime_Eval
2.  (10/2022) Investigate code changes to improve performance, specifically for the mass matrix.

COMPILING
1.  (10/2022) Reconsider adding a CodeBlocks option. This would not be a supported option and would be stated as such.
2.  (10/2022) Further evaluate this comment "My changes to superlu did not work and I did not want to go any further. Multi languages can be problematic and C is not my native language.
Your team should cleanup the superlu cmake so that it works out of the box."
