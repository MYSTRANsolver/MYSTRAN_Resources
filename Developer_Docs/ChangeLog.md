This is the MASTER list of all current and prior changes to the source code and documentation (starting from 11.2).
Information here can be for features, errors/bugs, a list of source codes changes, changes to documentations, etc.
After a release, this information is passed to the appropriate user and developer docs.
Note that changes Prior to 14.0 have been less accurately documented and the time stamps may be approximate.
From 14.0 and onward, all developer documents were made accessible so official releases can now be more accurately documented and also synced with documention.


14.1 to Current
---
- ADD CHANGES HERE

14.0 to 14.1
---
- NEED DEVELOPER INPUT


13.2 to 14.0 (~9/15/2022)
---
- NEED DEVELOPER INPUT
The ELAS values in the SB-ALL-ELEM-TEST.DAT file was being overwritten.

DOCUMENTATION:
1) In the PARAM card, AUTOSPC Default adjusted to 1.0E-8 (previously 1.0E-6)
2) In the PARAM card, added the entry DELBAN
3) In the CBUSH card, the +CONT entry was incorrectly stated at BAR98
4) Modified the Note in Section 4.3 to state that the differential stiffness matrix has been added for solid elements.


13.1 to 13.2 (~9/1/2021)
---
ERRORS:
1) In subroutine OFP3_ELFE_1D a wrong variable was used for BAR length causing errors
in engineering forces for BAR elements
2) In subroutine PRESSURE_DATA_PROC variable NPDAT should have been initialized at
the beginning of each subcase processed
3) Offsets were calculated in such a fashion that the offset values for the last grid in an
element were used for all elements
4) The BUSH coord transformation matrix TE was calculated wrong. The rows & cols were
interchanged

MODIFICATIONS:
1) MYSTRAN previously used 1.0E-06 for the AUTOSPC default value. However, developers agreed that 1.0E-08 is a better choice, which is consistent with other commercial NASTRAN solvers.
In “Source/Modules/PARAMS.f90” ONEPM8 defines the AUTOSPC value
In “Source/Modules/CONSTANTS_1.f90” ONEPM8 is defined to be 1.0E-08_QUAD

2) PARAM,DELBAN
Deletes the Bandit files
1.) Source/Interfaces/BD_PARAM_Interface.f90 where other subroutines can read the types of all parameter entities.
2.) Source/LK1/L1A-BD/BD_PARAM.f90  which processes the PARAM bulk data cards
3.) Source/Modlues/PARAMS.f90  where you define and comment the default value of your parameter, and describe what it does.
In LK1/L1A-bD/BD_PARAM, the comment says that if it's 1, it deletes the bandit files, and if it's 0, it doesn't.
The default is initialized in Modules/PARAMS.f90 and it says that by default, DELBAN = 1 Therefore the default is to delete the bandit files

13.0 to 13.1 (8/10/2021)
---
FEATURES:
1) Buckling capability was added for the ROD (and CONROD)


12.4 to 13.0 (7/28/2021)
---
FEATURES:
1) Buckling capability was added for all 6 solid elements: HEXA (8 and 20 node), PENTA (6 and 15
node) and TETRA (4 and 10 node)

ERRORS:
When running a buckling problem in a model with an RBE2, MYSTRAN stopped with a
fatal error reporting that GMN was not allocated. Code to check the allocation status of GMN
and allocating it if it isn't, was added.


12.0 to 12.4 (7/04/2021)
---
ERRORS:
1) The MIN4T version of the QUAD4 element has the error corrected for orthotropic
materials (4 sub-triangles material orientation fixed)
2) Fix coding issue in CORD_PTOC where: Index variable ‘i’ redefined in procedure
‘param_prtcord_output’ called from within a DO loop in the main procedure


12.0 to 12.2 (4/26/2021)
---
ERRORS:
1) BUSH element code completely rewritten as the BUSH code was nowhere near correct
2) Variable IOFF should be 9 but was 8 (supposed to be the offset into CCELDT to get to
last BUG request)
3) CETEMP(I,J) = 'N' is used to indicate certain elements have no temperature load
capability. Only the ELASi elements were set to 'N'. However, BUSH and PLOTEL should
have also been set.
4) Calculation of BUSH element engineering forces was wrong
5) In subroutine WRITE_FIJFIL, MAX_


12.0 to 12.1 (4/26/2021)
---
ERRORS:
1) A dummy variable as not initialized in 4 subroutines which eventuall caused an error:
OFP3_STRE_NO_PCOMP, OFP3_STRE_NO_PCOMP, OFP3_STRE_NO_PCOMP, OFP3_STRE_NO_PCOMP,
2) RCV values defined on a continuation entry of bulk data entry PUSH would be ignored
and 1.0 values used for the 4 entries on RCV
3) BUSHOFF was not written to unformatted file on unit L1G


11.2 to 12.0 (9/10/2020)
---
FEATURES:
A sparse solver, SuperLU was added.

ERRORS:
For error number 1305, the check on I1 should have been if I1 > NCORD + 1 but, instead,
was I1 > NCORD


For Changes prior to 12.0, see the "Errors_Corrected" and "New_Features_List" files.
---


