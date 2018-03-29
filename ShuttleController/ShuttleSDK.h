//
// Contour Shuttle Devices Software Development Kit
// Native Support Interface
//
// Copyright (c) 2003 Contour Design, Inc. 
// Written by Marco Laurenzano
//

#ifndef _SHUTTLESDK_INC_
#define _SHUTTLESDK_INC_

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

#ifdef SHUTTLESDK_EXPORTS
#define SHUTTLESDK_API __declspec(dllexport)
#else
#define SHUTTLESDK_API __declspec(dllimport)
#endif

// Device type identifiers
#define SHUTTLEXPRESS    1
#define SHUTTLEPRO	     2
#define SHUTTLEPRO2      3

// Device number identifiers
#define SHUTTLEPRIMARY   1
#define SHUTTLESECONDARY 2

// Result codes
#define SHUTTLESDK_OK					0
#define SHUTTLESDK_ERRPARAM				1
#define SHUTTLESDK_ERRDRVNOTFOUND		2
#define	SHUTTLESDK_ERRALREADYREGISTERED	3
#define SHUTTLESDK_ERRREGNOTFOUND		4
#define	SHUTTLESDK_ERRUNKNOWN			5

// Shuttle Device Events
// Jog dial (inner wheel) events
#define SHUTTLEEVENTJOG			0
#define SHUTTLEEVENTJOGFIRST	0
#define	SHUTTLEEVENTJOGLEFT		0	
#define	SHUTTLEEVENTJOGRIGHT	1
#define SHUTTLEEVENTJOGLAST		1


// Shuttle ring (outer wheel) zones events
#define SHUTTLEEVENTSHUTTLEFIRST	4
#define SHUTTLEEVENTSHUTTLEL8	4   
#define	SHUTTLEEVENTSHUTTLEL7	5	
#define	SHUTTLEEVENTSHUTTLEL6	6	
#define	SHUTTLEEVENTSHUTTLEL5	7	
#define	SHUTTLEEVENTSHUTTLEL4	8	
#define	SHUTTLEEVENTSHUTTLEL3	9
#define	SHUTTLEEVENTSHUTTLEL2	10
#define	SHUTTLEEVENTSHUTTLEL1	11
#define SHUTTLEEVENTSHUTTLE		12
#define	SHUTTLEEVENTSHUTTLEC0	12
#define	SHUTTLEEVENTSHUTTLER1	13
#define	SHUTTLEEVENTSHUTTLER2	14
#define	SHUTTLEEVENTSHUTTLER3	15
#define	SHUTTLEEVENTSHUTTLER4	16
#define	SHUTTLEEVENTSHUTTLER5	17
#define	SHUTTLEEVENTSHUTTLER6	18
#define SHUTTLEEVENTSHUTTLER7	19
#define SHUTTLEEVENTSHUTTLER8	20
#define SHUTTLEEVENTSHUTTLELAST	20

// Shuttle ring (outer wheel) transitions between zones events
#define SHUTTLEEVENTSHUTTLETRANRIGHTFIRST	24
#define SHUTTLEEVENTSHUTTLETRANL8L7		24
#define SHUTTLEEVENTSHUTTLETRANL7L6		25
#define SHUTTLEEVENTSHUTTLETRANL6L5		26
#define SHUTTLEEVENTSHUTTLETRANL5L4		27
#define SHUTTLEEVENTSHUTTLETRANL4L3		28
#define SHUTTLEEVENTSHUTTLETRANL3L2		29
#define SHUTTLEEVENTSHUTTLETRANL2L1		30
#define SHUTTLEEVENTSHUTTLETRANL1C0		31
#define SHUTTLEEVENTSHUTTLETRANC0R1		32
#define SHUTTLEEVENTSHUTTLETRANR1R2		33
#define SHUTTLEEVENTSHUTTLETRANR2R3		34
#define SHUTTLEEVENTSHUTTLETRANR3R4		35
#define SHUTTLEEVENTSHUTTLETRANR4R5		36
#define SHUTTLEEVENTSHUTTLETRANR5R6		37
#define SHUTTLEEVENTSHUTTLETRANR6R7		38
#define SHUTTLEEVENTSHUTTLETRANR7R8		39
#define SHUTTLEEVENTSHUTTLETRANRIGHTLAST	39

#define SHUTTLEEVENTSHUTTLETRANLEFTFIRST	42
#define SHUTTLEEVENTSHUTTLETRANR8R7		42
#define SHUTTLEEVENTSHUTTLETRANR7R6		43
#define SHUTTLEEVENTSHUTTLETRANR6R5		44
#define SHUTTLEEVENTSHUTTLETRANR5R4		45
#define SHUTTLEEVENTSHUTTLETRANR4R3		46
#define SHUTTLEEVENTSHUTTLETRANR3R2		47
#define SHUTTLEEVENTSHUTTLETRANR2R1		48
#define SHUTTLEEVENTSHUTTLETRANR1C0		49
#define SHUTTLEEVENTSHUTTLETRANC0L1		50
#define SHUTTLEEVENTSHUTTLETRANL1L2		51
#define SHUTTLEEVENTSHUTTLETRANL2L3		52
#define SHUTTLEEVENTSHUTTLETRANL3L4		53
#define SHUTTLEEVENTSHUTTLETRANL4L5		54
#define SHUTTLEEVENTSHUTTLETRANL5L6		55
#define SHUTTLEEVENTSHUTTLETRANL6L7		56
#define SHUTTLEEVENTSHUTTLETRANR7L8		57
#define SHUTTLEEVENTSHUTTLETRANLEFTLAST		57

// Button press events
#define SHUTTLEEVENTBUTTONFIRST			60
#define SHUTTLEEVENTBUTTON				60
#define	SHUTTLEEVENTBUTTON1				61
#define	SHUTTLEEVENTBUTTON2				62
#define	SHUTTLEEVENTBUTTON3				63
#define	SHUTTLEEVENTBUTTON4				64
#define	SHUTTLEEVENTBUTTON5				65
#define	SHUTTLEEVENTBUTTON6				66
#define	SHUTTLEEVENTBUTTON7				67
#define	SHUTTLEEVENTBUTTON8				68
#define	SHUTTLEEVENTBUTTON9				69
#define	SHUTTLEEVENTBUTTON10			70
#define	SHUTTLEEVENTBUTTON11			71
#define	SHUTTLEEVENTBUTTON12			72
#define	SHUTTLEEVENTBUTTON13			73
#define SHUTTLEEVENTBUTTON14			74
#define SHUTTLEEVENTBUTTON15			75
#define SHUTTLEEVENTBUTTONLAST			75

// Handler return values
#define SHUTTLE_REPORT_HANDLED     260275
#define SHUTTLE_REPORT_NOT_HANDLED 270476
#define SHUTTLE_HANDLING_FAILED 0

// Shuttle event structure
typedef struct
{
	unsigned char Status;		// Indicates the beginning or the end of the event.
								// For a button indicates button pressed (TRUE) of released (FALSE)
								// For a zone indicates the entering (TRUE) in that zone or the exit (FALSE)
	unsigned long Event;		// Indicates the event type.
	WORD Type;					// Indicates the device type. Possible values: SHUTTLEXPRESS, SHUTTLEPRO, SHUTTLEPRO2
	WORD DeviceNumber;			// Indicates the device number. Possibile values: SHUTTLEPRIMARY, SHUTTLESECONDARY
} SHUTTLEEVENTSTR;

typedef void (CALLBACK *SHUTTLEEVENTPROC)(DWORD event, UCHAR status, WORD type, WORD devno);

// API
SHUTTLESDK_API int WINAPI Shuttle_Register_Window(HWND win, WORD type, WORD devno);
SHUTTLESDK_API int WINAPI Shuttle_Unregister_Window(HWND win, WORD type, WORD devno);
SHUTTLESDK_API UINT WINAPI Shuttle_Notification_Msg(void);
SHUTTLESDK_API int WINAPI Shuttle_Decode_Msg(SHUTTLEEVENTSTR * str, LPARAM lp, WPARAM wp);
SHUTTLESDK_API int WINAPI Shuttle_Register_Callback(SHUTTLEEVENTPROC shuttleproc, WORD type, WORD devno);
SHUTTLESDK_API int WINAPI Shuttle_Register_Callback_Global(SHUTTLEEVENTPROC shuttleproc, WORD type, WORD devno);
SHUTTLESDK_API int WINAPI Shuttle_Unregister_Callback(WORD type, WORD devno);

#ifdef __cplusplus
}
#endif

#endif