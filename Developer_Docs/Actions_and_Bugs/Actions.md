DOCUMENTATION
D1.	Demonstrate (or develop a new procedure) for how to create the user manual with bookmarks. The prior versions had bookmarks (Bill used his procedure), but the updated user docs do no have bookmarks. This needs to be addressed. See “MYSTRAN-Users-Manual-how to create a PDF.doc” for Bill’s procedure (which may be out of date for a newer version of Acrobat).
D2.	The Install and Run manual may need a TOC update.
D3.	Investigate the Craig-Bampton Demo (See the Preface for further discussion. It is not clear what other problems may be used. This example is relatively specific so it is put in the developer side for now.
D4.	The “Source_Code_Structure” folder is a data dump for now. It seems there are 2 versions, but neither one may be up to date (though one may be closer than the other).
D5.  Update the change log here: https://github.com/MYSTRANsolver/MYSTRAN_Documentation/blob/main/Developer_Docs/ChangeLog.md
D6.  Need OP2 general documentation and documentation that needs to go in the user manual. Also any notes on codes changes.

BENCHMARKS
B1.	Add CSHEAR models to the benchmarks
B2.  Add in the BUSH, BAR, etc. benchmarks that Toto was working on with Bill

GENERAL 
G1.  Long-term modularization effort for Sparse Solvers
G2.  Look into adding a CSV output. For starters, this could be a default output that is hard coded (no BDF input required).
The user would make changes at the Fortran level and then rebuild to create a "custom" CSV. After that, it could be adjusted to accept customization via BDF.
G3.  Investigate and document the MYSTRAN.INI file furhter. This is discussed in the Install and Run User Manual and there may be some examples in archive versions of MYSTRAN.
G4.  Need a list of differences between MYSTRAN and NASTRAN PARAMS and reconcile them so they are in sycn and as compatible as possible.

ELEMENTS
E1.  For the elements that Harry is working on, get documentation (as best we can) as to what those formulations are.
E2.  Ask about the CBEAM element.

BUGS
B1.  Look further into the "Bug_Issues.doc" file in this folder

