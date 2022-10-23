      PROGRAM Convert_QUADs_to_TRIA3s

! Reads a text file that contains MYSTRAN QUAD4 Bulk Data entries (and any other entries) and converts the QUAD's to a pair of
! TRIA3's with element numbers that have GRID_DELTA (input at the prompt) added to the QUAD4 element ID. Writes out all of the 
! input file with the QUAD's converted to TRIA3's

      USE PENTIUM_II_KIND

      CHARACTER(80*BYTE)              :: CARD              ! 80 column input line from input file
      CHARACTER( 8*BYTE)              :: JCARD(10)         ! 10 fields of 8 columns each from CARD

      INTEGER(LONG)                   :: EID_QUAD          ! Element ID from a CQUAD entry in the input file
      INTEGER(LONG)                   :: EID_TRIA(2)       ! Element ID's for the TRIA3 elements
      INTEGER(LONG)                   :: FATAL_ERR = 0     ! Count of errors reading CARD
      INTEGER(LONG)                   :: GID_QUAD(4)       ! GRID ID's from a CQUAD entry in the input file
      INTEGER(LONG)                   :: GID_TRIA_1(3)     ! GRID ID's for the 1st TRIA3 which replaces a QUAD
      INTEGER(LONG)                   :: GID_TRIA_2(3)     ! GRID ID's for the 2nd TRIA3 which replaces a QUAD
      INTEGER(LONG)                   :: GRID_DELTA        ! Number to add to QUAD element ID's to convert to TRIA elem ID's
      INTEGER(LONG)                   :: I                 ! DO loop index
      INTEGER(LONG)                   :: IERR      = 0     ! Error from FFIELD
      INTEGER(LONG)                   :: IERRFL(10)        ! 'Y'/'N' indicator of whether there were read errs in the fields of CARD
      INTEGER(LONG)                   :: IOCHK             ! IOSTAT error value from READ
      INTEGER(LONG)                   :: IN0               ! Unit number where input  file is opened
      INTEGER(LONG)                   :: OU0               ! Unit number where output file is opened
      INTEGER(LONG)                   :: PID               ! Element property ID

      REAL(DOUBLE)                    :: MAT_ANGLE         ! Mat'l orientation angle

! **********************************************************************************************************************************
      WRITE(*,*) ' Input the integer to add to the QUAD element ID to convert to 2 TRIA3 elements:'
      WRITE(*,*)
      READ(*,'(I8)') GRID_DELTA

      DO I=1,10
         IERRFL(I) = 'N'
      ENDDO

      IN0 = 1
      OU0 = 2

      OPEN(IN0,FILE='Elements.txt',STATUS='OLD')
      OPEN(OU0,FILE='Elements.OUT',STATUS='REPLACE')

cards:DO
         READ(IN0,101,IOSTAT=IOCHK) CARD

         IF (IOCHK < 0) THEN                               ! Quit if EOF/EOR occurs.
            EXIT cards
         ENDIF
 
         IF (IOCHK > 0) THEN                               ! Check if error occurred.
            WRITE(OU0,1010)
            WRITE(OU0,'(A)') CARD
            FATAL_ERR = FATAL_ERR + 1
            CYCLE
         ENDIF
                                                           ! Convert free-field card to fixed field & left justify fields 2-9 
         IF ((CARD(1:1) /= '$')  .AND. (CARD(1:) /= ' ')) THEN
            CALL FFIELD ( CARD, IERR )
            IF (IERR /= 0) THEN
               FATAL_ERR = FATAL_ERR + 1
               WRITE(OU0,101) CARD
               WRITE(OU0,1003)
               CYCLE cards
            ENDIF 
         ENDIF
 
         IF (CARD(1:5) == 'CQUAD') THEN

            CALL MKJCARD ( 'Convert_QUADs_to_TRIA3s', CARD, JCARD )

            CALL I4FLD ( JCARD(2), 2, EID_QUAD )

            CALL I4FLD ( JCARD(3), 3, PID )

            DO I=1,4
               CALL I4FLD( JCARD(I+3), I+3, GID_QUAD(I) )
            ENDDO

            CALL R8FLD (JCARD(8), 8, MAT_ANGLE )

            CALL CRDERR ( CARD )

            IF (FATAL_ERR == 0) THEN
               EID_TRIA(1) = EID_QUAD +   GRID_DELTA
               EID_TRIA(2) = EID_QUAD + 2*GRID_DELTA
               GID_TRIA_1(1) = GID_QUAD(1)
               GID_TRIA_1(2) = GID_QUAD(2)
               GID_TRIA_1(3) = GID_QUAD(3)
               GID_TRIA_2(1) = GID_QUAD(3)
               GID_TRIA_2(2) = GID_QUAD(4)
               GID_TRIA_2(3) = GID_QUAD(1)
               WRITE(OU0,200) EID_TRIA(1), PID, GID_TRIA_1(1), GID_TRIA_1(2), GID_TRIA_1(3), MAT_ANGLE 
               WRITE(OU0,200) EID_TRIA(2), PID, GID_TRIA_2(1), GID_TRIA_2(2), GID_TRIA_2(3), MAT_ANGLE
            ENDIF

         ELSE

            WRITE(OU0,201) CARD

         ENDIF

      ENDDO cards

      IF (FATAL_ERR > 0) THEN
         WRITE(*,301) FATAL_ERR
      ENDIF 

      STOP

! **********************************************************************************************************************************
  101 FORMAT(A)

  200 FORMAT('CTRIA3  ',5I8,F7.4)

  201 FORMAT(A)

  301 FORMAT(' PROGRAM TERMINATED DUE TO ERRORS. SEE OUTPUT FILE')

 1003 FORMAT(' *ERROR  1003: ALL FIELDS ON THE ABOVE CARD MUST BE NO LONGER THAN 8 CHARACTERS')

 1010 FORMAT(' *ERROR  1010: ERROR READING FOLLOWING BULK DATA DECK CARD. CARD IGNORED')

 1011 FORMAT(' *ERROR  1011: NO ',A10,' CARD FOUND BEFORE END OF FILE OR END OF RECORD IN INPUT FILE')

! ##################################################################################################################################

      CONTAINS

! ##################################################################################################################################
 
      SUBROUTINE CRDERR ( CARD )
 
! Prints Bulk Data card errors and warnings
 
      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG, DOUBLE
      IMPLICIT NONE
 
      CHARACTER(LEN=*), INTENT(IN)    :: CARD              ! A Bulk Data card
      CHARACTER( 1*BYTE)              :: CARD_ERR          ! = 'Y' if IERRFL is 'Y' for any Bulk Data card field
 
      INTEGER(LONG)                   :: II                ! DO loop index
 
! **********************************************************************************************************************************
      CARD_ERR = 'N'
      DO II=1,10
         IF (IERRFL(II) == 'Y') THEN
            CARD_ERR = 'Y'
            EXIT
         ENDIF
      ENDDO
 
      IF (CARD_ERR == 'Y') THEN
         WRITE(OU0,101) CARD
         DO II=1,10
            IF (IERRFL(II) == 'Y') THEN
               WRITE(OU0,1502) II
               FATAL_ERR = FATAL_ERR + 1
            ENDIF
         ENDDO   
      ENDIF
 
      DO II=1,10
         IERRFL(II) = 'N'
      ENDDO   
 
! **********************************************************************************************************************************
  101 FORMAT(A)

 1502 FORMAT(' *ERROR  1502: FORMAT ERROR IN FIELD',I3,' OF PREVIOUS CARD')
 
! **********************************************************************************************************************************
 
      END SUBROUTINE CRDERR

! ##################################################################################################################################
 
      SUBROUTINE FFIELD ( CARD, IERR )
 
! Routine to:
!  1) Convert fields 2-9 of a free field Bulk Data card to left justified fixed
!     field CHAR*80 card. It is assumed that if input CARD has a comma
!     then it is a free-field card
!  2) Left justify fields 2 - 9 of cards that are fixed field
 
      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG

      IMPLICIT NONE
 
      CHARACTER(LEN=*),  INTENT(INOUT):: CARD              ! Program input data card
      CHARACTER(1*BYTE)               :: FOUND_DATA        ! 
      CHARACTER(3*BYTE)               :: FREEFLD           ! = 'Y' if CARD is free field form
      CHARACTER( 1*BYTE)              :: IMB_BLANK(2:9)  = (/('N', I=2, 9)/) ! 'Y', 'N' indicates imbedded blanks in B.D. field 
      CHARACTER(8*BYTE)               :: JCARD(10)         ! 10 8 col fields of CARD
      CHARACTER(8*BYTE)               :: TJCARD(10)        ! Temporary JACRD's
      CHARACTER(LEN=LEN(CARD))        :: TCARD             ! Temporary CARD
 
      INTEGER(LONG)                   :: CARD_LEN          ! Length of CARD
      INTEGER(LONG)                   :: II,JJ             ! DO loop indices
      INTEGER(LONG), INTENT(OUT)      :: IERR              ! = 1 if a field  is longer than 8 chars on a free field card
      INTEGER(LONG)                   :: IFD               ! Counter for the 10 fields of a Bulk Data CARD
      INTEGER(LONG)                   :: JCT               ! Column counter in free-field CARD
      INTEGER(LONG)                   :: JCTS              ! Column counter for 1st col of a field in a free-field CARD
 
! **********************************************************************************************************************************
      CARD_LEN = LEN(CARD)

! Make JCARD from CARD
 
      CALL MKJCARD ( 'Convert_QUADs_to_TRIA3s', CARD, JCARD )
 
! Initialize TCARD, TJCARD, and IERR:
 
      DO II = 1,CARD_LEN
         TCARD(II:II) = ' '
      ENDDO
 
      DO II=1,10
         TJCARD(II) = '        '
      ENDDO 
 
      IERR   = 0
 
! Look for ',' on input string 'CARD'; if found, we assume card is free-field
 
      IF (INDEX(CARD,',') > 0) THEN
         FREEFLD = 'YES'
      ELSE
         FREEFLD = 'NO '
      ENDIF

! Process CARD

      IF (FREEFLD == 'NO ') THEN                            ! Left justify data in fields 2-9 for non-free field card.
 
         DO II = 2,9
            IF (JCARD(II) == '        '.OR.JCARD(II)(1:1) /= ' ') THEN
               TJCARD(II) = JCARD(II)  
            ELSE
               DO JJ = 1,8
                  IF (JCARD(II)(JJ:JJ) /= ' ') THEN
                     TJCARD(II)(1:) = JCARD(II)(JJ:)
                     EXIT  
                  ENDIF
               ENDDO
            ENDIF   
         ENDDO   
         DO II=2,9
            JCARD(II) = TJCARD(II)
         ENDDO          
         CALL MKCARD(JCARD,CARD)
 
      ELSE                                                  ! Convert free-field 'CARD' to fixed field 'TCARD'

         IFD = 1
         JCT = 0
         JCTS = 0
         DO II = 1,CARD_LEN
            IF (CARD(II:II) == ' ') CYCLE
            IF (CARD(II:II) /= ',') THEN
               JCT = JCT+1
 
               IF ((JCT-JCTS) > 8) THEN                    ! Check for too long of an entry (greater than 8 columns)
                  WRITE(OU0,1002)
                  WRITE(OU0,129) (CARD(JJ:JJ),JJ=1,CARD_LEN)
                  IERR = 1
                  FATAL_ERR = FATAL_ERR + 1
                  EXIT
               ENDIF
 
               TCARD(JCT:JCT) = CARD(II:II)

            ELSE

               JCT = IFD*8
               JCTS = JCT
               IFD = IFD+1
               IF (IFD > 10) EXIT

            ENDIF

         ENDDO

         CARD = TCARD
 
      ENDIF
 
! Check fields for any imbedded blanks and set error if any are found
 
      DO II=2,9
         FOUND_DATA   = 'N'
         IMB_BLANK(II) = 'N'
         DO JJ=8,1,-1
            IF(JCARD(II)(JJ:JJ) /= ' ') THEN
               FOUND_DATA = 'Y'
            ELSE 
               IF(FOUND_DATA == 'Y') THEN
                  IMB_BLANK(I) = 'Y'
               ELSE
                  CYCLE
               ENDIF
            ENDIF
         ENDDO
      ENDDO
 
      RETURN

! **********************************************************************************************************************************
 1002 FORMAT(' *ERROR  1002: TOO LONG AN ENTRY (MORE THAN 8 CHARACTERS) ON THE FOLLOWING CARD:')

  129 FORMAT(A)
 
! **********************************************************************************************************************************
 
      END SUBROUTINE FFIELD

! ##################################################################################################################################

      SUBROUTINE I4FLD ( JCARDI, IFLD, I4INP )

! Reads 8 column field of INTEGER*4 data

      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG

      IMPLICIT NONE

      CHARACTER( 8*BYTE), INTENT(IN)  :: JCARDI            ! The field of 8 characters to read
      CHARACTER( 1*BYTE)              :: DEC_PT            ! 'Y'/'N' indicator of whether a decimal point was founr in JCARDI

      INTEGER(LONG), INTENT(IN)       :: IFLD              ! Field (2 - 9) of a Bulk Data card to read
      INTEGER(LONG), INTENT(OUT)      :: I4INP             ! The 4 byte integer value read
      INTEGER(LONG)                   :: II                ! DO loop index
      INTEGER(LONG)                   :: IOCHK             ! IOSTAT error value from READ

! **********************************************************************************************************************************
      IERRFL(IFLD) = 'N'

      READ(JCARDI,'(I8)',IOSTAT=IOCHK) I4INP

      IF (IOCHK /= 0) THEN
         IERRFL(IFLD) = 'Y'
         FATAL_ERR    = FATAL_ERR + 1
      ENDIF

! Scan to make sure there was not a decimal point.

      IF (JCARDI /= '        ') THEN
         DEC_PT = 'N'
         DO II=1,8
            IF (JCARDI(II:II) == '.') THEN
               DEC_PT = 'Y'
               EXIT
            ENDIF
         ENDDO
         IF (DEC_PT == 'Y') THEN
            IERRFL(IFLD) = 'Y'
            FATAL_ERR = FATAL_ERR + 1
            WRITE(OU0,1501) IFLD
         ENDIF
      ENDIF
 
      RETURN
 
! **********************************************************************************************************************************
 1501 FORMAT(' *ERROR  1501: A DECIMAL POINT WAS FOUND IN WHAT IS SUPPOSED TO BE AN INTEGER NUMBER IN FIELD ',I3,' OF THE PREVIOUS'&
                           ' BULK DATA CARD') 

! **********************************************************************************************************************************

      END SUBROUTINE I4FLD

! ##################################################################################################################################
 
      SUBROUTINE MKCARD ( JCARD, CARD )
 
! Routine to create CARD, a CHAR*80 field, from the 10 CHAR*8 input JCARD fields
 
      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG, DOUBLE
 
      USE MKCARD_USE_IFs

      IMPLICIT NONE
 
      CHARACTER( 8*BYTE), INTENT(IN)  :: JCARD(10)         ! The 10 fields of 8 characters making up CARD
      CHARACTER(LEN=*)  , INTENT(OUT) :: CARD              ! A Program data card
 
      INTEGER(LONG)                   :: II                ! DO loop index
      INTEGER(LONG)                   :: K1,K2             ! Range for setting CARD = JCARD
 
! **********************************************************************************************************************************
      DO II=1,10
         K1 = 8*(II-1) + 1
         K2 = K1 + 7
         CARD(K1:K2) = JCARD(II)(1:8)
      ENDDO 
 
      RETURN

! **********************************************************************************************************************************
 
      END SUBROUTINE MKCARD

! ##################################################################################################################################
 
      SUBROUTINE MKJCARD ( CARD, JCARD )
 
! Routine to create JCARD, a set of 10 CHAR*8 fields, from input CHAR*80 CARD
 
      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG, DOUBLE
 
      USE MKJCARD_USE_IFs

      IMPLICIT NONE
 
      CHARACTER(LEN=*)  , INTENT(IN)  :: CARD              ! A Program data card
      CHARACTER( 8*BYTE), INTENT(OUT) :: JCARD(10)         ! The 10 fields of 8 characters making up CARD
 
      INTEGER(LONG)                   :: II
      INTEGER(LONG)                   :: K1,K2             ! Range for setting CARD = JCARD
 
! **********************************************************************************************************************************
      DO II=1,10
         K1 = 8*(II-1) + 1
         K2 = K1 + 7
         JCARD(II)(1:8) = CARD(K1:K2)
      ENDDO 
 
      RETURN

! **********************************************************************************************************************************
 
      END SUBROUTINE MKJCARD

! ##################################################################################################################################
 
      SUBROUTINE R8FLD ( JCARDI, IFLD, R8INP )
 
! Reads 8 column field of REAL DOUBLE data
 
      USE PENTIUM_II_KIND, ONLY       :  BYTE, LONG, DOUBLE
      IMPLICIT NONE
 
      CHARACTER( 8*BYTE), INTENT(IN)  :: JCARDI            ! The field of 8 characters to read
      CHARACTER( 1*BYTE)              :: DEC_PT            ! 'Y'/'N' indicator of whether a decimal point was founr in JCARDI
 
      INTEGER(LONG), INTENT(IN)       :: IFLD              ! Field (2 - 9) of a Bulk Data card to read
      INTEGER(LONG)                   :: II                ! DO loop index
      INTEGER(LONG)                   :: IOCHK             ! IOSTAT error value from READ
 
      REAL(DOUBLE) , INTENT(OUT)      :: R8INP             ! The 8 byte real value read
 
! **********************************************************************************************************************************
      IERRFL(IFLD) = 'N'

      READ(JCARDI,'(F8.0)',IOSTAT=IOCHK) R8INP

      IF (IOCHK /= 0) THEN
         IERRFL(IFLD) = 'Y'
         FATAL_ERR    = FATAL_ERR + 1
      ENDIF
 
! Scan to make sure there was a decimal point. Don't set IERRFL, since an error message is written here.

      IF (JCARDI /= '        ') THEN
         DEC_PT = 'N'
         DO II=1,8
            IF (JCARDI(II:II) == '.') THEN
               DEC_PT = 'Y'
               EXIT
            ENDIF
         ENDDO
         IF (DEC_PT == 'N') THEN
            IERRFL(IFLD) = 'Y'
            FATAL_ERR = FATAL_ERR + 1
            WRITE(OU0,1501) IFLD
         ENDIF
      ENDIF
 
      RETURN
 
! **********************************************************************************************************************************
 1501 FORMAT(' *ERROR  1501: NO DECIMAL POINT WAS FOUND IN WHAT IS SUPPOSED TO BE A REAL NUMBER IN FIELD ',I3,' OF THE PREVIOUS'   &
                           ' BULK DATA CARD') 

! **********************************************************************************************************************************
 
      END SUBROUTINE R8FLD

      END PROGRAM Convert_QUADs_to_TRIA3s