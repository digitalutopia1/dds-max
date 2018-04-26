//-----------------------------------------------------------------------------
// ----------------
// File ....: dds.h
// ----------------
// Author...: Digital_Utopia
// Date ....: December 2016
// Descr....: DDS File I/O Module
//
// History .: December 5, 2016 - Started
//            
//
//
//-----------------------------------------------------------------------------
        
#ifndef _DDSCLASS_
#define _DDSCLASS_
#include "ATI_Compress_Test_Helpers.h"
#define DLLEXPORT __declspec(dllexport)

#define DDSCONFIGNAME _T("dds.cfg")

//-----------------------------------------------------------------------------
//-- Class Definition ---------------------------------------------------------
//


typedef struct {
	int		outDepth;		// Output depth
	bool	saved;
}DDSParams;

class BitmapIO_DDS : public BitmapIO {
    
     private:
     
        BITMAPFILEHEADER	hdr;
        BITMAPINFOHEADER	bmi;
		DDSD2 ddsd;
		ATI_TC_Texture texture;
        void           GetCfgFilename     ( TCHAR *filename );

     public:
     
		DDSParams		mParams;
        BOOL			ReadCfg				( );
        void			WriteCfg			( );

        //-- Constructors/Destructors
        
                       BitmapIO_DDS       ( );
                      ~BitmapIO_DDS       ( );
               
        //-- Number of extemsions supported
        
        int            ExtCount           ( )       { return 1;}
        
        //-- Extension #n (i.e. "3DS")
        
        const TCHAR   *Ext                ( int n ) {return _T("dds");}
        
        //-- Descriptions
        
        const TCHAR   *LongDesc           ( );
        const TCHAR   *ShortDesc          ( );

        //-- Miscelaneous Messages
        
        const TCHAR   *AuthorName         ( )       { return _T("Sean D Klapperich");}
        const TCHAR   *CopyrightMessage   ( )       { return _T("Copyright 2016, Digital Utopia");}
        const TCHAR   *OtherMessage1      ( )       { return _T("");}
        const TCHAR   *OtherMessage2      ( )       { return _T("");}
        
        unsigned int   Version            ( )       { return (110);}

        //-- Driver capabilities
        
        int            Capability         ( )       { return BMMIO_READER    | 
                                                                 
                                                             BMMIO_EXTENSION 
															 ;}
        
        //-- Driver Configuration
        
        BOOL           LoadConfigure      ( void *ptr, DWORD piDataSize );
        BOOL           SaveConfigure      ( void *ptr );
        DWORD          EvaluateConfigure  ( ) { return sizeof(DDSParams); }
        
        //-- Show DLL's "About..." box
        
        void           ShowAbout          ( HWND hWnd );  

		//-- Show Image's control Dlg Box
		BOOL           ShowControl      ( HWND hWnd, DWORD flag );

        //-- Return info about image
        
        BMMRES         GetImageInfo       ( BitmapInfo *fbi );        

        //-- Image Input
        
        BitmapStorage *Load               ( BitmapInfo *fbi, Bitmap *map, BMMRES *status);

        //-- Image Output
        
        BMMRES         OpenOutput         ( BitmapInfo *fbi, Bitmap *map);
        BMMRES         Write              ( int frame );
        int            Close              ( int flag );
        
        //-- This handler's specialized functions
        
        int            ReadBimpHeader     ( FILE *stream );
		int            ReadDDSHeader	(FILE *stream);

		//-- Dialog Proc for the Image control Dlg box

		INT_PTR ConfigCtrlDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) ;

};

#endif

//-- EOF: bmp.h ---------------------------------------------------------------
