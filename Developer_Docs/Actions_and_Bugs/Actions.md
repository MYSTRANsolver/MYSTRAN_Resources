DOCUMENTATION
1.	Demonstrate (or develop a new procedure) for how to create the user manual with bookmarks. The prior versions had bookmarks (Bill used his procedure), but the updated user docs do no have bookmarks. This needs to be addressed. See “MYSTRAN-Users-Manual-how to create a PDF.doc” for Bill’s procedure (which may be out of date for a newer version of Acrobat).
2.	The Install and Run manual may need a TOC update.
3.	Investigate the Craig-Bampton Demo (See the Preface for further discussion. It is not clear what other problems may be used. This example is relatively specific so it is put in the developer side for now.
4.	The “Source_Code_Structure” folder is a data dump for now. It seems there are 2 versions, but neither one may be up to date (though one may be closer than the other).
5.  Update the change log here: https://github.com/MYSTRANsolver/MYSTRAN_Documentation/blob/main/Developer_Docs/ChangeLog.md

BENCHMARKS
1.	Add CSHEAR models to the benchmarks
2.  Add in the BUSH, BAR, etc. benchmarks that Toto was working on with Bill

GENERAL 
1.  Long-term modularization effort for Sparse Solvers
2.  Look into adding a CSV output. For starters, this could be a default output that is hard coded (no BDF input required).
The user would make changes at the Fortran level and then rebuild to create a "custom" CSV. After that, it could be adjusted to accept customization via BDF.

ELEMENTS
1.  For the elements that Harry is working on, get documentation (as best we can) as to what those formulations are.

BUGS
1.  Look further into the "Bug_Issues.doc" file in this folder

