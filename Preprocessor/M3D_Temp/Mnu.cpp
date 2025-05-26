#include "Mnu.h"
#include "M3Da.h"
#include "math.h"
#include "Parser.h"
#include "GLOBAL_VARS.h"

//constructor sets where to out text
const double Pi = 3.1415926535;
#define D2R  0.01745329251994
#define R2D  57.2957795130931

double gDIM_FILSZ = 0.1;
double gDIM_OFFSZ = 0.1;
double gTXT_HEIGHT = 0.5;
double gDIM_RADSZ = 0.5;
double gDIM_CVORD = 2;
//GLOBAL DEFUALT VALUES ENTERED

void zMnu::Init(DBase* TheDBase, int iType)
{
	cDBase = TheDBase;
	pNext = NULL;
	iCKill = 0;
	RetVal = 0;
	iResumePos = 0;
	iStat = 0;
	initCnt = cDBase->DB_BuffCount;
	S_initCnt = cDBase->S_Count;
	iT = iType;
}

//saeed_start
//void zMnu::Init2(NSurf* ThetempSeedCurves)
//{
//	tempSeedCurves = ThetempSeedCurves;
//}
//saeed_end

void zMnu::DoNext(CString* CInMsg, CPoint Pt)
{
	if (pNext != NULL)
	{
		iCKill = pNext->DoMenu(*CInMsg, Pt);
		if (iCKill == 1)
		{
			delete pNext;
			pNext = NULL;
			iCKill = 0;
			iStat = iResumePos;//poistion to resume //saeed_comment_2025/05/18: (Done or Yes)
			*CInMsg = "NULL";
			//cDBase->DB_ActiveBuffSet(1);
		}
		if (iCKill == 2)
		{
			delete pNext;
			pNext = NULL;
			iCKill = 0;
			iStat = iCancelPos;//poistion to Cancel
			*CInMsg = "NULL";
			cDBase->S_Res();
			//cDBase->DB_ActiveBuffSet(1);
		}
		///saeed_start
		if (iCKill == 3)
		{
			delete pNext;
			pNext = NULL;
			iCKill = 0;
			iStat = iNoPos;//poistion to No
			*CInMsg = "NULL";
			cDBase->S_Res();
			//cDBase->DB_ActiveBuffSet(1);
		}
		//saeed_end
	}

}

int zMnu::DoMenu(CString CInMsg, CPoint Pt)
{
	BOOL  bNextBlock;
	BOOL  bNextBlock2;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (iStat == 0)
		{
			bNextBlock = FALSE;
			bNextBlock2 = FALSE;
			if (CInMsg == "NDCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURTRIM")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURTRIM_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELMOLAB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELMOLAB_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "QWNODES")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zQWNODES_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRROD")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRROD_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDMOLAB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDMOLAB_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RESSEL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRESSEL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPNEXT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPNEXT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPPREV")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPPREV_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MESHQND")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMESHQND_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RESSETFULLLIST")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRESSETFULLLIST_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RESSETDEFSCL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRESSETDEFSCL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RESSETLIST")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRESSETLIST_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RESSELDEF")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRESSELDEF_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPCENT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPCENT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MMAT1")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMMAT1_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRSOLID")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRSOLID_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRCMAT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRCMAT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPONCV")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPONCV_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPONSURF")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPONSURF_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURSWEEP")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURSWEEP_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ALIGN")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zALIGN_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "QANG")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zQANGSIZE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRSHELL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRSHELL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELPTSCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELPTSCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELSURFCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELSURFCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELCURCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELCURCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MERNODES")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMERNODES_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ARC3PT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zARC3PT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CIR3PT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCIR3PT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SOFF")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSOFF_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRBBOX")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRBBOX_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRBTUBE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRBTUBE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRBROD")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRBROD_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRBBAR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRBBAR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "BUPVEC")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zBUPVEC_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "QSIZE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zQSIZE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "BOFF")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zBOFF_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELBYMID")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELBYMID_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "INSCAT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zINSCAT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "REFLECT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zREFLECT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRLISTALL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRLISTALL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MATLISTALL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMATLISTALL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SCALE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSCALE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "COPYROT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCOPYROT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MMESHQ")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMMESHQ_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MMESHT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMMESHT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ROTANG")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zROTANG_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ROTABOUT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zROTABOUT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELSWEEP")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELSWEEP_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELSWEEPB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELSWEEPB_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LABENT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLABENT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PRLIST")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPRLIST_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELMOPID")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELMOPID_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDMOOSYS")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDMOOSYS_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDMORSYS")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDMORSYS_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELBYTYPE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELBYTYPE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CNODES")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCNODES_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LMEAS")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLMEAS_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELAT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELAT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "COLINE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCOLINE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPBYPID")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPBYPID_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RELTO")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRELTO_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELALL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELALL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPBYCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPBYCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELBYCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELBYCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELNODESBYCOL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELNODESBYCOL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "COORDCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCOORDCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CVONSUR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCVONSUR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURBOUND")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURBOUND_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SELBYPID")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSELBYPID_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURTRIMLOOP")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURTRIMLOOP_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDBET")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDBET_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CORNER")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCORNER_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RECT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRECT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "OFFSET")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zOFFSET_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LNANG")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLNANG_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "FIL")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zFIL_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CVFIT")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCVFIT_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "DSPLAM")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zDSPLAM_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "FILET")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zFILET_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPSIZE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPSIZE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "COPY")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCOPY_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "FCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zFCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CVMOW")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCVMOW_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "MOVE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zMOVE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CVPTON")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCVPTON_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SUREX")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSUREX_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURRV")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURRV_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "SURCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zSURCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LAB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "RCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zRCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDMOVE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDMOVE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPMODE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPMODE_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDCO")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDCO_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CVCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCVCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "NDONCV")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zNDSONCV_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "ELTYPE")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zELTYPE_Mnu();
				pNext->Init(cDBase, -1);
				pNext->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "PTCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zPTCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LN")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLN_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CIRCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCIRCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "CIRCR2")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zCIRCR2_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LNX")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLNX_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LNY")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLNY_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "LNZ")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zLNZ_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPALIGN")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPALIGN_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "WPGLOB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zWPGLOB_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPCR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPCR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPLIST")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPLIST_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPDSP")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPDSP_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "FILCLR")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zFILCLR_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPADD")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPADD_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPREM")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPREM_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPSET")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPSET_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else if (CInMsg == "GPADDGP")
			{
				iResumePos = 0;
				iCancelPos = 100;
				cDBase->DB_ActiveBuffSet(2);
				cDBase->DB_ClearBuff();
				pNext = new zGPADDGP_Mnu();
				pNext->Init(cDBase, -1);
				this->DoMenu(CInMsg, Pt);
			}
			else
			{
				bNextBlock = TRUE;
			}

			if (bNextBlock) //SECOND IF BLOCK CONTINUATION
			{
				if (CInMsg == "FILALL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFILALL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				if (CInMsg == "TEXTCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTEXTCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPREMGP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPREMGP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "COL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCOL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FILSET")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSETFIL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NDMOLAB2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNDMOLAB2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DES")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDES_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHVIS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHVIS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SHOWALL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSHOWALL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "HIDE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zHIDE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LSETLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLSETLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BSETLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBSETLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TSETLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTSETLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "COPYROT2D")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCOPYROT2D_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LSETACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLSETACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BSETACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBSETACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TSETACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTSETACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LSETDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLSETDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BSETDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBSETDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TSETDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTSETDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LSETCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLSETCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BSETCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBSETCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TSETCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTSETCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DSPGP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDSPGP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DSPALL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDSPALL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SELINV")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSELINV_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DSPSEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDSPSEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DELAY")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDELAY_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ECHO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zECHO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBAR2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBAR2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESDISPOFF")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESDISPOFF_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMOLWT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMOLWT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMOLWM")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMOLWM_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMOLWL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMOLWL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMOSOL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMOSOL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMODOT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMODOT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMODASH")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMODASH_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVMOCTR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVMOCTR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESLISTEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESLISTEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESREVCOLBAR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESREVCOLBAR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FMESHT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFMESHT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESSETCOLBAR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESCOLSETBAR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPBYTYPE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPBYTYPE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPBYMID")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPBYMID_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPNDBYCOL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPNDBYCOL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FEDGE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFEDGE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SNORM")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSNORM_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MQUADTOTRI")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMQUADTOTRI_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FFACE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFFACE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MSHELL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMSHELL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPNDBYOSYS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPNDBYOSYS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MATEDIT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMATEDIT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PREDIT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPREDIT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "OEDIT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zOEDIT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPNDBYDSYS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPNDBYDSYS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "COPYTO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCOPYTO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MOVETO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMOVETO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESLISTND")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESLISTND_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CIRCPT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCIRCPT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESSETVECSCL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESSETVECSCL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "REFLECT2D")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zREFLECT2D_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SURFUNTRIM")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSURFUNTRIM_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MATLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMATLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MMESHTET")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMMESHTET_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MMAT8")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMMAT8_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TBCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTBCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SOLLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSOLLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SOLCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSOLCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SPGMOSYS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSPGMOSYS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "AMEAS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zAMEAS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LNC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLNC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ACR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zACR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHKJAC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHKJAC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "STEPCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSTEPCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RACR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRACR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SOLVE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSOLVE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FLUXCR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFLUXCR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELMASS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELMASS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NODEX")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNODEX_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NODEY")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNODEY_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NODEZ")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNODEZ_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CELM")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCELM_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHKSHELLASP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHKSHELLASP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHKTETCOL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHKTETCOL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHKCIRCUMSPH")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHKCIRCUMSPH_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BDOFA")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBDOFA_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BDOFB")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBDOFB_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "KNOTINS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zKNOTINS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "KNOTMOD")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zKNOTMOD_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRSPGT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRSPGT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELMOSHELLMCYS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELMOSHELLMCYS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRSPGR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRSPGR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHK2D")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHK2D_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESDELAY")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESDELAY_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESLSTRESP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESLSTRESP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESVECLIST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESVECLIST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESVEC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESVEC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESVECDEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESVECDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESFRAMES")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESFRAMES_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SOLACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSOLACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "STEPACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSTEPACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MMESHAF")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMMESHAF_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				//saeed_start
				else if (CInMsg.CompareNoCase("EXP04") == 0)
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					cDBase->S_Des();
					pNext = new zEXP04_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg.CompareNoCase("EXP05") == 0)
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					cDBase->S_Des();
					pNext = new zEXP05_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				//saeed_end
				else if (CInMsg == "EXTRACT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zEXTRACT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SDSEC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSDSEC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MMESHSZ")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMMESHSZ_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MMESHBZ")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMMESHBZ_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FINDNODE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFINDNODE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRMASS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRMASS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRPCOMP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRPCOMP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else
				{
					bNextBlock2 = TRUE;
				}
			}
			//THIRD IF BLOCK CONTINUATION
			//INSERT NEW FUNCTIONS BLOWS R
			if (bNextBlock2)
			{
				if (CInMsg == "ELREV")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELREV_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBUSH")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBUSH_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBT2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBT2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TEMPD")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTEMPD_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GRAV")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGRAV_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TEST")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTEST_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SELCURLAY")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSELCURLAY_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMSCL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMSCL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMA")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMA_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMANG")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMANG_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMH")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMH_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMV")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMV_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIML")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIML_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMCL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMCL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMDRAG")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMDRAG_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DIMD")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDIMD_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "DEL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zDEL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELINSSPG")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELINSSPG_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MODINCNO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMODINCNO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MODLAYNO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMODLAYNO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PTSONCIR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPTSONCIR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LNTANCIR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLNTANCIR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LNTAN2CIR")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLNTAN2CIR_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LABGAP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLABGAP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LABGAPMP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLABGAPMP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESGRAPHRESP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESGRAPHRESP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CVSPLIT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCVSPLIT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TRIM")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTRIM_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NDEQLAB")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNDEQLAB_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "CHKCOUNT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCHKCOUNT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESLABRESP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESLABRESP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BOFFY")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBOFFY_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BOFFZ")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBOFFZ_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "COLINC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCOLINC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBCHAN2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBCHAN2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "SELRBENODE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zSELRBENODE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PRBI2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPRBI2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESENVMAX")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESENVMAX_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESENVMIN")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESENVMIN_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESSCALE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESSCALE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MESHINT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMESHINT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MESHINTWP")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMESHINTWP_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESDIVINTO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESDIVINTO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELSWEEPNDS")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELSWEEPNDS_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELSWEEPNDB")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELSWEEPNDB_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ORTHO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zORTHO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELMOLAB2")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELMOLAB2_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "QMORPH")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zQMORPH_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "COLPID")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zCOLPID_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "RESLSTRESPFULL")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zRESLSTRESPFULL_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "HLIMIT")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zHLIMIT_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "EXPINC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zEXPINC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "MODINCNO")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zMODINCNO_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "PTSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zPTSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NDSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zNDSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "TXTSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zTXTSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "BMSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zBMSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "WPLSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zWPLSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "ELSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zELSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "EDSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zEDSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "FCSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zFCSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "LMSIZE")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zLMSIZE_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "GPBYINC")
				{
					iResumePos = 0;
					iCancelPos = 100;
					cDBase->DB_ActiveBuffSet(2);
					cDBase->DB_ClearBuff();
					pNext = new zGPBYINC_Mnu();
					pNext->Init(cDBase, -1);
					this->DoMenu(CInMsg, Pt);
				}
				else if (CInMsg == "NULL")
				{
					outtext2("// COMMAND:");
				}
				else if (CInMsg == "MouseInp")
				{

				}
				else
				{
					outtext2("// COMMAND:");
				}
			}
		}
		else
		{
			outtext2("// COMMAND:");
			iStat = 0;
		}
	}
	CInMsg = "NULL";
	return RetVal;
}

BOOL zMnu::isNULL()
{
	BOOL brc = FALSE;
	if (pNext == NULL)
		brc = TRUE;
	return(brc);
}

int zMnu::ExtractPt(CString mCInMsg, C3dVector* ReturnPt)
{
	C3dVector C_TmpPt;
	int iIsValid = 0;
	int iC = 0;
	int iCommaNo = 0;
	int iComPos[2];
	CString CXtxt;
	CString CYtxt;
	CString CZtxt;

	int iLen = mCInMsg.GetLength();

	for (iC = 0; iC <= iLen - 1; iC++)
	{
		if (mCInMsg[iC] == ',' || mCInMsg[iC] == ' ' || mCInMsg[iC] == '\t')
		{
			iComPos[iCommaNo] = iC;
			iCommaNo++;
		}
	}

	if (iCommaNo == 0)
	{
		CXtxt = mCInMsg;
		CYtxt = '0';
		CZtxt = '0';
	}
	else if (iCommaNo == 1)
	{
		CXtxt = mCInMsg.Left(iComPos[0]);
		CYtxt = mCInMsg.Right(iLen - iComPos[0] - 1);
		CZtxt = '0';
	}
	else if (iCommaNo == 2)
	{
		CXtxt = mCInMsg.Left(iComPos[0]);
		CYtxt = mCInMsg.Mid(iComPos[0] + 1, iComPos[1] - iComPos[0] - 1);
		CZtxt = mCInMsg.Right(iLen - iComPos[1] - 1);
	}
	//pTextDia->OutStr(CXtxt+' '+CYtxt+' '+CZtxt);
	//ReturnPt->x = atof(CXtxt);
	//ReturnPt->y = atof(CYtxt);
	//ReturnPt->z = atof(CZtxt);
	ReturnPt->x = evaluate(CXtxt.GetString());
	ReturnPt->y = evaluate(CYtxt.GetString());
	ReturnPt->z = evaluate(CZtxt.GetString());
	mCInMsg = "11";
	//-------------------REMOVE------------

	iIsValid = 1;

	return iIsValid;
}

int zMMESHAF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}

			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			outtext2("// ENTER ELEMENT SIZE");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->S_Des();
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->MeshSurfAF(cDBase->OTemp, ptNo.x);
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

//saeed_start
int zEXP04_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		C3dVector ptNo;
		CPoint Pt;
		if (CInMsg.CompareNoCase("C") == 0 || CInMsg.CompareNoCase("CANCEL") == 0) //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			iStat = 100;
		}
		// ======================================================================
		if (iStat == 0) { // initializing
			SeedVals.IsSeedMode = true;
			cDBase->DB_ClearBuff();
			iStat = 1;
		}
		// ======================================================================
		if (iStat == 1) { // select surface(s)
			SeedVals.SelectLock = false;
			SeedVals.SelectSurface = true;
			SeedVals.SelectSurfaceCurves = false;
			outtextMultiLine("\r\nEXP04", 1);
			outtext1("1 >>");
			nCancel = 1;
			outtext1("Select Surface(s) containing curves.");
			outtext1("Pick Surface(s) >> Right Click >> Done");
			LastRequest = "// Select Surface(s) containing curves >> Right Click >> Done >>";
			outtextMultiLine(LastRequest, 2);
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			cDBase->DB_ClearBuff();
			cDBase->S_Des();
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_EXP04_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		if (iStat == 2 || iStat == 3) { // select curve(s) (first || after first)
			SeedVals.SelectLock = false;
			SeedVals.SelectSurface = false;
			SeedVals.SelectSurfaceCurves = true;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(13);
			if (iStat == 2) { // first entrance
				cDBase->SaveOrResetTempSeeds_EXP04("Reset");
				SeedVals.InputedSeedNumbers = 0;
				cDBase->AddOrRemoveTempSeeds_EXP04();
				outtext1("2 >>");
				nCancel = 2;
				outtext1("Select Surface Curve(s) to set Number Of Seeds.");
				outtext1("Pick Surface Curve(s) >> Right Click >> Done");
				outtext1("Also after selection, you can: A-press mouse middle button or B-press Enter or C-press D/d and Enter");
				iResumePos = 4;
			}
			else {
				iResumePos = 5;
				iNoPos = 9;
			}
			cDBase->S_Des(); // deselect all
			LastRequest = "// Pick Surface Curve(s) >> Right Click >> Done >>";
			outtextMultiLine(LastRequest, 2);
			iCancelPos = 100;
			pNext = new zSEL_EXP04_Mnu();
			if (iStat == 2) {
				pNext->Init(cDBase, 1);
			}
			else {
				pNext->Init(cDBase, 2);
			}
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		if (iStat == 4 || iStat == 5) { // input seed number  (first || after first)
			SeedVals.SelectLock = true;
			if (cDBase->S_Count > 0) {
				if (iStat == 4) { // first entrance
					outtext1("3 >>");
					nCancel = 3;
					outtext1("Input Seed Numbers (minimum 4 or 0 to Clear) >> Press Enter");
					outtext1("Seed Numbers applies to each selected curve.");
					outtext1("Minimum value of Seed Numbers is 4");
					outtext1("Also you can input 0 to Clear mesh seeds on selected curve(s).");
				}
				SetFocus();
				if (iStat == 4) {
					iResumePos = 6;
				}
				else {
					iResumePos = 7;
				}
				iCancelPos = 100;
				SeedVals.SelectLock = true;
				pNext = new zKEY_EXP04_Mnu();
				pNext->Init(cDBase, 1);
				DoNext(&CInMsg, Pt);
			}
			else
			{
				iStat = 3;
			}
		}
		// ======================================================================
		if (iStat == 6 || iStat == 7) { // apply mesh seeds  (first || after first)
			cDBase->AddOrRemoveTempSeeds_EXP04();
			if (iStat == 6) {
				iStat = 8;
			}
			else {
				iStat = 9;
			}
		}
		// ======================================================================
		if (iStat == 8 || iStat == 9) { //  ask if continue select curve(s) (first || after first)
			SeedVals.SelectLock = true;
			if (iStat == 8) { // first entrance
				outtext1("4 >>");
				nCancel = 4;
				outtext1("Enter Y/Yes to select the next curve(s), or N/No to finish.");
				outtext1("Also you can select Yes or No by Right Click.");
			}
			iResumePos = 3;
			iNoPos = 10;
			iCancelPos = 100;
			pNext = new zKEY_EXP04_Mnu();
			pNext->Init(cDBase, 2);
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		if (iStat == 10) { // do mesh
			cDBase->SaveOrResetTempSeeds_EXP04("Save");
			outtext1("5 >>");
			outtextMultiLine("EXP04 Applied successfully.\r\n", 1);
			outtext2("EXP04 Applied successfully.");
		}
		// ======================================================================
		if (iStat == 100) // cancel
		{
			cDBase->SaveOrResetTempSeeds_EXP04("Cancel");
			outtextSprintf("%i >>", nCancel + 1, 0.0, true, 1);
			outtextMultiLine("EXP04 Canceled successfully.\r\n", 1);
			outtext2("EXP04 Canceled successfully.");
		}
		// ======================================================================
		if (iStat == 10 || iStat == 100) // do mesh OR cancel
		{
			SeedVals.SelectLock = false;
			SeedVals.IsSeedMode = false;
			SeedVals.SelectSurface = true;
			SeedVals.SelectSurfaceCurves = false;
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			cDBase->DB_ClearBuff();
			cDBase->S_Des();
			outtext2("");
			RetVal = 1;
		}
	}
	return RetVal;
}
//saeed_end

//saeed_start
int zEXP05_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		C3dVector ptNo;
		CPoint Pt;
		if (CInMsg.CompareNoCase("C") == 0 || CInMsg.CompareNoCase("CANCEL") == 0) //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			iStat = 100;
		}
		// ======================================================================
		if (iStat == 0) { // initializing
			SeedVals.IsSeedMode = true;
			iStat = 1;
		}
		// ======================================================================
		if (iStat == 1) { // select surface(s)
			SeedVals.SelectLock = false;
			SeedVals.SelectSurface = true;
			SeedVals.SelectSurfaceCurves = false;
			outtextMultiLine("\r\nEXP05", 1);
			outtext1("1 >>");
			nCancel = 1;
			outtext1("Select Surface(s) containing mesh seeds.");
			outtext1("Pick Surface(s) >> Right Click >> Done");
			LastRequest = "// Select Surface(s) containing mesh seeds >> Right Click >> Done >>";
			outtextMultiLine(LastRequest, 2);
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			cDBase->DB_ClearBuff();
			cDBase->S_Des(); // deselect all
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_EXP04_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		// (preview setted seeds)
		if (iStat == 2 || iStat == 3) { // input element size of mesh (first || after first)
			SeedVals.SelectLock = true;
			if (iStat == 2) { // first entrance
				outtext1("2 >>");
				nCancel = 2;
				outtext1("Input Element Size Of Mesh >> Press Enter");
				double minElementSize = cDBase->GetdTol();
				outtextSprintf("Minimum Element Size value = %.6g", 0, minElementSize, false, 1);
				cDBase->SaveOrResetTempSeeds_EXP04("Reset");
				SeedVals.InputedSeedNumbers = 0;
				cDBase->AddOrRemoveTempSeeds_EXP04();
				cDBase->S_Des(); // deselect all
			}
			SetFocus();
			if (iStat == 2) {
				iResumePos = 4;
			}
			else {
				iResumePos = 5;
			}
			iCancelPos = 100;
			SeedVals.SelectLock = true;
			pNext = new zKEY_EXP04_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		// (show new points with setted seeds)
		if (iStat == 4 || iStat == 5) { //  ask if continue select curve(s) (first || after first)
			SeedVals.SelectLock = true;
			if (iStat == 4) { // first entrance
				outtext1("3 >>");
				nCancel = 3;
				outtext1("Enter Y/Yes to finish, or N/No to input New Element Size Of Mesh.");
				outtext1("Also you can select Yes or No by Right Click.");
			}
			iResumePos = 6;
			iNoPos = 3;
			iCancelPos = 100;
			pNext = new zKEY_EXP04_Mnu();
			pNext->Init(cDBase, 4);
			DoNext(&CInMsg, Pt);
		}
		// ======================================================================
		// (show meshing)
		if (iStat == 6) { // do mesh
			////cDBase->SaveOrResetTempSeeds_EXP04("Save");
			cDBase->MeshSurfAF_EXP04();
			cDBase->OTemp->Clear();
			cDBase->SaveOrResetTempSeeds_EXP04("Cancel");
			outtext1("4 >>");
			outtextMultiLine("EXP05 Applied successfully.\r\n", 1);
			outtext2("EXP05 Applied successfully.");
		}
		// ======================================================================
		if (iStat == 100) // cancel
		{
			cDBase->SaveOrResetTempSeeds_EXP04("Cancel");
			outtextSprintf("%i >>", nCancel + 1, 0.0, true, 1);
			outtextMultiLine("EXP05 Canceled successfully.\r\n", 1);
			outtext2("EXP05 Canceled successfully.");
		}
		// ======================================================================
		if (iStat == 6 || iStat == 100) // do mesh OR cancel
		{
			SeedVals.SelectLock = false;
			SeedVals.IsSeedMode = false;
			SeedVals.SelectSurface = true;
			SeedVals.SelectSurfaceCurves = false;
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			cDBase->DB_ClearBuff();
			cDBase->S_Des();
			outtext2("");
			RetVal = 1;
		}
	}
	return RetVal;


	//////DoNext(&CInMsg, Pt);
	//////if (pNext == NULL)
	//////{
	//////	C3dVector ptNo;
	//////	CPoint Pt;
	//////	if (CInMsg.CompareNoCase("C") == 0 || CInMsg.CompareNoCase("CANCEL") == 0) //Common Options
	//////	{
	//////		RetVal = 2;
	//////		cDBase->FILTER.SetAll();
	//////		iStat = 100;
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 0) { // initializing
	//////		SeedVals.SelectLock = true;
	//////		SeedVals.IsSeedMode = true;
	//////		SeedVals.SelectSurface = false;
	//////		SeedVals.SelectSurfaceCurves = true;
	//////		cDBase->FILTER.Clear();
	//////		cDBase->FILTER.SetFilter(13);
	//////		cDBase->S_Des(); // deselect all
	//////		//cDBase->RemoveTempSeeds_EXP04();
	//////		cDBase->SaveOrResetTempSeeds_EXP04("Reset");
	//////		iStat = 1;
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 1) { // input element size of mesh
	//////		outtextMultiLine("\r\nEXP04", 1);
	//////		iResumePos = 2;
	//////		iCancelPos = 100;
	//////		pNext = new zKEY_EXP04_Mnu();
	//////		pNext->Init(cDBase, 3);
	//////		DoNext(&CInMsg, Pt);
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 2 || iStat == 3) { // select curve(s) (first || after first)
	//////		SeedVals.SelectLock = false;
	//////		cDBase->S_Des(); // deselect all
	//////		ptNo = cDBase->DB_PopBuff();
	//////		SeedVals.InputedMeshElementSize = ptNo.x;
	//////		if (iStat == 2) { // first entrance
	//////			outtext1("2 >>");
	//////			outtext1("Select Surface Curve(s) to set Number Of Seeds.");
	//////			outtext1("Pick Surface Curve(s) >> Right Click >> Done");
	//////			outtext1("Also after selection, you can: A-press mouse middle button or B-press Enter or C-press D/d and Enter");
	//////			iResumePos = 4;
	//////		}
	//////		else {
	//////			iResumePos = 5;
	//////			iNoPos = 9;
	//////		}
	//////		LastRequest = "// Pick Surface Curve(s) >> Right Click >> Done >>";
	//////		outtextMultiLine(LastRequest, 2);
	//////		iCancelPos = 100;
	//////		pNext = new zSEL_EXP04_Mnu();
	//////		if (iStat == 2) {
	//////			pNext->Init(cDBase, 1);
	//////		}
	//////		else {
	//////			pNext->Init(cDBase, 2);
	//////		}
	//////		DoNext(&CInMsg, Pt);
	//////		//cDBase->S_Count_Initial = cDBase->S_Count;
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 4 || iStat == 5) { // input seed number  (first || after first)
	//////		//int newSelects;
	//////		SeedVals.SelectLock = true;
	//////		//newSelects = cDBase->S_Count - cDBase->S_Count_Initial;
	//////		//if (newSelects > 0) {
	//////		if (cDBase->S_Count > 0) {
	//////			if (iStat == 4) { // first entrance
	//////				outtext1("3 >>");
	//////				outtext1("Input Seed Numbers (minimum 4 or 0 to Clear) >> Press Enter");
	//////				outtext1("Seed Numbers applies to each selected curve.");
	//////				outtext1("Minimum value of Seed Numbers is 4");
	//////				outtext1("Also you can input 0 to Clear mesh seeds on selected curve(s).");
	//////			}
	//////			SetFocus();
	//////			if (iStat == 4) {
	//////				iResumePos = 6;
	//////			}
	//////			else {
	//////				iResumePos = 7;
	//////			}
	//////			iCancelPos = 100;
	//////			SeedVals.SelectLock = true;
	//////			pNext = new zKEY_EXP04_Mnu();
	//////			pNext->Init(cDBase, 1);
	//////			DoNext(&CInMsg, Pt);
	//////		}
	//////		else
	//////		{
	//////			iStat = 3;
	//////		}
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 6 || iStat == 7) { // apply mesh seeds  (first || after first)
	//////		ptNo = cDBase->DB_PopBuff();
	//////		SeedVals.InputedSeedNumbers = (int)ptNo.x;
	//////		cDBase->AddOrRemoveTempSeeds_EXP04();
	//////		if (iStat == 6) {
	//////			iStat = 8;
	//////		}
	//////		else {
	//////			iStat = 9;
	//////		}
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 8 || iStat == 9) { //  ask if continue select curve(s) (first || after first)
	//////		SeedVals.SelectLock = true;
	//////		if (iStat == 8) { // first entrance
	//////			outtext1("4 >>");
	//////			outtext1("Enter Y/Yes to select the next curve(s), or N/No to finish.");
	//////			outtext1("Also you can select Yes or No by Right Click.");
	//////		}
	//////		iResumePos = 3;
	//////		iNoPos = 10;
	//////		iCancelPos = 100;
	//////		pNext = new zKEY_EXP04_Mnu();
	//////		pNext->Init(cDBase, 2);
	//////		DoNext(&CInMsg, Pt);
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 10 || iStat == 11) { // select surfaces (first || after error)
	//////		SeedVals.SelectLock = false;
	//////		SeedVals.SelectSurface = true;
	//////		SeedVals.SelectSurfaceCurves = false;
	//////		if (iStat == 10) {
	//////			outtext1("5 >>");
	//////			outtext1("Select Surface(s) to mesh.");
	//////			outtext1("Pick Surface(s) >> Right Click >> Done");
	//////			LastRequest = "// Select Surface(s) to mesh >> Right Click >> Done >>";
	//////			outtextMultiLine(LastRequest, 2);
	//////			cDBase->FILTER.Clear();
	//////			cDBase->FILTER.SetFilter(15);
	//////			cDBase->DB_ClearBuff();
	//////			cDBase->S_Des();
	//////		}
	//////		else {
	//////			//outtextSprintf("Selected Curves = %i", cDBase->S_Count, 0.0, true, 1);
	//////		}
	//////		iResumePos = 12;
	//////		iNoPos = 11;
	//////		iCancelPos = 100;
	//////		pNext = new zSEL_EXP04_Mnu();
	//////		pNext->Init(cDBase, 3);
	//////		DoNext(&CInMsg, Pt);
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 12) { // do mesh
	//////		char S1[80];
	//////		int newSelects;
	//////		newSelects = cDBase->S_Count;
	//////		if (newSelects > 0) {
	//////			cDBase->S_Save(cDBase->OTemp);
	//////			sprintf_s(S1, "Selected Surfaces = %i", newSelects);
	//////			outtext1(S1);
	//////			SeedVals.SelectLock = true;
	//////			cDBase->MeshSurfAF_EXP04(cDBase->OTemp, SeedVals.InputedMeshElementSize);
	//////			//cDBase->OTemp->Clear();
	//////			outtextMultiLine("EXP04 Applied successfully.\r\n", 1);
	//////			outtext2("EXP04 Applied successfully.");
	//////		}
	//////		else
	//////		{
	//////			iStat = 0;
	//////		}
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 100) // cancel
	//////	{
	//////		outtextMultiLine("EXP04 Canceled successfully.\r\n", 1);
	//////		outtext2("EXP04 Canceled successfully.");
	//////	}
	//////	// ======================================================================
	//////	if (iStat == 12 || iStat == 100) // do mesh OR cancel
	//////	{
	//////		SeedVals.SelectLock = false;
	//////		SeedVals.IsSeedMode = false;
	//////		SeedVals.SelectSurface = true;
	//////		SeedVals.SelectSurfaceCurves = false;
	//////		if (iStat == 12) {
	//////			cDBase->SaveOrResetTempSeeds_EXP04("Save");
	//////		}
	//////		//tempSeedCurves->DeleteExtTrimLoop();
	//////		cDBase->OTemp->Clear();
	//////		cDBase->FILTER.SetAll();
	//////		cDBase->DB_ClearBuff();
	//////		cDBase->S_Des();
	//////		outtext2("");
	//////		RetVal = 1;
	//////	}
	//////}
	//////return RetVal;
}
//saeed_end

int zPT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if ((CInMsg == "C") || (CInMsg == "D"))  //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				cDBase->DB_AddPtBuff(cDBase->S_Buff[cDBase->S_Count - 1]->Get_Centroid());
				iStat = 2;
				cDBase->S_Count--;
			}
			else if (CInMsg == "BET")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zBET_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "LAB")
			{
				iResumePos = 1;
				iCancelPos = 0;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "PROJ")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zPROJ_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "TRAN")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zTRAN_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "PTRAN")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zPTRAN_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "ONSCR")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zONSCR_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "INT")
			{
				iResumePos = 2;
				iCancelPos = 0;
				pNext = new zINT_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "MouseInp")
			{
				C3dVector p2;
				p2 = cDBase->PickPointToGlobal2(Pt); //Was PickPointToGlobal1(Pt)
				cDBase->DB_AddPtBuff(p2);
				cDBase->bPICK = TRUE;
				iStat = 2;
			}
			else
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				C3dVector OutPt = cDBase->WPtoGlobal(GetPt);
				cDBase->DB_AddPtBuff(OutPt);
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			C3dVector vP;
			vP = cDBase->DB_GetBuff();
			char S1[80];
			sprintf_s(S1, "%f,%f,%f", vP.x, vP.y, vP.z);
			outtext2(S1);
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		//saeed_start
		/*
		//saeed_end
		if (CInMsg2 == "C") //Common Options
		//saeed_start
		*/
		if (CInMsg.CompareNoCase("C") == 0) //Common Options
			//saeed_end
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			//saeed_start
			/*
			//saeed_end
			if ((CInMsg2=="D") || (CInMsg2==""))
			//saeed_start
			*/
			if (CInMsg.CompareNoCase("D") == 0 || CInMsg2 == "")
				//saeed_end
			{
				iStat = 2;
			}
			else if (CInMsg == "LAB")
			{
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, iT);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "RELTO")
			{
				iResumePos = 2;
				iCancelPos = 100;
				cDBase->FILTER.SetAll();
				pNext = new zRELTO_Mnu();
				pNext->Init(cDBase, iT);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "SELALL")
			{
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zSELALL_Mnu();
				pNext->Init(cDBase, iT);
				DoNext(&CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

//saeed_start
int zSEL_EXP04_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg.CompareNoCase("C") == 0 || CInMsg.CompareNoCase("CANCEL") == 0) { // Common Options
			RetVal = 2; // cancel
			goto MenuEnd;
		}
		if (iStat == 0) {
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1) {
			if (CInMsg == "") {
				outtextMSG2("[Done]");
			}
			else if (CInMsg.CompareNoCase("D") == 0 || CInMsg.CompareNoCase("DONE") == 0 || CInMsg == "[Done]") {
				//C3dVector GetPt;
				if (iT == 1) { // ========================= first selecting of curve(s)
					if (cDBase->S_Count > 0) {
						iStat = 2;
						RetVal = 1;
						//GetPt.Set(0.0, 1.0, 0.0); // ------ done or yes
					}
					else {
						outtextMultiLine("\r\nERROR >>> At least one Curve must be selected. [!!!]", 2);
						outtextMultiLine(LastRequest, 2);
						//GetPt.Set(0.0, 1.0, -1.0); // ------no or error or warning
					}
				}
				else if (iT == 2) { // ========================= continue selecting of curve(s)
					//if (cDBase->S_Count > cDBase->S_Count_Initial) {
					if (cDBase->S_Count) {
						iStat = 2;
						RetVal = 1;
						//GetPt.Set(0.0, 2.0, 0.0); // ------ done or yes
					}
					else {
						//outtextMultiLine("\r\nERROR >>> At least one new Curve must be added to the selection. [!!!]", 2);
						outtextMultiLine("\r\nERROR >>> At least one Curve must be selected. [!!!]", 2);
						//outtextMultiLine(LastRequest, 2);
						iStat = 2;
						RetVal = 3; // ------ no or error or warning
						//GetPt.Set(0.0, 2.0, -1.0);
					}
				}
				else if (iT == 3) { // ========================= select surface(s)
					if (cDBase->S_Count > 0) {
						iStat = 2;
						RetVal = 1;
						//GetPt.Set(0.0, 3.0, 0.0); // ------ done or yes
					}
					else {
						outtextMultiLine("\r\nERROR >>> At least one Surface must be selected. [!!!]", 2);
						outtextMultiLine(LastRequest, 2);
						//iStat = 2;
						//RetVal = 3;
						//GetPt.Set(0.0, 2.0, -1.0); // ------ no or error or warning
					}
				}
				//cDBase->DB_AddPtBuff(GetPt);
			}
			else if (CInMsg != "MouseInp") {
				outtextMultiLine("\r\nERROR >>> Wrong input. Right Click >> Done Or Press Enter. [!!!]", 2);
				outtextMultiLine(LastRequest, 2);
				SetFocus(); // ========================= wrong input
			}
		}
	}
MenuEnd:
	return RetVal;
}
//saeed_end

int zNDCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2;
	CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if ((CInMsg2 == "C") || (CInMsg2 == "D"))//Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER LOCATION OR PICK FROM SCREEN");
			iStat = 1;
		}
		if (iStat == 1)
		{
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu;
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			if (cDBase->DB_BuffCount > initCnt)
			{
				cDBase->AddNode(cDBase->DB_PopBuff(), -1, 1, 1, 4, 0, 0);
				outtext1("1 Node Created.");
			}
			iStat = 1;
			this->DoMenu(CInMsg, Pt);
		}
		if (iStat == 100)  //Cancel Case
		{
			RetVal = 2;
		}
	}
MenuEnd:
	return RetVal;
}

int zBET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER FIRST LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// ENTER SECOND LOCATION");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			p1 = cDBase->GlobaltoWP(p1);
			p2 = cDBase->GlobaltoWP(p2);
			WP_Object* pWPlane = (WP_Object*)cDBase->DB_Obj[cDBase->iWP];
			int bWPMode = pWPlane->iWPMode;

			if (bWPMode == 1) //polar coords
			{
				if (p2.y < p1.y)
					p2.y += 360.0;
			}
			p1 += p2;
			p1 /= 2;
			p1 = cDBase->WPtoGlobal(p1);
			cDBase->DB_AddPtBuff(p1);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTVEC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (CInMsg == "KEY") //Common Options
		{
			iStat = 4;
		}
		else if (CInMsg == "PICK")
		{
			iStat = 1;
		}
		else if (iStat == 0)
		{
			outtext2("// ENTER TRANSLATION METHOD (PICK or KEY)");
		}
		if (iStat == 1)
		{
			outtext2("// PICK FIRST LOCATION");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// PICK SECOND LOCATION");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			iStat = 5;
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			p2 = cDBase->GlobaltoWP(p2);
			p1 = cDBase->GlobaltoWP(p1);
			p2 -= p1;
			cDBase->DB_AddPtBuff(p2);
		}
		if (iStat == 4)
		{
			outtext2("// ENTER TRANSLATION");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTRAN_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER OR PICK BASE LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// SPECIFY TRANSLATION");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			p1 = cDBase->GlobaltoWP(p1);
			p1 += p2;
			p1 = cDBase->WPtoGlobal(p1);
			cDBase->DB_AddPtBuff(p1);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPTRAN_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER OR PICK BASE LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// ENTER POLAR TRANSLATION (r,theta,z)");
			SetFocus();
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			p1 = cDBase->GlobaltoWP(p1);
			p1.x += p2.x * cos(p2.y * D2R);
			p1.y += p2.x * sin(p2.y * D2R);
			p1.z += p2.z;
			p1 = cDBase->WPtoGlobal(p1);
			cDBase->DB_AddPtBuff(p1);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zONSCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER OR PICK BASE LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			C3dVector p1;
			p1 = cDBase->DB_PopBuff();
			p1 = cDBase->GlobaltoWP(p1);
			p1.z = 0;
			p1 = cDBase->WPtoGlobal(p1);
			cDBase->DB_AddPtBuff(p1);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPTCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2;
	CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if ((CInMsg2 == "C") || (CInMsg2 == "D"))//Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER LOCATION OR PICK FROM SCREEN");
			iStat = 1;
		}
		if (iStat == 1)
		{
			iResumePos = 2;
			iCancelPos = 2;
			pNext = new zPT_Mnu;
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			C3dVector vP;
			if (cDBase->DB_BuffCount > 0)
			{
				vP = cDBase->DB_GetBuff();
				//char S1[80];
				//sprintf_s(S1,"%d,%d,%d",vP.x,vP.y,vP.z);
				//outtext2(S1);
				cDBase->AddPt(vP, -1, TRUE);
				cDBase->DB_ClearBuff();
				outtext1("1 Point Created.");
			}
			iStat = 1;
			this->DoMenu(CInMsg, Pt);
		}
		if (iStat == 2)  //Cancel Case
		{
			RetVal = 2;
		}
	}
MenuEnd:
	return RetVal;
}

int zFINDNODE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER LOCATION X,Y,Z");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->FindNode(ptVec);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLNANG_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK LOCATION OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// ENTER ANGLE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			C3dVector Ang;
			double dAng;

			C3dVector p1;
			C3dVector p2;
			C3dVector Ext;
			C3dVector ExtGlob;
			Ang = cDBase->DB_PopBuff();
			dAng = Ang.x;
			dAng = Ang.x * Pi / 180;
			Ext.Set(cDBase->WPSize * 1.1 * cos(dAng), cDBase->WPSize * 1.1 * sin(dAng), 0);
			ExtGlob = cDBase->GlobaltoWP3(Ext);
			p1 = cDBase->DB_PopBuff();
			p2 = p1;
			p2 += ExtGlob;
			cDBase->AddLN(p1, p2, -1, TRUE);
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLNX_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector Ext;
			C3dVector ExtGlob;
			Ext.Set(cDBase->WPSize * 1.1, 0, 0);
			ExtGlob = cDBase->GlobaltoWP3(Ext);
			p1 = cDBase->DB_PopBuff();
			p2 = p1;
			p1 -= ExtGlob;
			p2 += ExtGlob;
			cDBase->AddLN(p1, p2, -1, TRUE);
			outtext1("1 Line Created.");
			iStat = 0;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLN_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			iStat = 1;
		}
		if (iStat == 1)
		{
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->FILTER.Save();
			cDBase->bIsDrag = TRUE;
			p1 = cDBase->DB_PopBuff();
			cDBase->AddDragLN(p1);
			cDBase->vLS = p1;
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddLNfromDrag(p2);
			outtext1("1 Line Created.");
			iStat = 1;
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			this->DoMenu(CInMsg, Pt);
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMA_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			//cDBase->FILTER.Save();
			p1 = cDBase->DB_PopBuff();
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddDragDIMA(p1, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector p2;
			p3 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p3);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMANG_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			outtext2("// ANGULAR DIMENSION BY 3 POINTS");
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			p1 = cDBase->DB_PopBuff();
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			p2 = cDBase->DB_PopBuff();
			outtext2("// PICK THIRD POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			cDBase->bIsDrag = TRUE;
			p3 = cDBase->DB_PopBuff();
			cDBase->AddDragDIMANG(p2, p1, p3);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			pIns = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(pIns);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMH_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			//cDBase->FILTER.Save();
			p1 = cDBase->DB_PopBuff();
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddDragDIMH(p1, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector p2;
			p3 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p3);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMV_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			//cDBase->FILTER.Save();
			p1 = cDBase->DB_PopBuff();
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddDragDIMV(p1, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector p2;
			p3 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p3);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIML_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			p1 = cDBase->DB_PopBuff();
			outtext2("// ENTER LEADER TEXT");
			SetFocus();
			iStat = 2;
		}
		else if (iStat == 2)
		{
			sText = CInMsg;
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			cDBase->bIsDrag = TRUE;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddDragDIML(sText, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector p2;
			p3 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p3);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMR_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CIRCLE ");
			iStat = 2;
		}
		else if (iStat == 2)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7) &&
					(cDBase->S_Buff[cDBase->S_Count - 1]->iType == 3))
				{
					pC = (NCircle*)cDBase->S_Buff[cDBase->S_Count - 1];
					p2 = pC->Get_Centroid();
					cDBase->S_Count = S_initCnt;
					iStat = 3;
				}
				else
				{
					outtext1("Error: Must pick circle or arc.");
					cDBase->S_Count--;
					iStat = 1;
					this->DoMenu(CInMsg, Pt);
				}

			}
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			cDBase->AddDragDIMR(pC, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{

			p2 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p2);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->FILTER.Restore();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMCL_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CIRCLE ");
			iStat = 2;
		}
		else if (iStat == 2)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7) &&
					(cDBase->S_Buff[cDBase->S_Count - 1]->iType == 3))
				{
					pC = (NCircle*)cDBase->S_Buff[cDBase->S_Count - 1];
					cDBase->S_Count = S_initCnt;
					iStat = 3;
				}
				else
				{
					outtext1("Error: Must pick circle or arc.");
					cDBase->S_Count--;
					iStat = 1;
					this->DoMenu(CInMsg, Pt);
				}

			}
		}
		if (iStat == 3)
		{

			cDBase->AddCirCL(pC);
			outtext1("1 CL Created.");
			cDBase->ReDraw();
			cDBase->FILTER.Restore();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMDRAG_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(10);
			outtext2("// PICK DIMENSION TO DRAG ");
			iStat = 2;
		}
		else if (iStat == 2)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 10)
				{
					pD = (DIM*)cDBase->S_Buff[cDBase->S_Count - 1];
					cDBase->S_Count = S_initCnt;
					iStat = 3;
				}
				else
				{
					outtext1("Error: Must pick dimension to drag.");
					cDBase->S_Count--;
					iStat = 1;
					this->DoMenu(CInMsg, Pt);
				}

			}
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			cDBase->AddDimForDrag(pD);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{

			p1 = cDBase->DB_PopBuff();
			C3dMatrix mTran;  //not used
			pD->DragUpdate(p1, mTran);
			outtext1("1 Dim Updated.");
			cDBase->bIsDrag = FALSE;
			cDBase->Dsp_Add(pD);
			cDBase->InvalidateOGL();
			cDBase->ReDraw();
			cDBase->FILTER.Restore();
			cDBase->pDragObj = nullptr;
			iStat = 1;
			this->DoMenu(CInMsg, Pt);
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zDIMD_Mnu::DoMenu(CString CInMsg, CPoint Pt) {
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") { //Common Options
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			//cDBase->FILTER.SetAll();
			iStat = 1;
		}
		if (iStat == 1)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CIRCLE ");
			iStat = 2;
		}
		else if (iStat == 2)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7) &&
					(cDBase->S_Buff[cDBase->S_Count - 1]->iType == 3))
				{
					pC = (NCircle*)cDBase->S_Buff[cDBase->S_Count - 1];
					p2 = pC->Get_Centroid();
					cDBase->S_Count = S_initCnt;
					iStat = 3;
				}
				else
				{
					outtext1("Error: Must pick circle or arc.");
					cDBase->S_Count--;
					iStat = 1;
					this->DoMenu(CInMsg, Pt);
				}

			}
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			cDBase->AddDragDIMD(pC, p2);
			outtext2("// PICK INSERTION POINT OR TYPE COORDINATE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{

			p2 = cDBase->DB_PopBuff();
			cDBase->AddDIMfromDrag(p2);
			outtext1("1 Dim Created.");
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->FILTER.Restore();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}

MenuEnd:
	return RetVal;
}

int zLNC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			bF = TRUE; //First time in we need 2 points
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			cDBase->bIsDrag = TRUE;
			if (bF)
			{
				pLast = cDBase->DB_PopBuff();
				bF = FALSE;
			}
			cDBase->AddDragLN(pLast);
			cDBase->vLS = pLast;
			outtext2("// PICK NEXT POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddLNfromDrag(p2);
			pLast = p2;
			if (cDBase->pDragObj != nullptr)
			{
				NLine* pL = (NLine*)cDBase->pDragObj;
				pLast = pL->cPts[1]->Pt_Point;
			}
			cDBase->ReDraw();
			outtext1("1 Line Created.");
			iStat = 1;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCIRCPT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		C3dVector vN;
		vN.Set(0, 0, 1);
		vN = cDBase->GlobaltoWP3(vN);
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CIRCLE CENTRE OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			cDBase->bIsDrag = TRUE;
			p1 = cDBase->DB_PopBuff();
			cDBase->AddDragCIR(vN, p1);
			cDBase->vLS = p1;
			outtext2("// PICK OR ENTER POINT ON RADIUS");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			cDBase->bIsDrag = FALSE;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddCirCentPt(vN, p1, p2);
			outtext1("1 Circle Created.");
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCIRCR2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		C3dVector vN;
		vN.Set(0, 0, 1);
		vN = cDBase->GlobaltoWP3(vN);
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CIRCLE CENTRE OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			cDBase->bIsDrag = TRUE;
			p1 = cDBase->DB_PopBuff();
			cDBase->AddDragCIR(vN, p1);
			cDBase->vLS = p1;
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "ENTER RADIUS (", gDIM_RADSZ);
			SetFocus();
			outtext2(OutT);
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			cDBase->bIsDrag = FALSE;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			double dRad = p2.x;
			if (dRad == 0)
				dRad = gDIM_RADSZ;
			else
				gDIM_RADSZ = dRad;
			cDBase->AddCirCR(vN, p1, dRad, -1);
			outtext1("1 Circle Created.");
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLNTANCIR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		C3dVector vN;
		vN.Set(0, 0, 1);
		vN = cDBase->GlobaltoWP3(vN);
		if (CInMsg == "C") //Common Options
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			p1 = cDBase->DB_PopBuff();
			cDBase->bIsDrag = TRUE;
			cDBase->AddDragLN(p1);
			cDBase->vLS = p1;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CIRCLE ");
			iStat = 2;
		}
		if (iStat == 2)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
				iStat = 3;

			}
		}
		if (iStat == 3)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->AddCirTanPt(vN, p1, Pt);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zLNTAN2CIR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK 2 CIRCLES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
			}
			else if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear2 = Pt;
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			cDBase->AddLinTan2Cir(PNear1, PNear2);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zTEXTCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK TEXT LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			p1 = cDBase->DB_PopBuff();
			outtext2("// ENTER TEXT");
			SetFocus();
			iStat = 2;
		}
		else if (iStat == 2)
		{
			sText = CInMsg;
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "ENTER TEXT HEIGHT (", gTXT_HEIGHT);
			outtext2(OutT);
			SetFocus();
			iStat = 3;
		}
		else if (iStat == 3)
		{
			double dH;
			dH = atof(CInMsg);
			if (dH <= 0)
				dH = gTXT_HEIGHT;
			else
				gTXT_HEIGHT = dH;
			C3dVector vN, vDir, vO;
			vO.Set(0, 0, 0);
			vN.Set(0, 0, 1);
			vDir.Set(1, 0, 0);  //Text direction assume workplane X
			vO = cDBase->WPtoGlobal2(vO);
			vN = cDBase->WPtoGlobal2(vN);
			vDir = cDBase->WPtoGlobal2(vDir);
			vN -= vO;
			vDir -= vO;
			cDBase->AddText(vN, vDir, p1, sText, dH);
			outtext1("Text Added.");
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->bIsDrag = FALSE;
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zDIMSCL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "ENTER DIMENSION SIXE (", gDIM_SIZE);
			outtext2(OutT);
			SetFocus();
			iStat = 1;
		}
		else if (iStat == 1)
		{
			double dH;
			dH = atof(CInMsg);
			if (dH <= 0)
				dH = gDIM_SIZE;
			else
				gDIM_SIZE = dH;
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->bIsDrag = FALSE;
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCIR3PT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// ENTER PT1");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// ENTER PT2");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER PT3");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->Circ3Pts(p1, p2, p3);
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zARC3PT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// ENTER PT1");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// ENTER PT2");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER PT3");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->Arc3Pts(p1, p2, p3);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRECT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK FIRST POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			cDBase->bIsDrag = TRUE;
			p1 = cDBase->DB_PopBuff();
			cDBase->AddDragLN(p1);
			cDBase->vLS = p1;
			outtext2("// PICK SECOND POINT OR TYPE COORDINATE");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			cDBase->bIsDrag = FALSE;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->AddRect(p1, p2, -1);
			outtext1("1 Rectange Created.");
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLNY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector Ext;
			C3dVector ExtGlob;
			Ext.Set(0, cDBase->WPSize * 1.1, 0);
			ExtGlob = cDBase->GlobaltoWP3(Ext);
			p1 = cDBase->DB_PopBuff();
			p2 = p1;
			p1 -= ExtGlob;
			p2 += ExtGlob;
			cDBase->AddLN(p1, p2, -1, TRUE);
			outtext1("1 Line Created.");
			iStat = 0;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLNZ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK POINT OR TYPE COORDINATE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector Ext;
			C3dVector ExtGlob;
			Ext.Set(0, 0, cDBase->WPSize * 1.1);
			ExtGlob = cDBase->GlobaltoWP3(Ext);
			p1 = cDBase->DB_PopBuff();
			p2 = p1;
			p1 -= ExtGlob;
			p2 += ExtGlob;
			cDBase->AddLN(p1, p2, -1, TRUE);
			outtext1("1 Line Created.");
			iStat = 0;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zKEY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		//saeed_start
		/*
		//saeed_end
		if (CInMsg2 == "C") //Common Options
		//saeed_start
		*/
		if (CInMsg.CompareNoCase("C") == 0) //Common Options
			//saeed_end
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if ((iStat == 0))
		{
			outtext2("// KEY IN:");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if ((CInMsg == "MouseInp") && (iStat == 1))
			goto MenuEnd;
		if (iStat == 1)
		{
			C3dVector GetPt;
			int iPt = ExtractPt(CInMsg, &GetPt);
			cDBase->DB_AddPtBuff(GetPt);
			iStat = 2;
		}
		if (iStat == 2)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

//saeed_start
int zKEY_EXP04_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL) {
		if (CInMsg.CompareNoCase("C") == 0 || CInMsg.CompareNoCase("CANCEL") == 0) { // Common Options
			RetVal = 2; // cancel
			goto MenuEnd;
		}
		if ((iStat == 0)) {
			if (iT == 1) {
				LastRequest = "// Input Seed Numbers (minimum 4 or 0 to Clear) >> Press Enter:";
				outtext2(LastRequest);
				SetFocus();
			}
			else if (iT == 2) {
				LastRequest = "// Continue selecting Curve(s)? Right Click >> Yes or No >>";
				outtext2(LastRequest);
				SetFocus();
			}
			else if (iT == 3) {
				LastRequest = "// Input Element Size Of Mesh >> Press Enter:";
				outtext2(LastRequest);
				SetFocus();
			}
			else if (iT == 4) {
				LastRequest = "// Finish Process and Make Mesh by Seeds? Right Click >> Yes or No >>";
				outtext2(LastRequest);
				SetFocus();
			}
			iStat = 1;
			goto MenuEnd;
		}
		if ((CInMsg == "MouseInp") && (iStat == 1))
			goto MenuEnd;
		if (iStat == 1) {
			if (CInMsg == "") {
				if (iT == 1) {
					outtextMSG2("[0]");
				}
				else if (iT == 2 || iT == 4) {
					outtextMSG2("[Yes]");
				}
				else if (iT == 3) {
					outtextMSG2("[0]");
				}
			}
			else {
				C3dVector GetPt;
				if (iT == 1) { // ========================= an integer number for element size >= 4 or ... == 0
					int iPt = ExtractPt(CInMsg, &GetPt);
					//GetPt.Set(GetPt.x, 1.0, 0.0);
					if (GetPt.x >= 4 || GetPt.x == 0) {
						SeedVals.InputedSeedNumbers = (int)GetPt.x;
						iStat = 2;
						RetVal = 1; // ------ done or yes
					}
					else {
						outtextMultiLine("\r\nERROR >>> Minimum value = 4 or Input 0 to Clear. [!!!]", 2);
						outtext2("Please input again.");
						outtextMultiLine(LastRequest, 2);
						SetFocus(); // ------ error
					}
				}
				else if (iT == 2 || iT == 4) {// ========================= read y/n/yes/no char
					if (CInMsg.CompareNoCase("Y") == 0 || CInMsg.CompareNoCase("YES") == 0 || CInMsg == "[Yes]" ||
						CInMsg == "" || CInMsg.CompareNoCase("D") == 0 || CInMsg.CompareNoCase("DONE") == 0 || CInMsg == "[Done]") {
						//GetPt.Set(0.0, 2.0, 1.0);
						iStat = 2;
						RetVal = 1; // ------ done or yes
					}
					else if (CInMsg.CompareNoCase("N") == 0 || CInMsg.CompareNoCase("NO") == 0) {
						//GetPt.Set(0.0, 2.0, 2.0);
						iStat = 2;
						RetVal = 3; // ------ no
					}
					else {
						//GetPt.Set(0.0, 2.0, -1.0);
						outtextMultiLine("\r\nERROR >>> You should input Yes or No. [!!!]", 2);
						outtext2("Please input again.");
						if (iT == 2) {
							outtext2("Continue selecting Curve(s)?");
						}
						else if (iT == 4) {
							outtext2("Stop Editing Element Size Of Mesh?");
						}
						outtextMultiLine(LastRequest, 2);
						SetFocus(); // ------ error
					}
				}
				else if (iT == 3) { // ========================= a float number > 0
					int iPt = ExtractPt(CInMsg, &GetPt);
					double minElementSize = cDBase->GetdTol();
					//GetPt.Set(GetPt.x, 3.0, 0.0);
					if (GetPt.x >= minElementSize) {
						SeedVals.InputedMeshElementSize = GetPt.x;
						iStat = 2;
						RetVal = 1; // ------ done or yes
					}
					else {
						outtextSprintf("\r\nERROR >>> Element Size value >= %.6g [!!!]", 0, minElementSize, false, 2);
						outtext2("Please input again.");
						outtextMultiLine(LastRequest, 2);
						SetFocus(); // ------ error
					}
				}
				//cDBase->DB_AddPtBuff(GetPt);
			}
		}
	}
MenuEnd:
	return RetVal;
}
//saeed_end

int zWPALIGN_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK CENTRE POINT");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// POINT ON X");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			outtext2("// POINT ON XY");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			WP_Object* TWP = (WP_Object*)cDBase->DB_Obj[0];
			TWP->Align(p1, p2, p3);
			cDBase->TmpOGL[cDBase->TmpOGLCnt] = TWP;
			cDBase->TmpOGLCnt++;
			cDBase->ReDraw();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPONCV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			pC = NULL;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CURVE");
			iStat = 1;
		}
		else if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7) ||
					(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 13))
				{
					pC = (NCurve*)cDBase->S_Buff[cDBase->S_Count - 1];
				}
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// POINT ON X");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			if (pC != NULL)
			{
				C3dVector pX;
				C3dVector pO;
				C3dVector pZ;
				pX = cDBase->DB_PopBuff();
				pO = pC->GetPt(0);
				pZ = pC->GetDir(0);
				if (pC->iObjType == 13)
				{
					pZ = pC->GetPt(0.01);
					pZ -= pO;
					pZ.Normalize();
				}
				WP_Object* TWP = (WP_Object*)cDBase->DB_Obj[0];
				TWP->AlignZ(pO, pX, pZ);
				cDBase->TmpOGL[cDBase->TmpOGLCnt] = TWP;
				cDBase->TmpOGLCnt++;
				cDBase->ReDraw();
			}
			else
			{
				outtext1("ERROR: in Alignment.");
			}
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPONSURF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			pS = NULL;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			outtext2("// PICK SURFACE");
			iStat = 1;
		}
		else if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 15) ||
					(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 16) ||
					(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 17))
				{
					pS = (NSurf*)cDBase->S_Buff[cDBase->S_Count - 1];
				}
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			if (pS != NULL)
			{
				C3dVector pX;
				C3dVector pX2;
				C3dVector pY;
				C3dVector pO;
				C3dVector pZ;

				pO = pS->GetPt(0.5, 0.5);
				pX = pS->GetPt(0.6, 0.5);
				pX2 = pX;
				pX -= pO;
				pY = pS->GetPt(0.5, 0.6);
				pY -= pO;
				pX.Normalize();
				pY.Normalize();
				pZ = pX.Cross(pY);

				WP_Object* TWP = (WP_Object*)cDBase->DB_Obj[0];
				TWP->AlignZ(pO, pX2, pZ);

				cDBase->TmpOGL[cDBase->TmpOGLCnt] = TWP;
				cDBase->TmpOGLCnt++;
				cDBase->ReDraw();
				cDBase->FILTER.SetAll();
			}
			else
			{
				outtext1("ERROR: in Alignment.");
			}
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPCENT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.SetAll();
			outtext2("// PICK CENTRE LOCATION");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{

			C3dVector pO;
			pO = cDBase->DB_PopBuff();
			WP_Object* TWP = (WP_Object*)cDBase->DB_Obj[0];
			TWP->CentrePt(pO);
			cDBase->TmpOGL[cDBase->TmpOGLCnt] = TWP;
			cDBase->TmpOGLCnt++;
			cDBase->ReDraw();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zALIGN_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO ALIGN");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK CENTRE POINT ON MOVEABLE OBJECT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			outtext2("// POINT ON X ON MOVEABLE OBJECT");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 4)
		{
			outtext2("// POINT ON XY ON MOVEABLE OBJECT");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			outtext2("// PICK CENTRE POINT TO ALIGN");
			iResumePos = 6;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 6)
		{
			outtext2("// POINT ON X TO ALIGN");
			iResumePos = 7;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 7)
		{
			outtext2("// POINT ON XY TO ALIGN");
			iResumePos = 8;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 8)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			C3dVector p4;
			C3dVector p5;
			C3dVector p6;
			p6 = cDBase->DB_PopBuff();
			p5 = cDBase->DB_PopBuff();
			p4 = cDBase->DB_PopBuff();
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->Align(cDBase->OTemp, p1, p2, p3, p4, p5, p6);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zREFLECT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO REFLECT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			outtext2("// PICK CENTRE POINT ON REFLECTION PLANE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			outtext2("// POINT ON X ON REFLECTION PLANE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 4)
		{
			outtext2("// POINT ON XY ON REFLECTION PLANE");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 5)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->Reflect(cDBase->OTemp, p1, p2, p3);
			outtext1("Objects Reflected.");
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zREFLECT2D_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO REFLECT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// START POINT OF REFLECTION LINE in XY");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			outtext2("// END POINT OF REFLECTION LINE in XY");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 4)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p3.z = 0;
			p2.z = 0;
			p1 = p3;
			p1.z = 1;
			cDBase->Reflect2d(cDBase->OTemp, p1, p2, p3);
			outtext1("Objects Reflected.");
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zROTANG_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO ROTATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK CENTRE POINT FOR ROTATION");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER ROTATION (RX,RY,RZ)");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}

		else if (iStat == 4)
		{
			C3dVector p1;
			C3dVector p2;

			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->RotateAngs(cDBase->OTemp, p1, p2);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zROTABOUT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO ROTATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK FIRST POINT ON VECTOR TO ROTATE ABOUT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// PICK SECOND POINT ON VECTOR TO ROTATE ABOUT");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			outtext2("// ENTER ROTATION (ANG)");
			SetFocus();
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 5)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->RotateAbout(cDBase->OTemp, p1, p2, p3.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOPYROT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO ROTATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK FIRST POINT ON VECTOR TO ROTATE ABOUT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// PICK SECOND POINT ON VECTOR TO ROTATE ABOUT");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			outtext2("// ENTER ROTATION (ANG)");
			SetFocus();
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			outtext2("// ENTER NO OFF COPYIES)");
			SetFocus();
			iResumePos = 6;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 6)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			C3dVector p4;
			p4 = cDBase->DB_PopBuff();
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->CopyRot(cDBase->OTemp, p1, p2, p3.x, (int)p4.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOPYROT2D_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO ROTATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// POINT in XY TO ROTATE ABOUT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER ROTATION (ANG)");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NO OFF COPYIES)");
			SetFocus();
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 5)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			C3dVector p4;
			p4 = cDBase->DB_PopBuff();
			p3 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			p1.z = 0;
			p2 = p1;
			p2.z = 1;
			cDBase->CopyRot(cDBase->OTemp, p1, p2, p3.x, (int)p4.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zINSCAT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK LOCATION TO INSERT");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector p1;
			p1 = cDBase->DB_PopBuff();
			cDBase->InsertCat(p1);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSCALE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO SCALE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK POINT TO SCALE ABOUT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER SCALE FACTOR");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->Scale(cDBase->OTemp, p1, p2.x);
			outtext1("Objects Scaled.");
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOORDCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK CENTRE POINT");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// POINT ON X");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			outtext2("// POINT ON XY");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			outtext2("// ENTER TYPE (1-CART 2-CYL 3-SPH) (def 1)");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 4)
		{
			outtext2("// ENTER LABEL");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 5)
		{
			outtext2("// ENTER DEF SYS (Def 0)");
			iResumePos = 6;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 6)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			C3dVector Typ;
			C3dVector Lab;
			C3dVector RID;
			RID = cDBase->DB_PopBuff();
			Lab = cDBase->DB_PopBuff();
			Typ = cDBase->DB_PopBuff();
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->AddCoordSys(p1, p2, p3, (int)Lab.x, (int)Typ.x, (int)RID.x);
			outtext1("1 Coordinate System Created.");
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPGLOB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	outtext1("WP Set to Global.");
	WP_Object* TWP = (WP_Object*)cDBase->DB_Obj[0];
	TWP->Reset();
	cDBase->TmpOGL[cDBase->TmpOGLCnt] = TWP;
	cDBase->TmpOGLCnt++;
	cDBase->ReDraw();
	RetVal = 1;
	return RetVal;
}

int zSOLVE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->SolveStress();
	RetVal = 1;
	return RetVal;
}

int zDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->DeleteObj();
	RetVal = 1;
	return RetVal;
}

int zCIRCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "ENTER RADIUS (", gDIM_RADSZ);
			outtext2(OutT);
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			vR = cDBase->DB_PopBuff();
			dRad = vR.x;
			if (dRad == 0)
				dRad = gDIM_RADSZ;
			else
				gDIM_RADSZ = dRad;
			iStat = 2;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(1);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER CIRCLE CENTRE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p1;
			C3dVector vN;
			p1 = cDBase->DB_PopBuff();
			vN.Set(0, 0, 1);
			vN = cDBase->GlobaltoWP3(vN);
			cDBase->AddCirCR(vN, p1, dRad, -1);
			outtext1("1 Circle Created.");
			iStat = 2;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDSONCV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NO");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p1;
			p1 = cDBase->DB_PopBuff();
			cDBase->GenNodesOnCurve((int)p1.x, NULL);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPTSONCIR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CIRCLES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NO OF POINTS");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p1;
			p1 = cDBase->DB_PopBuff();
			cDBase->GenPointsOnCircle((int)p1.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTEST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->displaySymTable();
			iStat = 1;
			RetVal = 1;
		}


		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zDSPLAM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// ENTER PID OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->ViewLam((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->ViewLam(pE->PID);
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOW_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(15);
			outtext2("// PICK POINTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW WEIGHT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p1;
			p1 = cDBase->DB_PopBuff();
			cDBase->CV_ModifW(p1.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVPTON_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			cDBase->FILTER.SetFilter(15);
			outtext2("// PICK NURBS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			iStat = 1;
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			cDBase->Dsp_CtrlPts();
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELTYPE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER ELEMENT TYPE");
			SetFocus();
			iStat = 1;
		}
		else if (iStat == 1)
		{
			if (CInMsg == "BRICK")
			{
				//115 //BRICK 8
				cDBase->iCurElemType = 115;
				outtext1("BRICK TYPE 115 SET.");
			}
			else if (CInMsg == "WEDGE")
			{
				//iRC = 6; //WEDGE 6 
				cDBase->iCurElemType = 112;
				outtext1("WEDGE TYPE 112 SET.");
			}
			else if (CInMsg == "TET")
			{
				cDBase->iCurElemType = 111;
				outtext1("TET TYPE 111 SET.");
			}
			else if (CInMsg == "QUAD")
			{
				cDBase->iCurElemType = 94;
				outtext1("QUAD TYPE 94 SET.");
			}
			else if (CInMsg == "TRI")
			{
				cDBase->iCurElemType = 91;
				outtext1("TRI TYPE 91 SET.");
			}
			else if (CInMsg == "SCALAR")
			{
				cDBase->iCurElemType = 161;
				outtext1("SCALAR TYPE 161 SET.");
			}
			else if (CInMsg == "BEAM")
			{
				cDBase->iCurElemType = 21;
				outtext1("BEAM TYPE 21 SET.");
			}
			else if (CInMsg == "ROD")
			{
				cDBase->iCurElemType = 11;
				outtext1("ROD TYPE 11 SET.");
			}
			else if (CInMsg == "RIGID")
			{
				cDBase->iCurElemType = 122;
				outtext1("RIGID TYPE 122 SET.");
			}
			else if (CInMsg == "TSPRING")
			{
				cDBase->iCurElemType = 136;
				outtext1("TRANSLATION SPRING TYPE 136 SET.");
			}
			else if (CInMsg == "RSPRING")
			{
				cDBase->iCurElemType = 137;
				outtext1("ROTATIONAL SPRING TYPE 137 SET.");
			}
			else if (CInMsg == "BUSH")
			{
				cDBase->iCurElemType = 138;
				outtext1("BUSH SPRING TYPE 138 SET.");
			}
			else if (CInMsg == "SCELL")
			{
				cDBase->iCurElemType = 1000;
				outtext1("STAGGERED CELL TYPE 1000 SET.");
			}
			else
			{
				outtext1("ERROR: No Valid Selection.");
			}
			outtext2("D");
			RetVal = 1;
		}
	}
	//Escape clause
	if (iStat == 100)
	{
		cDBase->DB_BuffCount = initCnt;
		cDBase->S_Count = S_initCnt;
		RetVal = 1;
	}
MenuEnd:
	return RetVal;
}

int zELCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	int noNodes;

	noNodes = cDBase->pCurrentMesh->GetNoNode(cDBase->iCurElemType);
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if ((CInMsg == "C"))//Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + noNodes)
			{
				iStat = 2;
			}
			if ((cDBase->iCurElemType == 122) && (CInMsg == "D") && (cDBase->S_Count > S_initCnt + 1))
			{
				iStat = 2;
			}
			if (CInMsg == "ELTYPE") //Common Options
			{
				iResumePos = 0;
				iCancelPos = 100;
				pNext = new zELTYPE_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else if (CInMsg == "LAB") //Common Options
			{
				iResumePos = 0;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1); //-1Comment out 1 do not
				DoNext(&CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			pE = cDBase->AddEl(S_initCnt, TRUE);
			outtext1("1 Element Created.");
			cDBase->S_Count = S_initCnt;
			cDBase->ReDraw();
			if ((cDBase->iCurElemType == 122) && (pE != NULL))
			{
				iStat = 3;
			}
			else
			{
				iStat = 0;
				this->DoMenu("", Pt);
			}
		}
		//Dof string for rigid elements
		if (iStat == 3)
		{
			outtext2("// ENTER DOF STRING");
			SetFocus();
			iStat = 4;
		}
		else if (iStat == 4)
		{
			E_ObjectR* pR = (E_ObjectR*)pE;
			pR->SetDOFString(CInMsg);
			iStat = 0;
			this->DoMenu("", Pt);
		}
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELINSSPG_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	int noNodes;

	noNodes = cDBase->pCurrentMesh->GetNoNode(cDBase->iCurElemType);
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if ((CInMsg == "C"))//Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODE TO INSERT SPRING ELEMENT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			pE = cDBase->InsSpringEl(S_initCnt, TRUE);
			cDBase->S_Count = S_initCnt;
			cDBase->ReDraw();
			iStat = 0;
			this->DoMenu("", Pt);
		}
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLMEAS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK PT1");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// PICK PT2");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 2)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->lMeasure(p1, p2);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zAMEAS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER PT1");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			outtext2("// ENTER PT2");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER PT3");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 3)
		{
			C3dVector p1;
			C3dVector p2;
			C3dVector p3;
			p3 = cDBase->DB_PopBuff();
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->DB_PopBuff();
			cDBase->AMeasure(p1, p2, p3);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFILET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CPoint PNear1;
	CPoint PNear2;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(9);
			outtext2("// PICK LINES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
			}
			if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear2 = Pt;
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER RADIUS");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			//cDBase->Fillet2(ptNo.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2;
	CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// ENTER LOCATION OR PICK FROM SCREEN");
			iStat = 1;
		}
		if (iStat == 1)
		{
			iResumePos = 1;
			iCancelPos = 2;
			pNext = new zPT_Mnu;
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "//ENTER ORDER (", gDIM_CVORD);
			outtext2(OutT);
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector P;
			P = cDBase->DB_PopBuff();
			if (P.x < 1)
				P.x = gDIM_CVORD;
			if (P.x != gDIM_CVORD)
				gDIM_CVORD = P.x;

			cDBase->AddContPolyW(1, P.x);
			outtext1("1 Curve Created.");
			cDBase->FILTER.SetAll();
			iStat = 100;
		}
		//ESCAPE CLAUSE
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVFIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2;
	CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(5);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// ENTER LOCATION OR PICK FROM SCREEN");
			iStat = 1;
		}
		if (iStat == 1)
		{
			iResumePos = 1;
			iCancelPos = 2;
			pNext = new zPT_Mnu;
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "//ENTER ORDER (", gDIM_CVORD);
			outtext2(OutT);
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector P;
			P = cDBase->DB_PopBuff();
			if (P.x < 1)
				P.x = gDIM_CVORD;
			if (P.x != gDIM_CVORD)
				gDIM_CVORD = P.x;

			cDBase->AddCurveFit((int)P.x);
			outtext1("1 Curve Created.");
			cDBase->FILTER.SetAll();
			iStat = 100;
		}
		//ESCAPE CLAUSE
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}

	}
MenuEnd:
	return RetVal;
}

int zSUREX_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK PROFILE CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "LAB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1); //-1Comment out 1 do not
				DoNext(&CInMsg, Pt);
			}
			else if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// ENTER TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);

		}
		if (iStat == 3)
		{
			C3dVector ptVec = cDBase->DB_PopBuff();
			cDBase->AddSurfE(ptVec);
			outtext1("Surfaces Created.");
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURRV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK PROFILE CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "LAB")
			{
				iResumePos = 0;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1); //-1Comment out 1 do not
				DoNext(&CInMsg, Pt);
			}
			else if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// ENTER AXIS PT1");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->bIsDrag = TRUE;
			p1 = cDBase->DB_PopBuff();
			cDBase->AddDragLN(p1);
			cDBase->vLS = p1;
			outtext2("// ENTER AXIS PT2");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			cDBase->bIsDrag = FALSE;
			outtext2("// ENTER ROTATION ANG (Def: 360)");
			iStat = 5;
			SetFocus();
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dAng = atof(CInMsg);
			if ((dAng < 0) || (dAng > 360))
			{
				iStat = 4;
				outtext1("ERROR: Invalid Rotation Angle.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				if (dAng == 0)
				{
					dAng = 360;
				}
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			C3dVector pt2 = cDBase->DB_PopBuff();
			cDBase->AddSurfR(p1, pt2, dAng);
			outtext1("Surfaces Created.");
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->bIsDrag = FALSE;
			cDBase->ReDraw();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVONSUR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			cDBase->S_Count = 0;
			iCnt = cDBase->OTemp->iNo;
			outtext2("// PICK SURFACE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count > 0)
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			outtext2("// PICK CURVES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			cDBase->CurvesToSurface(cDBase->OTemp, cDBase->OTemp2);
			//cDBase->S_Res();
			cDBase->S_Res();
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURTRIM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			cDBase->S_Count = 0;
			iCnt = cDBase->OTemp->iNo;
			outtext2("// PICK SURFACE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count > 0)
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			outtext2("// PICK SURFACE CURVES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(13);
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			cDBase->SurfaceTrim(cDBase->OTemp, cDBase->OTemp2);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMMESHQ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			//Esp_Mod: Prior example showed a comma, but a space is expected
			outtext2("// ENTER NO IN U and V directions (Example '3 4')");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->MapMesh(ptNo.x, ptNo.y);
			cDBase->FILTER.SetAll();
			//cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURFUNTRIM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES TO UNTRIM");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->SurfUnTrim();
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMMESHT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			//Esp_Mod: Prior example showed a comma, but a space is expected
			outtext2("// ENTER NO IN U and V directions  (Example '3 4')");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->MapMeshTri(ptNo.x, ptNo.y);
			cDBase->FILTER.SetAll();
			//cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zEXTRACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK PART - CURVES / SURFACES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}

			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->Extract(cDBase->OTemp);
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zMMESHSZ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES TO DEFINE MESH SIZE");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}

			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			outtext2("// ENTER ELEMENT SIZE");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->S_Des();
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->MeshSurfSize(cDBase->OTemp, ptNo.x);
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zMMESHBZ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK CURVES TO BEAM MESH");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}

			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			outtext2("// ENTER ELEMENT SIZE");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			cDBase->S_Des();
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->MeshBeamSize(cDBase->OTemp, ptNo.x);
			cDBase->OTemp->Clear();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFMESHT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SURFACES");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER SPACING)");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptNo;
			ptNo = cDBase->DB_PopBuff();
			cDBase->FreeMeshTri(ptNo.x);
			cDBase->FILTER.SetAll();
			//cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zSURTRIMLOOP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			cDBase->S_Count = 0;
			iCnt = cDBase->OTemp->iNo;
			outtext2("// PICK SURFACE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count > 0)
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			//Esp_Mod: Added limititation in description
			outtext2("// PICK CURVES - ONE INTERNAL CURVE ALLOWED PER OPERATION");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			cDBase->SurfaceTrimLoop(cDBase->OTemp, cDBase->OTemp2);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->FILTER.SetAll();
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CROSS SECTION CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "LAB")
			{
				iResumePos = 0;
				iCancelPos = 0;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->AddSurf();
				cDBase->FILTER.SetAll();
				cDBase->DB_BuffCount = initCnt;
				cDBase->S_Count = S_initCnt;
				cDBase->ReDraw();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURSWEEP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVES TO SWEEP");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			outtext2("// PICK CURVES TO SWEEP ALONG");
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			cDBase->AddSurfSweep(cDBase->OTemp, cDBase->OTemp2);
			outtext1("Surfaces Created.");
			cDBase->S_Res();
			cDBase->S_Count = 0;
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSDSEC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK BOUNDARY CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->AddSolidSection();
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSURBOUND_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK BOUNDARY CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "LAB")
			{
				iResumePos = 0;
				iCancelPos = 0;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->AddSurfBound();
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOLWT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModLWT(2);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOLWM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModLWT(4);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOLWL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModLWT(10);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOSOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModType(1);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMODOT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModType(2);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMOCTR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModType(4);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVMODASH_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
				RetVal = 1;
				cDBase->CurveModType(3);
				cDBase->FILTER.SetAll();
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;

}

int zFIL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			iStat = 1;
		}

		if (iStat == 1)
		{
			char OutT[80];
			sprintf_s(OutT, "%s %g)", "ENTER RADIUS (", gDIM_FILSZ);
			outtext2(OutT);
			SetFocus();
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}

		if (iStat == 2)
		{
			vR = cDBase->DB_PopBuff();
			iStat = 3;
		}

		if (iStat == 3)
		{
			outtext2("// PICK TWO CURVES");
			iStat = 4;
		}

		if (iStat == 4)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
			}

			if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear2 = Pt;
				iStat = 5;
			}
		}

		if (iStat == 5)
		{
			double dRad;
			dRad = vR.x;
			if (dRad == 0)
				dRad = gDIM_FILSZ;
			else
				gDIM_FILSZ = dRad;
			cDBase->Fillet2(dRad, PNear1, PNear2);
			iStat = 4;
			cDBase->S_Count = S_initCnt;
			outtext2("// PICK TWO CURVES");
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}

MenuEnd:

	return RetVal;
}

int zCORNER_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK LINES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
			}
			if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear2 = Pt;
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			C3dVector P;
			P = cDBase->DB_PopBuff();
			cDBase->Corner2(PNear1, PNear2);
			cDBase->FILTER.SetAll();
			iStat = 0;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			//RetVal = 1;
			iStat = 0;
		}
	}
MenuEnd:
	return RetVal;
}

int zTRIM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVE TO TRIM ");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				PNear1 = Pt;
				outtext2("// PICK TRIM CURVE ");
			}
			if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear2 = Pt;
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			C3dVector P;
			P = cDBase->DB_PopBuff();
			cDBase->Trim(PNear1, PNear2);
			iStat = 0;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPROJ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(13);
			cDBase->FILTER.SetFilter(15);
			outtext2("// PICK OBJECT TO PROJECT TO");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER PT TO PROJECT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(1);
		}
		if (iStat == 3)
		{
			C3dVector p1;
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			p1 = cDBase->ClosestTo(p2);
			cDBase->DB_AddPtBuff(p1);
			RetVal = 1;
			cDBase->FILTER.SetAll();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zKNOTINS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				iStat = 2;
				pC = NULL;
				if (cDBase->S_Buff[cDBase->S_Count - 1] != NULL)
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7)
						pC = (NCurve*)cDBase->S_Buff[cDBase->S_Count - 1];
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// ENTER PT TO PROJECT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->KnotInsertion(pC, p2);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCVSPLIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVE TO SPLIT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				iStat = 2;
				pC = NULL;
				if (cDBase->S_Buff[cDBase->S_Count - 1] != NULL)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7)
					{
						pC = (NCurve*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->S_Count--;
					}
					else
					{
						cDBase->S_Count--;
						iStat = 0;
						outtext1("ERROR: Invalid Selection.");
						DoMenu(CInMsg, Pt);
					}
				}
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// ENTER PT TO PROJECT");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector p2;
			p2 = cDBase->DB_PopBuff();
			cDBase->CurveSplit(pC, p2);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zKNOTMOD_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK CURVE TO MODIFY KNOT VECTOR");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				iStat = 2;
				pC = NULL;
				if (cDBase->S_Buff[cDBase->S_Count - 1] != NULL)
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7)
					{
						pC = (NCurve*)cDBase->S_Buff[cDBase->S_Count - 1];
						outtext2("// CURR KNO SEQ:-");
						outtext2(_T(pC->GetKnotString()));
					}
			}
		}
		if (iStat == 2)
		{
			cDBase->FILTER.SetAll();
			outtext2("// ENTER NEW KNOT STRING (0,0,0,0.5 etc");
			iStat = 3;
		}
		if (iStat == 3)
		{
			iStat = 4;
			sKnot = CInMsg;
		}
		if (iStat == 4)
		{
			cDBase->KnotModify(pC, sKnot);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zINT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// PICK LINES TO INTERCECT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (cDBase->S_Count == S_initCnt + 2)
			{
				PNear1 = Pt;
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			C3dVector p2;
			BOOL bErr;
			p2 = cDBase->Intersect(bErr, PNear1);
			if (bErr == FALSE)
			{
				cDBase->DB_AddPtBuff(p2);
			}
			cDBase->FILTER.Restore();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.Restore();
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNODEX_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES TO MODIFY X ORDINATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER NEW X VALUE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ModNodeX(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNODEY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES TO MODIFY Y ORDINATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER NEW Y VALUE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ModNodeY(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNODEZ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES TO MODIFY Z ORDINATE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER NEW Z VALUE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ModNodeZ(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER FORCE VECTOR");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddForce(cDBase->OTemp, ptVec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zACR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER ACCELERATION VECTOR");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddAccel(cDBase->OTemp, ptVec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGRAV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER ACCELERATION SCALE FACTOR");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER ACCELERATION VECTOR");
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			C3dVector Vec;
			Vec = cDBase->DB_PopBuff();
			C3dVector SclVec;
			SclVec = cDBase->DB_PopBuff();
			cDBase->AddGrav(SclVec.x, Vec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRACR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER AXIS PT1");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER AXIS PT2");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER ROTATIONAL SPEED w (rad/s)");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector ptVec;
			C3dVector pA1;
			C3dVector pA2;
			ptVec = cDBase->DB_PopBuff();
			pA2 = cDBase->DB_PopBuff();
			pA1 = cDBase->DB_PopBuff();
			cDBase->AddRotAccel(cDBase->OTemp, ptVec.x, pA1, pA2);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

//class zTBCR_Mnu: public zMnu
//class zFLUXCR_Mnu: public zMnu
int zTBCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER TEMPERATURE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddTemperatureBC(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFLUXCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER NETT FLUX");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddFluxQ(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER TEMPERATURE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddTemperature(cDBase->OTemp, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTEMPD_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER TEMPERATURE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddTEMPD(ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER MOMENT VECTOR");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddMoment(cDBase->OTemp, ptVec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			cDBase->FILTER.SetFilter(4);
			outtext2("// PICK SHELL ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER PRESSURE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->AddPressure(cDBase->OTemp, ptVec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESLISTEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;               //pParent menu step
			}
			if (CInMsg == "LAB") //Common Options
			{
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, 1);
				DoNext(&CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->RESLISTEL(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			//cDBase->S_Count=S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESLISTND_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;               //pParent menu step
			}
			if (CInMsg == "LAB") //Common Options
			{
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zLAB_Mnu();
				pNext->Init(cDBase, 1);
				DoNext(&CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->RESLISTND(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			//cDBase->S_Count=S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCNODES_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES TO CHECK");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Des();
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER TOLERANCE");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			int i;
			ObjList* CNodes = new ObjList();
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->CoincidentNodes(cDBase->OTemp, CNodes, ptVec.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			cDBase->S_Count = 0;
			for (i = 0;i < CNodes->iNo;i++)
			{
				cDBase->S_BuffAdd(CNodes->Objs[i]);
			}
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			outtext2("// ENTER TRANS RESTRAINT VECTOR");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER ROT RESTRAINT VECTOR");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector TVec;
			C3dVector RVec;
			RVec = cDBase->DB_PopBuff();
			TVec = cDBase->DB_PopBuff();
			cDBase->AddRestraint(cDBase->OTemp, TVec, RVec);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ITEMS");
			iStat = 1;

		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER COLOUR");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->Colour((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCHKCOUNT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ITEMS TO COUNT");
			iStat = 1;

		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->CountItems();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLABENT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ITEMS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			cDBase->LabEnt();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELMOPID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW PROPERTY ID ((PID)");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ElemntMoPID((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELRBENODE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ELEMENTS");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;

			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			cDBase->SelRBENode(cDBase->OTemp);
			cDBase->OTemp->Clear();
			//cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELREV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			cDBase->FILTER.SetFilter(4);
			outtext2("// PICK ELEMENTS TO REVERSE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->ElementReverse();
			outtext1("Elements Reversed.");
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCHKCIRCUMSPH_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK TET ELEMENTS TO REPORT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->TetCircumSphere();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBROD_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "//ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER RADIUS");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dR = atof(CInMsg);
			if (dR < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Radius.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrRod(sTit, iPID, iMID, dR);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRROD_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER AREA");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dA = atof(CInMsg);
			if (dA < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Radius.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER TORSIONAL COEF (J)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dJ = atof(CInMsg);
			if (dJ < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Torsional Coeff.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePRod(sTit, iPID, iMID, dA, dJ);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBAR2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER AREA");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dA = atof(CInMsg);
			if (dA < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Radius.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER I1");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dI1 = atof(CInMsg);
			if (dI1 < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid I1.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER I2");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dI2 = atof(CInMsg);
			if (dA < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid I2.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER TORSIONAL COEF (J)");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dJ = atof(CInMsg);
			if (dJ < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Torsional Coeff.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}
		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePRBar2(sTit, iPID, iMID, dA, dI1, dI2, dJ);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBBAR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER WIDTH (beam Z)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dW = atof(CInMsg);
			if (dW < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER HEIGHT (beam Y)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dH = atof(CInMsg);
			if (dH < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrBar(sTit, iPID, iMID, dW, dH);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zQWNODES_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER TOLERENCE (Def:0.0001)");
			outtext2("// RECOMMEND SAVING MODEL FIRST");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			dTol = atof(CInMsg);
			if (dTol == 0)
			{
				dTol = 0.0001;
				iStat = 2;
				RetVal = 1;
				cDBase->CNodesMerge(dTol);
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMERNODES_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER TOLERENCE (Def:0.0001)");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			dTol = atof(CInMsg);
			if (dTol <= 0)
			{
				dTol = 0.0001;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// USE HIGHER LABEL (TYPE YES/NO) (Def:YES)");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			if (CInMsg.Find("NO") > -1)
			{
				bUp = FALSE;
				iStat = 6;
			}
			else if ((CInMsg.Find("YES") > -1) || (CInMsg = ""))
			{
				bUp = TRUE;
				iStat = 6;
			}
			else
			{
				iStat = 4;
				outtext1("ERROR: Invalid Selection.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 6)
		{
			outtext2("// MERGE NODES (TYPE YES/NO) (Def:YES)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			if (CInMsg.Find("NO") > -1)
			{
				bDel = FALSE;
				iStat = 8;
			}
			else if ((CInMsg.Find("YES") > -1) || (CInMsg = ""))
			{
				bDel = TRUE;
				iStat = 8;
			}
			else
			{
				iStat = 6;
				outtext1("ERROR: Invalid Selection.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 8)
		{
			RetVal = 1;
			cDBase->CNodesMerge2(cDBase->OTemp, dTol, bUp, bDel);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDEQLAB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER TOLERENCE (Def:0.0001)");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			dTol = atof(CInMsg);
			if (dTol <= 0)
			{
				dTol = 0.0001;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			RetVal = 1;
			cDBase->EqLab(cDBase->OTemp, dTol, bUp, bDel);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCHKSHELLASP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER THRESHOLD (Def:2.0)");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			dT = atof(CInMsg);
			if (dT <= 0)
			{
				dT = 2.0;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// LIST ASPECT VALUES (TYPE YES/NO) (Def:YES)");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			if (CInMsg.Find("NO") > -1)
			{
				bList = FALSE;
				iStat = 6;
			}
			else if ((CInMsg.Find("YES") > -1) || (CInMsg = ""))
			{
				bList = TRUE;
				iStat = 6;
			}
			else
			{
				iStat = 4;
				outtext1("ERROR: Invalid Selection.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 6)
		{
			RetVal = 1;
			cDBase->ChkShellAspect(cDBase->OTemp, dT, bList);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCHKTETCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER THRESHOLD (Def:0.2)");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			dT = atof(CInMsg);
			if (dT <= 0)
			{
				dT = 0.2;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// LIST COLLAPSE VALUES (TYPE YES/NO) (Def:YES)");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			if (CInMsg.Find("NO") > -1)
			{
				bList = FALSE;
				iStat = 6;
			}
			else if ((CInMsg.Find("YES") > -1) || (CInMsg = ""))
			{
				bList = TRUE;
				iStat = 6;
			}
			else
			{
				iStat = 4;
				outtext1("ERROR: Invalid Selection.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 6)
		{
			RetVal = 1;
			cDBase->ChkTetCollapse(cDBase->OTemp, dT, bList);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRCMAT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER PID TO CHANGE MATERIAL");
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iStat = 0;
				outtext1("ERROR: Invalid Property ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// MATERIAL ID TO UPDATE");
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iMID1 = atoi(CInMsg);
			if (iMID1 < 1)
			{
				iStat = 2;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NEW MATERIAL ID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID2 = atoi(CInMsg);
			if (iMID2 < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}

		if (iStat == 6)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->ModifyPrMat(iPID, iMID1, iMID2);
			}
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRSOLID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrSolid(sTit, iPID, iMID);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRSHELL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER THICKNESS");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dT = atof(CInMsg);
			if (dT < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER NSM");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dNSM = atof(CInMsg);
			if (dNSM < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid NSM.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrShell(sTit, iPID, iMID, dT, dNSM);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRPCOMP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NSM");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dNSM = atof(CInMsg);
			if (dNSM < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid NSM.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		//
		if (iStat == 6)
		{
			outtext2("// ENTER LAYER (MID,THK,THETA)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			if (CInMsg == "D")
			{
				iStat = 8;
			}
			else
			{
				sLay[iNoLay] = CInMsg;
				iNoLay++;
				iStat = 6;
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 8)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrPCOMP(sTit, iPID, dNSM, iNoLay, sLay);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRSPGT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER KX");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dkx = atof(CInMsg);
			if (dkx < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid KX.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER KY");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dky = atof(CInMsg);
			if (dky < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid KY.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER KZ");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dkz = atof(CInMsg);
			if (dkz < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid KZ.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			outtext2("// ENTER CONDUCTIVITY kCoeff");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dkt = atof(CInMsg);
			if (dkt < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid kCoeff.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}

		if (iStat == 12)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrSpringT(sTit, iPID, dkx, dky, dkz, dkt);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

//NASTRAN BUSH ELEMENT (BASIC FORM FOR K ONLY)
int zPRBUSH_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER K1");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dk1 = atof(CInMsg);
			if (dk1 < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid K1.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER K2");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dk2 = atof(CInMsg);
			if (dk2 < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid K2.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER K3");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dk3 = atof(CInMsg);
			if (dk3 < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid K3.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER K4");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dk4 = atof(CInMsg);
			if (dk4 < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid K4.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}

		if (iStat == 12)
		{
			outtext2("// ENTER K5");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dk5 = atof(CInMsg);
			if (dk5 < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid K5.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}

		if (iStat == 14)
		{
			outtext2("// ENTER K6");
			iStat = 15;
			goto MenuEnd;
		}
		if (iStat == 15)
		{
			dk5 = atof(CInMsg);
			if (dk5 < 0)
			{
				iStat = 14;
				outtext1("ERROR: Invalid K6.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 16;
			}
		}



		if (iStat == 16)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrBUSH(sTit, iPID, dk1, dk2, dk3, dk4, dk5, dk6);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRMASS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MASS");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dM = atof(CInMsg);
			if (dM < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid MASS.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrLumpedMass(sTit, iPID, dM);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRSPGR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualt pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER RX");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dkx = atof(CInMsg);
			if (dkx < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid RX.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER RY");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dky = atof(CInMsg);
			if (dky < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid RY.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER RZ");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dkz = atof(CInMsg);
			if (dkz < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid RZ.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			outtext2("// ENTER CONDUCTIVITY kCoeff");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dkt = atof(CInMsg);
			if (dkt < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid kCoeff.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}

		if (iStat == 12)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrSpringR(sTit, iPID, dkx, dky, dkz, dkt);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBBOX_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER WIDTH (beam Z)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dW = atof(CInMsg);
			if (dW < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER HEIGHT (beam Y)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dH = atof(CInMsg);
			if (dH < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER WIDTH THK (beam Z)");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dWT = atof(CInMsg);
			if (dWT < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER HEIGHT THK (beam Y)");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dHT = atof(CInMsg);
			if (dHT < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}



		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrBox(sTit, iPID, iMID, dW, dH, dWT, dHT);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER WIDTH (beam Z)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dW = atof(CInMsg);
			if (dW < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER HEIGHT (beam Y)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dH = atof(CInMsg);
			if (dH < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER WIDTH THK (beam Z)");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dWT = atof(CInMsg);
			if (dWT < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER HEIGHT THK (beam Y)");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dHT = atof(CInMsg);
			if (dHT < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}



		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrL(sTit, iPID, iMID, dW, dH, dWT, dHT);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBT2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER FLANGE WIDTH (beam Z)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dW = atof(CInMsg);
			if (dW < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER WEB HEIGHT (beam Y)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dH = atof(CInMsg);
			if (dH < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER FLANGE THK");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dWT = atof(CInMsg);
			if (dWT < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER WEB THK");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dHT = atof(CInMsg);
			if (dHT < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}



		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrT2(sTit, iPID, iMID, dW, dH, dWT, dHT);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBCHAN2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER WEB WIDTH (beam Z)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dW = atof(CInMsg);
			if (dW < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER FLANGE HEIGHT (beam Y)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dH = atof(CInMsg);
			if (dH < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER WEB THK");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dWT = atof(CInMsg);
			if (dWT < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER FLANGE THK");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dHT = atof(CInMsg);
			if (dHT < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}



		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrCHAN2(sTit, iPID, iMID, dW, dH, dWT, dHT);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBI2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER WEB HEIGHT (beam Y)");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			d1 = atof(CInMsg);
			if (d1 < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid height.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER BOTTOM FLANGE WIDTH (beam Z)");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			d2 = atof(CInMsg);
			if (d2 < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER TOP FLANGE WIDTH (beam Z)");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			d3 = atof(CInMsg);
			if (d3 < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid Width.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER WEB THK");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			d4 = atof(CInMsg);
			if (d4 < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}
		if (iStat == 14)
		{
			outtext2("// ENTER BOTTOM FLG THK");
			iStat = 15;
			goto MenuEnd;
		}
		if (iStat == 15)
		{
			d5 = atof(CInMsg);
			if (d5 < 0)
			{
				iStat = 14;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 16;
			}
		}
		if (iStat == 16)
		{
			outtext2("// ENTER TOP FLG THK");
			iStat = 17;
			goto MenuEnd;
		}
		if (iStat == 17)
		{
			d6 = atof(CInMsg);
			if (d6 < 0)
			{
				iStat = 16;
				outtext1("ERROR: Invalid Thickness.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 18;
			}
		}


		if (iStat == 18)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrI2(sTit, iPID, iMID, d1, d2, d3, d4, d5, d6);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMMAT8_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER MATERIAL TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = MatT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "//ENTER NEW MID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iMID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER E1");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dE1 = atof(CInMsg);
			if (dE1 < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Young's Modulus.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}

		if (iStat == 6)
		{
			outtext2("// ENTER E2");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dE2 = atof(CInMsg);
			if (dE2 < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Young's Modulus.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}

		if (iStat == 8)
		{
			outtext2("// ENTER NU12");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dNU12 = atof(CInMsg);
			if (dNU12 < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Value.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}


		if (iStat == 10)
		{
			outtext2("// ENTER G12");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dG12 = atof(CInMsg);
			iStat = 12;
		}

		if (iStat == 12)
		{
			outtext2("// ENTER G1Z");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dG1Z = atof(CInMsg);
			iStat = 14;
		}

		if (iStat == 14)
		{
			outtext2("// ENTER G2Z");
			iStat = 15;
			goto MenuEnd;
		}
		if (iStat == 15)
		{
			dG2Z = atof(CInMsg);
			iStat = 16;
		}

		if (iStat == 16)
		{
			outtext2("// ENTER DENSITY RHO");
			iStat = 17;
			goto MenuEnd;
		}
		if (iStat == 17)
		{
			dRHO = atof(CInMsg);
			if (dRHO < 0)
			{
				iStat = 16;
				outtext1("ERROR: Invalid Value.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 18;
			}
		}

		if (iStat == 18)
		{
			outtext2("// ENTER CTE A1");
			iStat = 19;
			goto MenuEnd;
		}
		if (iStat == 19)
		{
			dA1 = atof(CInMsg);
			iStat = 20;
		}
		if (iStat == 20)
		{
			outtext2("// ENTER CTE A2");
			iStat = 21;
			goto MenuEnd;
		}
		if (iStat == 21)
		{
			dA2 = atof(CInMsg);
			iStat = 22;
		}

		if (iStat == 22)
		{
			outtext2("// ENTER THERMAL CONDUCTIVITY k");
			iStat = 23;
			goto MenuEnd;
		}
		if (iStat == 23)
		{
			dk = atof(CInMsg);
			if (dk < 0)
			{
				iStat = 22;
				outtext1("ERROR: Invalid k.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 24;
			}
		}
		if (iStat == 24)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreateMat8(sTit, iMID, dE1, dE2, dNU12,
					dG12, dG1Z, dG2Z, dRHO,
					dA1, dA2, dk);
			}
			outtext1("End of Material Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMMAT1_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER MATERIAL TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = MatT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "//ENTER NEW MID (", iNLab, ")");
		////////////////////////////////////////////////////////////

		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iMID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER E");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			dE = atof(CInMsg);
			if (iMID < 0)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Young's Modulus.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER V");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dV = atof(CInMsg);
			if (dV < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Poisson's Ratio.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER DENSITY");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dDen = atof(CInMsg);
			if (dDen < 0)
			{
				iStat = 8;
				outtext1("ERROR: Invalid Density.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}
		if (iStat == 10)
		{
			outtext2("// ENTER CTE");
			iStat = 11;
			goto MenuEnd;
		}
		if (iStat == 11)
		{
			dA = atof(CInMsg);
			if (dA < 0)
			{
				iStat = 10;
				outtext1("ERROR: Invalid CTE.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 12;
			}
		}
		if (iStat == 12)
		{
			outtext2("// ENTER THERMAL CONDUCTIVITY k");
			iStat = 13;
			goto MenuEnd;
		}
		if (iStat == 13)
		{
			dk = atof(CInMsg);
			if (dk < 0)
			{
				iStat = 12;
				outtext1("ERROR: Invalid k.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 14;
			}
		}
		if (iStat == 14)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreateMat1(sTit, iMID, dE, dV, dDen, dA, dk);
			}
			outtext1("End of Material Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRBTUBE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER PROPERTY TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sTit = CInMsg;
			iStat = 2;
		}
		////////////////Get defualy pid//////////////////////////////
		iNLab = 1;
		if (cDBase->pCurrentMesh != NULL)
		{
			iNLab = PropsT->NextID();
		}
		char s1[200];
		CString sT;
		sprintf_s(s1, "%s%i%s", "ENTER NEW PID (", iNLab, ")");
		////////////////////////////////////////////////////////////
		if (iStat == 2)
		{
			outtext2(s1);
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iPID = atoi(CInMsg);
			if (iPID < 1)
			{
				iPID = iNLab;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER MID");
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iMID = atoi(CInMsg);
			if (iMID < 1)
			{
				iStat = 4;
				outtext1("ERROR: Invalid Material ID.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 6;
			}
		}
		if (iStat == 6)
		{
			outtext2("// ENTER OUTER RADIUS");
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			dR = atof(CInMsg);
			if (dR < 0)
			{
				iStat = 6;
				outtext1("ERROR: Invalid Outer Radius.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 8;
			}
		}
		if (iStat == 8)
		{
			outtext2("// ENTER INNER RADIUS");
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			dr = atof(CInMsg);
			if ((dr < 0) || (dr > dR))
			{
				iStat = 8;
				outtext1("ERROR: Invalid Inner Radius.");
				DoMenu(CInMsg, Pt);
			}
			else
			{
				iStat = 10;
			}
		}

		if (iStat == 10)
		{
			RetVal = 1;
			if (cDBase->pCurrentMesh != NULL)
			{
				cDBase->CreatePrTube(sTit, iPID, iMID, dR, dr);
			}
			outtext1("End of Property Definition.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDMOLAB2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES TO MODIFY LABEL");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER START ID");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->NodeMoLab2((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELMOLAB2_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK ELEMENTS TO MODIFY LABEL");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER START ID");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ElementMoLab2((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDMOLAB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES TO MODIFY LABEL");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER ID INCREMENT");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->NodeMoLab((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELMOLAB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK ELEMENTS TO MODIFY LABEL");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER ID INCREMENT");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ElementMoLab((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDMOOSYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES TO MODIFY OUT CYS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW OUPUT COORD SYS ID");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->NodeMoOSys((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELMOSHELLMCYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK SHELLS TO MODIFY MAT CSYS ID");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW COORD SYS ID OR PICK ONE");
			iStat = 3;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(12);
			//cDBase->FILTER.SetFilter(4);
			S_initCnt = cDBase->S_Count;
		}
		if (iStat == 3)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->ShellMoCSys((int)GetPt.x);
				cDBase->FILTER.SetAll();
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType = 12)
					{
						CoordSys* pC = (CoordSys*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->ShellMoCSys(pC->iLabel);
					}
					cDBase->FILTER.SetAll();
					RetVal = 1;
				}
			}
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSPGMOSYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK SPRINGS TO MODIFY COORD-SYS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW COORD SYS ID OR PICK ONE");
			iStat = 3;
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(12);
			S_initCnt = cDBase->S_Count;
		}
		if (iStat == 3)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SpringMoCSys((int)GetPt.x);
				cDBase->FILTER.SetAll();
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType = 12)
					{
						CoordSys* pC = (CoordSys*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SpringMoCSys(pC->iLabel);
					}
					cDBase->FILTER.SetAll();
					RetVal = 1;
				}
			}
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDMORSYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK NODES TO MODIFY REF CYS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER NEW REF COORD SYS ID");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->NodeMoRSys((int)ptVec.x);
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER WP SIZE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetWPSize(ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESCOLSETBAR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER MIN,MAX");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetColourBar(ptVec.x, ptVec.y);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBUPVEC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENTS TO SET UPVEC");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER TRANSLATION VECTOR");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->BeamUpVecs(cDBase->OTemp, ptVec);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBOFF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENTS TO OFFSET");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER TRANSLATION VECTOR");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->BeamOffsets(cDBase->OTemp, ptVec);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBDOFA_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENT TO SET END RELEASE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER DOF STRING (TO RELEASE)");
			SetFocus();
			iStat = 4;
		}
		else if (iStat == 4)
		{
			cDBase->SetDOFStringA(cDBase->OTemp, CInMsg);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBDOFB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENT TO SET OFFSETS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER DOF STRING (TO RELEASE)");
			SetFocus();
			iStat = 4;
		}
		else if (iStat == 4)
		{
			cDBase->SetDOFStringB(cDBase->OTemp, CInMsg);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSOFF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK SHELL ELEMENT TO SET OFFSETS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER DISTANCE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ShellOffsets(cDBase->OTemp, ptVec.x);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBOFFY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENTS TO OFFSETS IN BEAM Y");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER DISTANCE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->BeamOffsetY(cDBase->OTemp, ptVec.x);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBOFFZ_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK BEAM ELEMENTS TO OFFSETS IN BEAM Z");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// ENTER DISTANCE");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->BeamOffsetZ(cDBase->OTemp, ptVec.x);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDCO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES TO COPY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Des();
			cDBase->ReDraw();
			iStat = 3;
		}
		if (iStat == 3)
		{
			outtext2("// TRANSLATION:");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NO");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->CpNodes(cDBase->OTemp, ptVec, (int)ptNo.x);
			cDBase->S_Res();
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELSWEEP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ELEMENTS,FACES,EDGES TO SWEEP");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			cDBase->FILTER.SetFilter(8);
			cDBase->FILTER.SetFilter(9);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;

			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			outtext2("// ENTER TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER NO");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->ElSweep(cDBase->OTemp, ptVec, (int)ptNo.x);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.SetAll();
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELSWEEPNDS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK NODES TO SWEEP INTO SHELLS");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;

			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			outtext2("// ENTER TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER NO");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->NDSweepToShell(cDBase->OTemp, ptVec, (int)ptNo.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELSWEEPNDB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK NODES TO SWEEP INTO BEAMS");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;

			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			outtext2("// ENTER TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER NO");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->NDSweepToBeam(cDBase->OTemp, ptVec, (int)ptNo.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELSWEEPB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK SHELL EDGES TO SWEEP OUT");
			outtext2("// Note: You must do a free edge check first to make edges visable.");
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(8);
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;

			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			outtext2("// ENTER DIR DISTANCE");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER NO OF ELEMENT ROWS");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->ElSweepB(cDBase->OTemp, ptVec.x, (int)ptNo.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOPY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS");
			iStat = 1;
		}if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// ENTER NO");
			SetFocus();
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			ptVec = cDBase->DB_PopBuff();
			cDBase->Copy(cDBase->OTemp, ptVec, (int)ptNo.x);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOPYTO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO COPY");
			iStat = 1;
		}if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK POINT TO COPY FROM:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			vF = cDBase->DB_PopBuff();
			vF = cDBase->GlobaltoWP(vF);
			iStat = 4;
		}
		if (iStat == 4)
		{
			outtext2("// PICK POINT TO COPY TO:");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector vT;
			vT = cDBase->DB_PopBuff();
			vT = cDBase->GlobaltoWP(vT);
			vT -= vF;
			cDBase->Copy(cDBase->OTemp, vT, (int)1);
			iStat = 4;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->S_Res();
			RetVal = 1;
		}
	}
MenuEnd:

	return RetVal;
}

int zOFFSET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if ((CInMsg == "C") || (CInMsg == "D") || (CInMsg == "")) //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{

			char OutT[80];
			sprintf_s(OutT, "%s%g)", "ENTER OFFSET DISTANCE (", gDIM_OFFSZ);
			outtext2(OutT);
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);

		}
		if (iStat == 1)
		{
			dDist = cDBase->DB_PopBuff();
			iStat = 2;
		}
		if (iStat == 2)
		{
			outtext2("// PICK OBJECT TO OFFSET");
			iStat = 3;
		}
		if (iStat == 3)
		{
			if (cDBase->S_Count == S_initCnt + 1)
			{
				pO = cDBase->S_Buff[cDBase->S_Count - 1];
				cDBase->S_Count--;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// PICK SIDE TO OFFSET");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}

		if (iStat == 5)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			double dOffDist;
			dOffDist = dDist.x;
			if (dOffDist == 0)
				dOffDist = gDIM_OFFSZ;
			else
				gDIM_OFFSZ = dOffDist;

			cDBase->OffSet(pO, ptVec, dOffDist);
			iStat = 2;
			this->DoMenu(CInMsg, Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMOVE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// TRANSLATION:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zTVEC_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->MoveObjs(cDBase->OTemp, ptVec);
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMOVETO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK OBJECTS TO MOVE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK POINT TO MOVE FROM:");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			vF = cDBase->DB_PopBuff();
			vF = cDBase->GlobaltoWP(vF);
			iStat = 4;
		}
		if (iStat == 4)
		{
			outtext2("// PICK POINT TO MOVE TO:");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector vT;
			vT = cDBase->DB_PopBuff();
			vT = cDBase->GlobaltoWP(vT);
			vT -= vF;
			cDBase->MoveObjs(cDBase->OTemp, vT);
			cDBase->S_Res();
			RetVal = 1;
			//this->DoMenu(CInMsg,Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDMOVE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	int noNodes;
	noNodes = cDBase->pCurrentMesh->GetNoNode(cDBase->iCurElemType);
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp);
			cDBase->S_Count = 0;
			outtext2("// PICK FIRST LOCATION");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			outtext2("// PICK SECOND LOCATION");
			iResumePos = 4;
			iCancelPos = 100;
			pNext = new zPT_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 4)
		{
			C3dVector ptVec1;
			C3dVector ptVec2;
			ptVec2 = cDBase->DB_PopBuff();
			ptVec1 = cDBase->DB_PopBuff();
			ptVec2 -= ptVec1;
			cDBase->Move(cDBase->OTemp, ptVec2);
			iStat = 0;
			cDBase->S_Res();
			cDBase->S_Des();
			this->DoMenu("AGAIN", Pt);
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPMODE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->WPMode();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zORTHO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->Ortho();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDBET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	int noNodes;
	noNodes = cDBase->pCurrentMesh->GetNoNode(cDBase->iCurElemType);
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK FIRST NODE SET");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			outtext2("// PICK SECOND NODE SET");
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NO");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			cDBase->BetNodes(cDBase->OTemp, cDBase->OTemp2, (int)ptNo.x);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMESHQND_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	int noNodes;
	noNodes = cDBase->pCurrentMesh->GetNoNode(cDBase->iCurElemType);
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK FIRST NODE SET");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			outtext2("// PICK SECOND NODE SET");
			iStat = 3;
		}
		if (iStat == 3)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp2);
				cDBase->S_Count = 0;
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			outtext2("// ENTER NO");
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			C3dVector ptNo;
			C3dVector ptVec;
			ptNo = cDBase->DB_PopBuff();
			cDBase->ElsBetNodes(cDBase->OTemp, cDBase->OTemp2, (int)ptNo.x - 1);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMESHINT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK TRI ELEMENTS TO INTERSECT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			cDBase->IntersectEls(cDBase->OTemp);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMESHINTWP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK TRI ELEMENTS TO INTERSECT WITH WP");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				cDBase->S_Save(cDBase->OTemp);
				cDBase->S_Count = 0;
				iStat = 2;
				CInMsg = "NULL";
			}
		}
		if (iStat == 2)
		{
			cDBase->IntersectElsWP(cDBase->OTemp);
			cDBase->S_Res();
			cDBase->S_Count = 0;
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = 0;
			cDBase->S_Count = 0;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER GROUP NAME");
			SetFocus();
			iStat = 1;
		}
		else if (iStat == 1)
		{
			iStat = 2;
			cDBase->AddGp(CInMsg);
			outtext1("Group Created and Set as Active.");
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLAB_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	if (CInMsg != "MouseInp")
	{
		CString CInMsg2;
		CInMsg2 = CInMsg;
		DoNext(&CInMsg, Pt);
		if (pNext == NULL)
		{
			if (CInMsg == "C") //Common Options
			{
				RetVal = 2;
				goto MenuEnd;
			}

			if (iStat == 0)
			{
				if (iT == -1)
				{
					outtext2("// ENTER RESULTING TYPE (Key In)");
					iResumePos = 1;
					iCancelPos = 100;
					pNext = new zKEY_Mnu();
					pNext->Init(cDBase, 1);
					DoNext(&CInMsg, Pt);
				}
				else
				{
					iStat = 2;  //Jump the nest bit
				}
			}
			if (iStat == 1)
			{
				C3dVector ptVec;
				ptVec = cDBase->DB_PopBuff();
				iT = (int)ptVec.x;
				iStat = 2;
			}

			if (iStat == 2)
			{
				outtext2("// ENTER IDS (START - FININSH) (Key In)");
				iStat = 3;
			}
			if (iStat == 3)
			{
				iResumePos = 4;
				iCancelPos = 100;
				pNext = new zKEY_Mnu();
				pNext->Init(cDBase, 1);
				DoNext(&CInMsg, Pt);
			}
			if (iStat == 4)
			{
				if ((CInMsg2 == "D") || (CInMsg2 == ""))
				{
					RetVal = 1;
				}
				else
				{
					C3dVector ptVec;
					ptVec = cDBase->DB_PopBuff();
					cDBase->LabSel(iT, (int)ptVec.x, (int)ptVec.y);
					iStat = 3;
					DoMenu(CInMsg, Pt);
				}
			}
			//Escape clause
			if (iStat == 100)
			{
				RetVal = 1;
			}
		}
	}
MenuEnd:
	return RetVal;
}

int zGPBYPID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Property ID.");
	cDBase->AddToGroupbyPID(-1);
	RetVal = 1;
	return RetVal;
}

int zCOLPID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Colouring Elements by Property.");
	cDBase->ColourByPID(-1);
	RetVal = 1;
	return RetVal;
}

int zCOLINC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Colouring Elements by Include File.");
	cDBase->ColourByINC(-1);
	RetVal = 1;
	return RetVal;
}

int zCHKJAC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Checking for Negative Volume Elements.");
	cDBase->ChkNegJac();
	RetVal = 1;
	return RetVal;
}

int zDSPGP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Displaying Current Group:-");
	cDBase->Dsp_Group();
	RetVal = 1;
	return RetVal;
}

int zDSPALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->Dsp_All();
	cDBase->ReDraw();
	RetVal = 1;
	return RetVal;
}

int zSHOWALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->Dsp_ShowAll();
	RetVal = 1;
	return RetVal;
}

int zHIDE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK ITEMS TO HIDE");
			iStat = 1;

		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->Dsp_Hide();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zDSPSEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->Dsp_All();
	cDBase->Dsp_Selected();
	RetVal = 1;
	return RetVal;
}

int zDES_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->S_Des();
	cDBase->ReDraw();
	RetVal = 1;
	return RetVal;
}

int zGPBYMID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Material ID.");
	cDBase->AddToGroupbyMID(-1);
	RetVal = 1;
	return RetVal;
}

int zSELBYPID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// ENTER PID OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelbyPID((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType = 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelbyPID(pE->PID);
						cDBase->FILTER.SetFilter(9);
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMATEDIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//Saeed_Material_SaveBugV1_05_20_2025_Start
			//Saeed// outtext2("// ENTER MID OR PICK ELEMENT");
			outtext2("// ENTER Material ID OR PICK ELEMENT");
			//Saeed_Material_SaveBugV1_05_20_2025_End
			CInMsg = "NULL";
			iStat = 1;
			SetFocus();
		}
		if (iStat == 1)
		{
			//Saeed_Material_SaveBugV1_05_20_2025_Start
			bool materialIDFound;
			//Saeed_Material_SaveBugV1_05_20_2025_End
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				//Saeed_Material_SaveBugV1_05_20_2025_Start
				//Saeed// cDBase->EditMat((int)GetPt.x, FALSE);
				cDBase->EditMat((int)GetPt.x, FALSE, materialIDFound);
				if (!materialIDFound) {
					outtextSprintf("\r\nERROR >>> Material ID %i Not found. [!!!]", (int)GetPt.x, 0.0, true, 2);
				}
				//Saeed_Material_SaveBugV1_05_20_2025_End
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						//Saeed_Material_SaveBugV1_05_20_2025_Start
						//Saeed// cDBase->EditMat(pE->PID, TRUE);
						cDBase->EditMat(pE->PID, TRUE, materialIDFound);
						//Saeed_Material_SaveBugV1_05_20_2025_End
					}
					RetVal = 1;
				}
			}

		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPREDIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// ENTER PID OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
			SetFocus();
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->EditProp((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->EditProp(pE->PID);
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zOEDIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// PICK OBJECT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					cDBase->EditObject();
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMATLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER MID OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->ListMat((int)GetPt.x, FALSE);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType = 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->ListMat(pE->PID, TRUE);
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER PID OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->ListProp((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType = 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->ListProp(pE->PID);
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMMESHTET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK TRI SHELL ELEMENTS FORMING BOUNDARY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER GROWTH RATE 0.5 to 1.0 (Def:0.55)");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			dT = atof(CInMsg);
			if (dT <= 0)
			{
				dT = 0.55;
				iStat = 4;
			}
			else
			{
				iStat = 4;
			}
		}
		if (iStat == 4)
		{
			cDBase->MeshTET(cDBase->OTemp, dT);
			cDBase->FILTER.SetAll();
			//cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHELL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			//cDBase->FILTER.SetFilter(4);
			outtext2("// PICK SOLID ELEMENTS TO SHELL COAT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			outtext2("// ENTER COLOUR FOR NEW ELEMENTS");
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ShellSolids(cDBase->OTemp, static_cast<int>(ptVec.x));
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFFACE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK SOLID ELEMENTS FOR FREE FACE DISPLAY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			iStat = 3;
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();                //clear selection buffer
			cDBase->FreeFaceDsp(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMQUADTOTRI_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK QUAD ELEMENTS TO SPLIT");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->QuadToTri(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->OTemp->Clear();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCHK2D_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK SHELL ELEMENTS FOR SECTION PROPERTIES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->SectionProps(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFEDGE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS FOR FREE EDGE DISPLAY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->FreeEdgeDsp(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zQMORPH_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS FOR FREE EDGE DISPLAY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->QMorph(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELMASS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS FOR MASS CHECK");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->ElMass(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCELM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS FOR COINCIDENT CHECK");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->CoincidentElements(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSNORM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// PICK ELEMENTS FOR NORMAL CONSISTANCY");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 3);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->S_Save(cDBase->OTemp); //Save selection
			cDBase->S_Des();       //clear selection buffer
			cDBase->ShellNormConsistancy(cDBase->OTemp);
			cDBase->FILTER.SetAll();
			cDBase->S_Res();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPRLISTALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->ListAllProps();
	RetVal = 2;
	return RetVal;
}

int zSOLLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->ListSolutions();
	RetVal = 2;
	return RetVal;
}

int zSOLCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			outtext2("// ENTER SOLUTION TITLE");
			SetFocus();
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sT = CInMsg;
			outtext2("// ENTER SOLUTION TYPE");
			outtext2("// 0 LINEAR STATIC;");
			outtext2("// 1 STEADY STATE THERMAL (N/A);");
			outtext2("// 2 Sparse;");
			SetFocus();
			iStat = 2;
			goto MenuEnd;
		}
		if (iStat == 2)
		{
			iSol = atoi(CInMsg);
			if ((iSol == 0) || (iSol == 1) || (iSol == 2))
			{
				iStat = 3;
			}
			else
			{
				iStat = 1;
				outtext1("ERROR: Invalid Solution Type.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 3)
		{
			outtext2("// ENTER CONVERGENCE TOLERANCE");
			SetFocus();
			iStat = 4;
			goto MenuEnd;
		}
		if (iStat == 4)
		{
			dT = atof(CInMsg);
			if (dT < 0.1)
			{
				iStat = 5;
			}
			else
			{
				iStat = 3;
				outtext1("ERROR: Tolerance Must be < 0.1.");
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 5)
		{
			RetVal = 1;
			cDBase->AddSolutions(sT, iSol, dT);
			outtext1("Solution Added and Set as Active.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSTEPCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		C3dVector ptVec;
		if (iStat == 0)
		{
			if (cDBase->isActiveSolSet())
			{
				iStat = 1;
			}
			else
			{
				outtext1("ERROR: No Active Solution.");
				RetVal = 2;
				goto MenuEnd;
			}
		}
		if (iStat == 1)
		{
			outtext2("// ENTER STEP TITLE");
			SetFocus();
			iStat = 2;
			goto MenuEnd;
		}
		if (iStat == 2)
		{
			sT = CInMsg;
			outtext2("// ENTER LOAD SET ID");
			SetFocus();
			iStat = 3;
			goto MenuEnd;
		}
		if (iStat == 3)
		{
			iLC = atoi(CInMsg);
			if (cDBase->isValidLCid(iLC))
			{
				iStat = 4;
			}
			else
			{
				iStat = 2;
				outtext1("ERROR: Invalid Load Set ID.");
				DoMenu(CInMsg, Pt);
			}
		}


		if (iStat == 4)
		{
			outtext2("// ENTER BOUNDARY SET ID");
			SetFocus();
			iStat = 5;
			goto MenuEnd;
		}
		if (iStat == 5)
		{
			iBC = atoi(CInMsg);
			if (cDBase->isValidBCid(iBC))
			{
				iStat = 6;
			}
			else
			{
				iStat = 4;
				outtext1("ERROR: Invalid Boundary Set ID.");
				DoMenu(CInMsg, Pt);
			}
		}


		if (iStat == 6)
		{
			outtext2("// ENTER TEMP SET ID or ENTRE FOR N/A");
			SetFocus();
			iStat = 7;
			goto MenuEnd;
		}
		if (iStat == 7)
		{
			iTC = atoi(CInMsg);
			if (iTC == 0)
			{
				iTC = -1;
				iStat = 8;
			}
			else if (cDBase->isValidTCid(iTC))
			{
				iStat = 8;
			}
			else
			{
				iStat = 6;
				outtext1("ERROR: Invalid Temperatre Set ID.");
				DoMenu(CInMsg, Pt);
			}
		}

		if (iStat == 8)
		{
			outtext2("// ENTER RESTART 1 for YES else NO.");
			SetFocus();
			iStat = 9;
			goto MenuEnd;
		}
		if (iStat == 9)
		{
			iStat = 10;
			int iT = atoi(CInMsg);
			if (iT == 1)
			{
				bRS = TRUE;
			}
			else
			{
				bRS = FALSE;
			}
		}
		if (iStat == 10)
		{
			RetVal = 1;
			cDBase->AddStep(sT, iLC, iBC, iTC, bRS);
			outtext1("Step Added to Active Solution.");
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			cDBase->FILTER.SetAll();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMATLISTALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->ListAllMats();
	RetVal = 2;
	return RetVal;
}

int zRELTO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	CString CInMsg2 = CInMsg;
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg2 == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			if (iT == -1)
			{
				outtext2("// ENTER RESULTANT TYPE");
				SetFocus();
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zKEY_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			if (iT == -1)
			{
				C3dVector ptVec;
				ptVec = cDBase->DB_PopBuff();
				iT = (int)ptVec.x;
			}
			iStat = 3;
		}
		if (iStat == 3)
		{
			char S1[80];
			sprintf_s(S1, "%s %i", "//PICK ITEMS RELATED TO TYPE ", iT);
			outtext2(S1);
			iStat = 4;
		}
		if (iStat == 4)
		{
			iResumePos = 5;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 5)
		{
			if ((CInMsg2 == "D") || (CInMsg2 == ""))
			{
				iStat = 6;
			}
		}

		if (iStat == 6)
		{
			cDBase->RelatedTo(iT);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELAT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODE");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			outtext2("// ENTER MAX ELEMENTS AT");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->NoOfElementOnANode((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zCOLINE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODES");
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, 1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			cDBase->CreateCoordLine();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELNODESBYCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// ENTER COLOUR OR PICK NODE");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelNodesbyCOL((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 1)
					{
						Node* pE = (Node*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelNodesbyCOL(pE->iColour);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESDISPOFF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(1);
			outtext2("// PICK NODE FOR RELATIVE OFFSET");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				pN = NULL;
				cDBase->SetResDispOff(pN);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 1)
					{
						pN = (Node*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SetResDispOff(pN);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELSURFCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(15);
			outtext2("// ENTER COLOUR OR PICK SURFACE");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelSurfsbyCOL((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 15)
					{
						G_Object* pE = (G_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelSurfsbyCOL(pE->iColour);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELPTSCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			outtext2("// ENTER COLOUR OR PICK POINT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelPtsbyCOL((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 0)
					{
						Node* pE = (Node*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelPtsbyCOL(pE->iColour);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELCURCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(7);
			outtext2("// ENTER COLOUR OR PICK CURVE");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelCursbyCOL((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7)
					{
						Node* pE = (Node*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelCursbyCOL(pE->iColour);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELCURLAY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Save();
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(0);
			cDBase->FILTER.SetFilter(6);
			cDBase->FILTER.SetFilter(7);
			cDBase->FILTER.SetFilter(10);
			outtext2("// ENTER LAYER OR PICK CURVE/POINT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelCursbyLAY((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if ((cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 0) ||
						(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 6) ||
						(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 7) ||
						(cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 10))
					{
						Node* pE = (Node*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelCursbyLAY(pE->iFile);
						cDBase->FILTER.Restore();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			cDBase->FILTER.Restore();
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELBYCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// ENTER COLOUR OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelbyCOL((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelbyCOL(pE->iColour);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELBYTYPE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->FILTER.Clear();
			cDBase->FILTER.SetFilter(3);
			outtext2("// ENTER TYPE OR PICK ELEMENT");
			CInMsg = "NULL";
			iStat = 1;
		}
		if (iStat == 1)
		{
			if ((CInMsg != "MouseInp") && (CInMsg != "D") && (CInMsg != "NULL"))
			{
				C3dVector GetPt;
				int iPt = ExtractPt(CInMsg, &GetPt);
				cDBase->SelbyTYPE((int)GetPt.x);
				RetVal = 1;
			}
			else if (CInMsg == "MouseInp")
			{
				if (cDBase->S_Count == S_initCnt + 1)
				{
					if (cDBase->S_Buff[cDBase->S_Count - 1]->iObjType == 3)
					{
						E_Object* pE = (E_Object*)cDBase->S_Buff[cDBase->S_Count - 1];
						cDBase->SelbyTYPE(pE->iType);
						cDBase->FILTER.SetAll();
					}
					RetVal = 1;
				}
			}
		}

		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			if (iT == -1)
			{
				outtext2("// ENTER SELECTION TYPE");
				SetFocus();
				iResumePos = 2;
				iCancelPos = 100;
				pNext = new zKEY_Mnu();
				pNext->Init(cDBase, -1);
				DoNext(&CInMsg, Pt);
			}
			else
			{
				iStat = 2;
			}
		}
		if (iStat == 2)
		{
			if (iT == -1)
			{
				C3dVector ptVec;
				ptVec = cDBase->DB_PopBuff();
				iT = (int)ptVec.x;
			}
			iStat = 3;
		}
		if (iStat == 3)
		{
			cDBase->S_All(iT);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSELINV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->S_Invert();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPBYCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Element Colour.");
	cDBase->AddToGroupbyCol(-1);
	RetVal = 1;
	return RetVal;
}

int zGPNDBYCOL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Node Colour.");
	cDBase->AddToGroupbyNDCol(-1);
	RetVal = 1;
	return RetVal;
}

int zGPNDBYOSYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Node Output System.");
	cDBase->AddToGroupbyNDOSYS(-1);
	RetVal = 1;
	return RetVal;
}

int zGPNDBYDSYS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Node Definition System.");
	cDBase->AddToGroupbyNDDSYS(-1);
	RetVal = 1;
	return RetVal;
}

int zGPBYTYPE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Creating Groups by Element Type.");
	cDBase->AddToGroupbyType(-1);
	RetVal = 1;
	return RetVal;
}

int zSELBYMID_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER MID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SelbyMID((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPSET_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER GROUP");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Group to:-");
			cDBase->SetCurrentGP((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER GROUP");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->Del_Group((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLSETDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER LOAD SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->DeleteLC((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBSETDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER BOUNDARY SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->DeleteBC((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTSETDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER TEMPERATURE SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->DeleteTSET((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zDELAY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER DELAY IN SEC");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->DELAY((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zHLIMIT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER HIGHLIGHT LIMIT (-1 for ALL)");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->HLimit((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zECHO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER STRING TO ECHO");
			SetFocus();
			iStat = 1;
			iCancelPos = 100;
		}
		if (iStat == 1)
		{
			iStat = 2;
		}
		else if (iStat == 2)
		{
			outtext1(CInMsg);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESDELAY_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER DELAY IN MILSEC");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResDelay((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESLSTRESP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// NODE/ELEM ID FOR RESPONSE DATA");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResListRespData((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESGRAPHRESP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			cDBase->ResGraphRespData(0);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESLABRESP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->LabelRespItems();
	RetVal = 2;
	return RetVal;
}

int zRESLSTRESPFULL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// NODE/ELEM ID FOR RESPONSE DATA");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResListRespDataFull((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESFRAMES_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER NO OF FRAMES (1-20)");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResFrames((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESVEC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESULTS SET ID, VEC ID, DOF");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetCurrentResVec((int)ptVec.x, (int)ptVec.y, (int)ptVec.z);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESVECDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext1("Deleting Results Vector.");
			cDBase->DeleteResVec();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESSEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESULTS SET ID, VAR ID, OPT ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetCurrentResSet((int)ptVec.x, (int)ptVec.y, (int)ptVec.z);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESENVMAX_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESSETS TO ENV MAX (SETID,VAR,OPT)");
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;
			}
			else
			{
				sSeq[iNo] = CInMsg;
				iNo++;
				iStat = 0;
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			cDBase->ResSetEnvMax(sSeq, iNo);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESSCALE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESSETS TO SCALE (SETID,VAR,OPT)");
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sSeq = CInMsg;
			outtext2("// ENTER RESULTS SET SCALE FACTOR");
			SetFocus();
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResSetScale(sSeq, ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESDIVINTO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESSETS TO DIVIDE BY (SETID,VAR,OPT)");
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			sSeq = CInMsg;
			outtext2("// ENTER VALUE TO DIVIDE INTO");
			SetFocus();
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ResSetDivInTo(sSeq, ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESENVMIN_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESSETS TO ENV MIN (SETID,VAR,OPT)");
			iStat = 1;
			goto MenuEnd;
		}
		if (iStat == 1)
		{
			if (CInMsg == "D")
			{
				iStat = 2;
			}
			else
			{
				sSeq[iNo] = CInMsg;
				iNo++;
				iStat = 0;
				DoMenu(CInMsg, Pt);
			}
		}
		if (iStat == 2)
		{
			cDBase->ResSetEnvMin(sSeq, iNo);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESSETDEFSCL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER DEFORMATION SCALE FACTOR");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetDefScale((double)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESSETVECSCL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER VECTOR SCALE FACTOR");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetVecScale((double)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zRESSELDEF_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER RESULTS SET ID, VAR ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->SetCurrentResSetDef((int)ptVec.x, (int)ptVec.y);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->MeshListALl();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER FEM MESH NAME");
			SetFocus();
			iStat = 1;
		}
		else if (iStat == 1)
		{
			iStat = 2;
			cDBase->CreateNewMesh(CInMsg);
			outtext1("Mesh Created and Set as Active.");
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER MESH ID TO ACTIVATE");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Mesh To:-");
			cDBase->SetActiveMesh((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLABGAP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER LABEL GAP SIZE TO FIND");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->LabGaps((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLABGAPMP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER LABEL GAP SIZE TO FIND");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->LabGapsMP((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHVIS_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER MESH ID TO TOGGLE VISABILITY");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Toggling Visability for Mesh:-");
			cDBase->TogVisableMesh((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMSHDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER MESH ID DELETE");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Deleting Mesh:-");
			cDBase->DeleteMesh((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLSETLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->ListLC();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLSETACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Set To:-");
			cDBase->SetCurLC((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSTEPACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER STEP ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Step To:-");
			cDBase->SetActStep((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSOLACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SOLUTION ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Solution To:-");
			cDBase->SetActSol((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBSETACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Set To:-");
			cDBase->SetCurBC((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBSETLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->ListBC();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTSETLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			cDBase->ListTSET();
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTSETACT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			outtext1("Setting Active Set To:-");
			cDBase->SetCurTSET((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLSETCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// ENTER LOAD SET NAME:-");
			SetFocus();
			iStat = 2;
		}
		else if (iStat == 2)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->CreateLC((int)ptVec.x, CInMsg);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBSETCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// ENTER BOUNDARY SET NAME:-");
			SetFocus();
			iStat = 2;
		}
		else if (iStat == 2)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->CreateBC((int)ptVec.x, CInMsg);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTSETCR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER SET ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			outtext2("// ENTER TEMPERATUE SET NAME:-");
			SetFocus();
			iStat = 2;
		}
		else if (iStat == 2)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->CreateTSET((int)ptVec.x, CInMsg);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zSETFIL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			cDBase->FILTER.SetAll();
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER TYPE");
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->FILTER.SetFilter((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPREMGP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER GROUP ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			cDBase->GPRemGP((int)ptNo.x);
			outtext1("Group Subtrated from Active Group.");
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPADDGP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER GROUP ID");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			cDBase->GPAddGP((int)ptNo.x);
			outtext1("Group Added to Active Group.");
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zQANGSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER ANGULAR INCREMENT (DEGS)");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			cDBase->gdASize = ptNo.x;
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zQSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER INCREMENT (MM)");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			cDBase->gdSize = ptNo.x / 1000;
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zPTSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER POINT SIZE (Def 12))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 12;
			gPT_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zEDSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER ELEMENT FREE EDGE SIZE (Def 5))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 5;
			gED_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zFCSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER ELEMENT FREE FACE SIZE (Def 2))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 2;
			gFC_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zNDSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER NODE SIZE (Def 10))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 10;
			gND_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zTXTSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER TEXT SIZE (Def 2))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 2;
			gTXT_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zBMSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER BEAM SECTION SIZE (Def 2))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 2;
			gBM_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zWPLSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER WORKPLANE LINE SIZE (Def 12))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 12;
			gWP_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zELSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER ELEMENT EDGE SIZE (Def 2))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 2;
			gEL_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zLMSIZE_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}
		if (iStat == 0)
		{
			outtext2("// ENTER LUMP MASS SIZE (Def 20))");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 1)
		{
			iStat = 2;
			C3dVector ptNo = cDBase->DB_PopBuff();
			if (ptNo.x < 1)
				ptNo.x = 20;
			gLM_SIZE = ptNo.x;
			cDBase->InvalidateOGL();
			cDBase->ReGen();
			RetVal = 1;
		}
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->ListGp();
	RetVal = 2;
	return RetVal;
}

int zGPNEXT_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->NextGp();
	RetVal = 2;
	return RetVal;
}

int zGPPREV_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->PrevGp();
	RetVal = 2;
	return RetVal;
}

int zRESSETLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->ListResSets();
	RetVal = 2;
	return RetVal;
}

int zRESVECLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->ListVecSets();
	RetVal = 2;
	return RetVal;
}

int zRESDEL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->DelResSets();
	outtext1("All Results Deleted.");
	RetVal = 2;
	return RetVal;
}

int zRESREVCOLBAR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{

	cDBase->RevColourBar();
	RetVal = 2;
	return RetVal;
}

int zRESSETFULLLIST_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	cDBase->ListResSet();
	RetVal = 2;
	return RetVal;
}

int zGPDSP_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Displaying Current Group.");
	cDBase->Dsp_Group();
	RetVal = 2;
	return RetVal;
}

int zFILALL_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Filter Set to All.");
	cDBase->FILTER.SetAll();
	RetVal = 2;
	return RetVal;
}

int zFILCLR_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Filter Cleared.");
	cDBase->FILTER.Clear();
	RetVal = 2;
	return RetVal;
}

int zGPADD_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Selected Items Added to Group.");
	cDBase->AddToGroup();
	RetVal = 1;
	return RetVal;
}

int zGPREM_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	outtext1("Selected Items Removed from Group.");
	cDBase->RemFromGroup();
	RetVal = 1;
	return RetVal;
}

int zEXPINC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER FILE NO or -1 for all");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ExporttoNAS((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zGPBYINC_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// ENTER FILE NO or -1 for all");
			SetFocus();
			iResumePos = 1;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		else if (iStat == 1)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->GPByInclude((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMODINCNO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK ITEMS");
			iStat = 1;

		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER FILE NO");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ModIncludeNo((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}

int zMODLAYNO_Mnu::DoMenu(CString CInMsg, CPoint Pt)
{
	DoNext(&CInMsg, Pt);
	if (pNext == NULL)
	{
		if (CInMsg == "C") //Common Options
		{
			RetVal = 2;
			goto MenuEnd;
		}

		if (iStat == 0)
		{
			outtext2("// PICK CURVES / POINTS / DIMS TO SET LAYER");
			iStat = 1;

		}
		if (iStat == 1)
		{
			if ((CInMsg == "D") || (CInMsg == ""))
			{
				iStat = 2;
			}
			iResumePos = 2;
			iCancelPos = 100;
			pNext = new zSEL_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 2)
		{
			outtext2("// ENTER LAYER NO");
			SetFocus();
			iResumePos = 3;
			iCancelPos = 100;
			pNext = new zKEY_Mnu();
			pNext->Init(cDBase, -1);
			DoNext(&CInMsg, Pt);
		}
		if (iStat == 3)
		{
			C3dVector ptVec;
			ptVec = cDBase->DB_PopBuff();
			cDBase->ModLayerNo((int)ptVec.x);
			RetVal = 1;
		}
		//Escape clause
		if (iStat == 100)
		{
			cDBase->DB_BuffCount = initCnt;
			cDBase->S_Count = S_initCnt;
			RetVal = 1;
		}
	}
MenuEnd:
	return RetVal;
}